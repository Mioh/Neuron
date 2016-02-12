//
//  Phasor.h
//  APDelay
//
//  Created by asmprog on 15/10/2015.
//  Copyright (c) 2015 asmprog. All rights reserved.
//
//  Modified by Mikael Olsson on 11/02/16.
//
//

#ifndef APDelay_Phasor_h
#define APDelay_Phasor_h

class Phasor  {
    
    float m_phase;
    float m_samplerate;
    float m_frequency;
    float m_inc;
    
public:
    
    Phasor();
    Phasor(float samplerate, float frequency =1   ){
        m_samplerate = samplerate;
        m_frequency = frequency;
        calc_inc();
    }
    
    void tick(){
        m_phase += m_inc;
        while(m_phase > 1){
            m_phase -=1.0;
        }
    }
    
    void calc_inc(){
        m_inc = m_frequency/m_samplerate;
    }
    
    float get_frequency(){
        return  m_frequency;
    }
    
    float get_phase(){
        return  m_phase;
    }
    
    void set_frequency(float frequency){
        m_frequency = frequency;
        calc_inc();
    }
};


#endif
