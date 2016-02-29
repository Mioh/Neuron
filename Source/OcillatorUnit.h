//
//  OcillatorUnit.h
//  APDelay
//
//  Created by Mikael Olsson on 22/01/16.
//
//

#ifndef __APDelay__OcillatorUnit__
#define __APDelay__OcillatorUnit__

#include <stdio.h>
#include "Phasor.h"

class OcillatorUnit : public Phasor {
public: enum Wave { SINE };
    
private:
    float *m_waveTable;
    int m_waveTableSize;
    int m_index = 0;
    OcillatorUnit::Wave m_type = SINE;
    
public:
    
    void fillWaveTable (float (*f) (float)) {
        for (int i = 0; i < m_waveTableSize; i++) {
            m_waveTable[i] = f(double_Pi * (i/m_waveTableSize));
        }
    }
    
    void setType (OcillatorUnit::Wave type) {
        if (type != m_type) {
            m_type = type;
            
            switch (type) {
                case SINE:
                    fillWaveTable(&std::sin);
                default:
                    break;
            }
        }
    }
    
    float getValue() {
        return m_waveTable[m_index];
    }
    
    
    void tick() override {
        Phasor::tick();
        m_index = (int) (Phasor::getPhase() * m_waveTableSize);
    }
    
    OcillatorUnit (float samplerate, int  frequency, Wave type, int size):
        Phasor(samplerate, frequency),
        m_waveTableSize(size)
    {
        setType(type);
    }
    
    OcillatorUnit (float samplerate, int  frequency, Wave type):
        Phasor(samplerate, frequency),
        m_waveTableSize(512)
    {
        setType(type);
    }
    
    OcillatorUnit(float samplerate, int  frequency):
        Phasor(samplerate, frequency),
        m_waveTableSize(512)
    {
        setType(SINE);
    }
};

#endif /* defined(__APDelay__OcillatorUnit__) */
