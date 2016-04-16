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
    float m_sinePhase;
    float m_speed;
    
public:
    
    ModulatedDelayUnit(float samplerate, float frequency, OcillatorUnit::Wave waveType, int delaySize, float depth):
        OcillatorUnit(samplerate, frequency, waveType),
        DelayUnit(delaySize),
        m_samplerateMS(samplerate * 0.001f),
        m_sinePhase(0)
    {
        setDepth(depth);
        setFrequency(frequency);
    }
    
    ModulatedDelayUnit():
    OcillatorUnit(44100.0, 0.1, OcillatorUnit::SINE),
    DelayUnit(44100.0),
    m_samplerateMS(44100.0 * 0.001f),
    m_sinePhase(0)
    {
        setDepth(0.1f);
    }
    
    static float frequencyFromSpeed(float speed) {
        float max = 5.0;
        float min = 0.1;
        
        return (speed * (max - min)) + min;
    }
    
    void setDepth (float fraction) {
        float max = 0.1f;
        float min = 0.01f;
        m_depth = (fraction * (max - min)) + min;
    }
    
    float process(float delayMS) {
        double minDelay = 7.0;
        double maxDelay = 30.0;
        double start = minDelay + delayMS;
        
        double phase = OcillatorUnit::getValue();
        OcillatorUnit::tick();
        
//        if (phase < 0 || phase > 1) {
//            //debug
//            int x = 1;
//        }
        
        delayMS = m_depth * (phase * (maxDelay - minDelay)) + start;
        
//        float sinePos = sin((double_Pi * 2.0 * m_sinePhase * 0.1) / 44100.0);
//        delayMS *= sinePos;
//        m_sinePhase++;
        
        return DelayUnit::delay2(delayMS * m_samplerateMS);
    }
};

#endif  // MODULATEDDELAYUNIT_H_INCLUDED
