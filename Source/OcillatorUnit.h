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
#include <math.h>
#include "Phasor.h"


class OcillatorUnit : public Phasor {
public: enum Wave { SINE };
    
private:
    double *m_waveTable = nullptr;
    //double m_waveTable[512];
    int m_waveTableSize = 0;
    double m_doubleIndex = 0.0;
    OcillatorUnit::Wave m_type;
    
public:
    
    void fillWaveTable (double (*f) (double)) {
        for (int i = 0; i < m_waveTableSize; i++) {
            double tableFraction = ((double) i) / ((double) m_waveTableSize);
            m_waveTable[i] = f(double_Pi * tableFraction);
        }
        std::cout << "\n ocillator table filled \n";
    }
    
    void setType (OcillatorUnit::Wave type) {
        //This screws things upp as m_type is initiallized to SINE!!!
        //if (type != m_type) {
            m_type = type;
            
            switch (type) {
                case SINE:
                    fillWaveTable(&std::sin);
                    break;
                default:
                    fillWaveTable(&std::sin);
            }
        //}
    }
    
    double getValue() {
        double previousSampleValue, nextSampleValue, doubleIndex;
        double fraction = modf(m_doubleIndex, &doubleIndex);
        int index = (int) doubleIndex;
        
        previousSampleValue = m_waveTable[index];
        if (index != (m_waveTableSize -1 )) {
            nextSampleValue = m_waveTable[index + 1];
        } else {
            nextSampleValue = m_waveTable[0];
        }
        
        double interpolatedValue = (fraction * previousSampleValue) +
            ((1-fraction) * nextSampleValue);
        
        return interpolatedValue;
    }
    
    int getWaveTableSize() {
        return m_waveTableSize;
    }
    
    void tick() override {
        Phasor::tick();
        //scale the phase to fit the size of the wavetable
        m_doubleIndex = (Phasor::getPhase() * m_waveTableSize);
    }
    
    ~OcillatorUnit() {
        if (m_waveTable != nullptr) {
            delete m_waveTable;
        }
    }
    
    OcillatorUnit (float samplerate, float  frequency, Wave type, int size):
        Phasor(samplerate, frequency),
        m_waveTableSize(size)
    {
        m_waveTable = new double[m_waveTableSize];
        setType(type);
    }
    
    OcillatorUnit (float samplerate, float  frequency, Wave type):
        Phasor(samplerate, frequency),
        m_waveTableSize(512)
    {
        m_waveTable = new double[m_waveTableSize];
        setType(type);
    }
    
    OcillatorUnit(float samplerate, float  frequency):
        Phasor(samplerate, frequency),
        m_waveTableSize(512)
    {
        m_waveTable = new double[m_waveTableSize];
        setType(SINE);
    }
};

#endif /* defined(__APDelay__OcillatorUnit__) */
