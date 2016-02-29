/*
  ==============================================================================

    Phasor.h
    Created by asmprog on 15/10/2015.
    Copyright (c) 2015 asmprog. All rights reserved.
 
    Modified: 18 Feb 2016 4:18:02pm by Mikael Olsson

  ==============================================================================
*/

#include <iostream>

class Phasor {
    
    float m_phase;
    float m_samplerate;
    float m_frequency;
    float m_inc;
public:
    
    Phasor();
    Phasor(float samplerate, float frequency =1) {
        m_samplerate = samplerate;
        m_frequency = frequency;
        calc_inc();
    }
    
    float getFrequency() {
        return  m_frequency;
    }
    
    float getPhase() {
        return  m_phase;
    }
    
    virtual void tick() {
        m_phase += m_inc;
        while(m_phase > 1) {
            m_phase -=1.0;
        }
    }
    
    void calc_inc() {
        m_inc = m_frequency/m_samplerate;
    }
    
    void setFrequency(float frequency) {
        m_frequency = frequency;
        calc_inc();
    }
    
    void setSamplerate(float samplerate) {
        m_samplerate = samplerate;
        calc_inc();
    }
    
};
