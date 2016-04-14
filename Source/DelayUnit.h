/*
  ==============================================================================

    DelayUnit.h
    Created: 19 Oct 2015 4:59:09pm
    Author:  SPearse
    
    Modified by Mikael Olsson on 22/01/16.

  ==============================================================================
*/

#ifndef DELAYUNIT_H_INCLUDED
#define DELAYUNIT_H_INCLUDED


class DelayUnit{
	float* m_delayBuffer;
	int m_maxDelay;
	int m_writePos;
	
public:
	DelayUnit(int delaysize):
	m_maxDelay(delaysize),
	m_writePos(0)
	{
		
		m_delayBuffer = new float[m_maxDelay];
		clear();
	}
    DelayUnit() :
    m_maxDelay(44100),
    m_writePos(0)
    {
        m_delayBuffer = new float[m_maxDelay];
        clear();
    };
	
	~DelayUnit(){
		delete[] m_delayBuffer;
	}
	
	void clear(){
		for(int n = 0; n < m_maxDelay; ++n){
			m_delayBuffer[n] = 0.0f;
		}
	}
	
	void sum(float sample){
		
		m_delayBuffer[m_writePos] += sample;
		
		++m_writePos;
		
		while(m_writePos > m_maxDelay){
			m_writePos -= m_maxDelay;
		}
	
	}
    
	void write(float sample){
		
		m_delayBuffer[m_writePos] = sample;
		
		++m_writePos;
		
		while(m_writePos > m_maxDelay){
			m_writePos -= m_maxDelay;
		}
	}
	
	float delay(int time){
		
		int pos = m_writePos - time;
		
		while (pos < 0 ) {
			pos += m_maxDelay;
		}
		
		while (pos > m_maxDelay) {
			pos -= m_maxDelay;
		}
        
        return m_delayBuffer[pos];
        
    }
    
    float delay2(double time){
        
        double pos = m_writePos - time;
        
        while (pos < 0 ) {
            pos += m_maxDelay;
        }
        
        while (pos > m_maxDelay) {
            pos -= m_maxDelay;
        }
        
        double previousSampleValue, nextSampleValue, doubleIndex;
        double fraction = modf(pos, &doubleIndex);
        int index = (int) doubleIndex;
        
        previousSampleValue = m_delayBuffer[index];
        
        if (index != (m_maxDelay-1)) {
            nextSampleValue = m_delayBuffer[index+1];
        } else {
            nextSampleValue = m_delayBuffer[0];
        }
        
        double interpolatedValue = (fraction * previousSampleValue) +
        ((1-fraction) * nextSampleValue);
        
        return interpolatedValue;
	}
};


#endif  // DELAYUNIT_H_INCLUDED
