//
//  OscillatorUnit.h
//  APDelay
//
//  Created by Mikael Olsson on 22/01/16.
//
//

#ifndef __APDelay__OscillatorUnit__
#define __APDelay__OscillatorUnit__

#include <stdio.h>
#include <math.h>
#include "Phasor.h"


class OscillatorUnit : public Phasor {
public: enum Wave { SINE };
    
private:
    double *m_waveTable = nullptr;
    int m_waveTableSize = 0;
    double m_doubleIndex = 0.0;
    OscillatorUnit::Wave m_type;
    
public:
    
    //PRE: f has a cicle of 2*pi
    void fillWaveTable (double (*f) (double)) {
        for (int i = 0; i < m_waveTableSize; i++) {
            // Scale such that descrete values match wave table indecies
            double tableFraction = ((double) i) / ((double) (m_waveTableSize-1));
            m_waveTable[i] = f(2.0 * double_Pi * tableFraction);
        }
    }
    
    //TODO: Add support for more waveforms and make a select button
    void setType (OscillatorUnit::Wave type) {
        m_type = type;
            
        switch (type) {
            case SINE:
                fillWaveTable(&sin);
                break;
            default:
                fillWaveTable(&sin);
        }
    }
    
    double getValue() {
        double previousSampleValue, nextSampleValue, fraction;
        
        // Interpolate the wave as one could try to access a value inbetween
        // what is stored in the wavetable as soundwaves are continious
        // while values handled are discrete.
        int index = (int) m_doubleIndex;
        fraction = m_doubleIndex - index;
        previousSampleValue = m_waveTable[index];
        
        // Get next element in the circular buffer,
        // If previous element was the last element, get the first element
        if (index != m_waveTableSize-1) {
            nextSampleValue = m_waveTable[index + 1];
        } else {
            nextSampleValue = m_waveTable[0];
        }
        
        // Get interpolated value
        double interpolatedValue = ((1.0f - fraction) * previousSampleValue) +
        (fraction * nextSampleValue);
        
        return interpolatedValue;
    }
    
    int getWaveTableSize() {
        return m_waveTableSize;
    }
    
    void tick() override {
        Phasor::tick();
        //scale the phase to fit the size of the wavetable
        m_doubleIndex = (Phasor::getPhase() * (m_waveTableSize - 1));
    }
    
    ~OscillatorUnit() {
        if (m_waveTable != nullptr) {
            delete m_waveTable;
        }
    }
    
    OscillatorUnit (float samplerate, float  frequency, Wave type, int size):
        Phasor(samplerate, frequency),
        m_waveTableSize(size)
    {
        m_waveTable = new double[m_waveTableSize];
        setType(type);
    }
    
    OscillatorUnit (float samplerate, float  frequency, Wave type):
        Phasor(samplerate, frequency),
        m_waveTableSize(512)
    {
        m_waveTable = new double[m_waveTableSize];
        setType(type);
    }
    
    OscillatorUnit(float samplerate, float  frequency):
        Phasor(samplerate, frequency),
        m_waveTableSize(512)
    {
        m_waveTable = new double[m_waveTableSize];
        setType(SINE);
    }
};

#endif /* defined(__APDelay__OscillatorUnit__) */
