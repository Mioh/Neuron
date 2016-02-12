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

class OcillatorUnit : Phasor {
private:
    int m_frequency, m_type;
    float *m_waveTable;
    int m_waveTableSize;
    typedef Phasor super;
    
public:
    enum Wave { SINE };
    
    OcillatorUnit (int  frequency, int type, int size):
        m_frequency(frequency),
        m_type(type),
        m_waveTableSize(size)
    {
        
    }
    OcillatorUnit (int  frequency, int type):
        m_frequency(frequency),
        m_type(type),
        m_waveTableSize(512)
    {
        
    }
    OcillatorUnit():
        m_frequency(0),
        m_type(SINE),
        m_waveTableSize(512)
    {
        
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
    
    void fillWaveTable (float (*f) (float) {
        for (int i = 0; i < m_waveTableSize; i++) {
            m_waveTable[i] = f(double_Pi * (i/m_waveTableSize));
        }
    }
};

#endif /* defined(__APDelay__OcillatorUnit__) */
