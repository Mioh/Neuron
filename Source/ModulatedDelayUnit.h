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
    int m_waveTypeSize = 512;
    
public:
    ModulatedDelayUnit(float samplerate, float frequency, OcillatorUnit::Wave waveType, int delaySize):
        OcillatorUnit(samplerate, frequency, waveType, m_waveTypeSize),
        DelayUnit(delaySize)
    {
    }
};

#endif  // MODULATEDDELAYUNIT_H_INCLUDED
