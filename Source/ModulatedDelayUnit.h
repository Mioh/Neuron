/*
  ==============================================================================

    ModulatedDelayUnit.h
    Created: 25 Feb 2016 4:32:44pm
    Author:  Mikael Olsson

  ==============================================================================
*/

#ifndef MODULATEDDELAYUNIT_H_INCLUDED
#define MODULATEDDELAYUNIT_H_INCLUDED

#include "OcillatorUnit.h"
#include "DelayUnit.h"

class ModulatedDelayUnit : public OcillatorUnit, public DelayUnit {
private:
    float m_samplerateMS;
    float m_depth;
    float m_speed;
    
public:
    
    ModulatedDelayUnit(float samplerate, float frequency, OcillatorUnit::Wave waveType, int delaySize, float depth):
        OcillatorUnit(samplerate, frequency, waveType),
        DelayUnit(delaySize),
        m_samplerateMS(samplerate * 0.001f)
    {
        setDepth(depth);
        setFrequency(frequency);
    }
    
    ModulatedDelayUnit():
    OcillatorUnit(44100.0, 0.1, OcillatorUnit::SINE),
    DelayUnit(44100.0),
    m_samplerateMS(44100.0 * 0.001f)
    {
        setDepth(0.1f);
    }
    
    // The value 'speed' is a value between  0.0f and 1.0f representing a fraction
    // of the frequency range the unit has to offer.
    static float frequencyFromSpeed(float speed) {
        float maxFrequency = 5.0;
        float minFrequency = 0.1;
        
        return (speed * (maxFrequency - minFrequency)) + maxFrequency;
    }
    
    // The value 'depth' is a value between 0.0f and 1.0f representing a fraction
    // of the available depth the unit has to offer.
    void setDepth (float depth) {
        float max = 0.1f;
        float min = 0.01f;
        m_depth = (depth * (max - min)) + min;
    }
    
    float chorusDelay (float delayMS) {
        float minPhaseDelayMS = 7.0f;
        float maxPhaseDelayMS = 30.0f;
        
        return delay (delayMS, minPhaseDelayMS, maxPhaseDelayMS);
    }
    
    //PRE: minPhaseDelayMS < maxPhaseDelayMS
    float delay (float delayMS, float minPhaseDelayMS, float maxPhaseDelayMS) {
        float start = minPhaseDelayMS + delayMS;
        
        float phase = OcillatorUnit::getValue();
        OcillatorUnit::tick();
        
        delayMS = m_depth * (phase * (maxPhaseDelayMS - minPhaseDelayMS)) + start;
        
        return DelayUnit::delay(delayMS * m_samplerateMS);
    }
    
    void tick() {
        DelayUnit::tick();
    }
};

#endif  // MODULATEDDELAYUNIT_H_INCLUDED
