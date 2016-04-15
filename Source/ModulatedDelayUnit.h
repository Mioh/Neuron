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
    float m_sinePhase;
    
public:
    ModulatedDelayUnit(float samplerate, float frequency, OcillatorUnit::Wave waveType, int delaySize):
        OcillatorUnit(samplerate, frequency, waveType),
        DelayUnit(delaySize),
        m_samplerateMS(samplerate * 0.001f),
        m_sinePhase(0)
    {
    }
    
    ModulatedDelayUnit():
    OcillatorUnit(44100.0, 0.1, OcillatorUnit::SINE),
    DelayUnit(44100.0),
    m_samplerateMS(44100.0 * 0.001f),
    m_sinePhase(0)
    {
    }
    
    double process(double delayMS) {
//        double minDelay = 5.0;
//        double maxDelay = 30.0;
//        double start = minDelay + delayMS;
//        double depth = 0.5;
//        
//        double phase = OcillatorUnit::getValue();
//        OcillatorUnit::tick();
//        if (phase < 0 || phase > 1) {
//            int x = 1;
//        }
        
        float sinePos = sin((double_Pi * 2.0 * m_sinePhase * 0.1) / 44100.0);
        
        //delayMS = (phase * 20.0) + delayMS;
        delayMS += sinePos * 10.0 + 20.0;
        m_sinePhase++;
        //double delay = depth * (phase * (maxDelay - minDelay)) + start;
        
        return DelayUnit::delay2(delayMS * m_samplerateMS);
    }
};

#endif  // MODULATEDDELAYUNIT_H_INCLUDED
