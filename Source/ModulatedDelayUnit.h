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
    
public:
    ModulatedDelayUnit(float samplerate, float frequency, OcillatorUnit::Wave waveType, int delaySize):
        OcillatorUnit(samplerate, frequency, waveType),
        DelayUnit(delaySize)
    {
    }
    
    ModulatedDelayUnit():
    OcillatorUnit(44100, 2.0, OcillatorUnit::SINE),
    DelayUnit(44100)
    {
    }
    
    double process(double delay) {
        double phase = OcillatorUnit::getValue();
        OcillatorUnit::tick();
        //delay = phase * delay;
        
        return DelayUnit::delay(delay);
    }
};

#endif  // MODULATEDDELAYUNIT_H_INCLUDED
