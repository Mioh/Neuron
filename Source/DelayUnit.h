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
	}
    
	void write(float sample){
		m_delayBuffer[m_writePos] = sample;
	}
    
    void tick() {
        m_writePos++;
        
        if (m_writePos == m_maxDelay)
            m_writePos = 0;
    }
    
    float delay(double time){
        float pos, previousSampleValue, nextSampleValue, fraction;
        
        pos = m_writePos - time;
        
        //Make shure the delay does not overshoot the buffer
        //Change to while if extreme delays are allowed
        //If statements are a little bit cheaper in terms of instructions
        if (pos < 0 ) {
            pos += m_maxDelay;
        } else if (pos >= m_maxDelay) {
            pos -= m_maxDelay;
        }
        
        //Interpolate the signal as the delay could try to access a value
        //inbetween what is stored in the buffer
        int index = (int) pos;
        fraction = pos - index;
        previousSampleValue = m_delayBuffer[index];
        
        // Get next element in the circular buffer,
        // If previous element was the last element, get the first element
        if (index != m_maxDelay-1) {
            nextSampleValue = m_delayBuffer[index + 1];
        } else {
            nextSampleValue = m_delayBuffer[0];
        }
        
        // Get interpolated value
        float interpolatedValue = ((1.0f - fraction) * previousSampleValue) +
        (fraction * nextSampleValue);
        
        return interpolatedValue;
	}
};


#endif  // DELAYUNIT_H_INCLUDED
