/*
  ==============================================================================

    ModulatedDelayUnit.h
    Created: 25 Feb 2016 4:32:44pm
    Author:  Mikael Olsson

  ==============================================================================
*/

#ifndef MODULATEDDELAYUNIT_H_INCLUDED
#define MODULATEDDELAYUNIT_H_INCLUDED

#include "OscillatorUnit.h"
#include "DelayUnit.h"

class ModulatedDelayUnit : public OscillatorUnit, public DelayUnit {
private:
    float m_samplerateMS;
    float m_depth;
    float m_speed;
    
public:
    
    ModulatedDelayUnit(float samplerate, float frequency, OscillatorUnit::Wave waveType, int delaySize, float depth):
        OscillatorUnit(samplerate, frequency, waveType),
        DelayUnit(delaySize),
        m_samplerateMS(samplerate * 0.001f)
    {
        setDepth(depth);
        setFrequency(frequency);
    }
    
    ModulatedDelayUnit():
    OscillatorUnit(44100.0f, 0.1f, OscillatorUnit::SINE),
    DelayUnit(44100.0f),
    m_samplerateMS(44100.0f * 0.001f)
    {
        setDepth(0.1f);
    }
    
    // PRE: 'speed' is a value between  0.0f and 1.0f.
    //It represents a fraction of the frequency range the unit has to offer.
    static float frequencyFromSpeed(float speed) {
        // Keep max and min frequency somewhat low, we just want to color the sound
        // Suggested bounds by Prinkle for modulated delays.
        // Pirkle, W. (2012). Designing Audio Effect Plug-Ins in C++. Hoboken: Taylor
        float maxFrequency = 5.0f;
        float minFrequency = 0.002f;
        
        return (speed * (maxFrequency - minFrequency)) + maxFrequency;
    }
    
    // PRE: 'depth' is a value between 0.0f and 1.0f.
    // It represents a fraction of the available depth the unit has to offer.
    void setDepth (float depth) {
        // Keep max and min depth somewhat low, we just want to color the sound
        float max = 0.1f;
        float min = 0.005f;
        m_depth = (depth * (max - min)) + min;
    }
    
    float chorusDelay (float delayMS) {
        // Typical bounds for chorus delay
        // (Pirkle, W. (2012). Designing Audio Effect Plug-Ins in C++. Hoboken: Taylor)
        float minPhaseDelayMS = 5.0f;
        float maxPhaseDelayMS = 30.0f;
        
        return delay (delayMS, minPhaseDelayMS, maxPhaseDelayMS);
    }
    
    //PRE: minPhaseDelayMS < maxPhaseDelayMS
    float delay (float delayMS, float minPhaseDelayMS, float maxPhaseDelayMS) {
        float start = minPhaseDelayMS + delayMS;
        
        // Make LFO pahse go from 0 to 1 instead of -1 to 1
        float phase = (1.0f + OscillatorUnit::getValue()) * 0.5f;
        OscillatorUnit::tick();
        
        delayMS = m_depth * (phase * (maxPhaseDelayMS - minPhaseDelayMS)) + start;
        
        return DelayUnit::delay(delayMS * m_samplerateMS);
    }
    
    void tick() {
        DelayUnit::tick();
    }
};

#endif  // MODULATEDDELAYUNIT_H_INCLUDED
