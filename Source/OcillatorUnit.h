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
private:
    float *m_waveTable;
    int m_waveTableSize;
    int m_index = 0;
//    typedef Phasor super;
    
public:
    enum Wave { SINE };
    
    OcillatorUnit (float samplerate, int  frequency, int type, int size):
        Phasor(samplerate, frequency),
        m_type(type),
        m_waveTableSize(size)
    {
        setType(type);
    }
    
    OcillatorUnit (float samplerate, int  frequency, int type):
        m_phasor(samplerate, frequency),
        m_type(type),
        m_waveTableSize(512)
    {
        setType(type);
    }
    
    OcillatorUnit(float samplerate, int  frequency):
        m_phasor(samplerate, frequency),
        m_type(SINE),
        m_waveTableSize(512)
    {
        setType(SINE);
    };
    
    void setType (enum type) {
        if (type != m_type) {
            switch (type) {
                case SINE:
                    fillWaveTable(&std:sin);
                default:
                    break;
            }
        }
    }
    
    void fillWaveTable (float (*f) (float)) {
        for (int i = 0; i < m_waveTableSize; i++) {
            m_waveTable[i] = f(double_Pi * (i/m_waveTableSize));
        }
    }
    
    float getValue() {
        return m_waveTable[m_index];
    }
    
    
    void tick override() {
        Phasor::tick();
        m_index = (int) (Phasor::getPhase() * m_waveTableSize);
    }
    
};

#endif /* defined(__APDelay__OcillatorUnit__) */
