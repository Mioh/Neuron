//
//  Compressor.h
//  APDelay
//
//  Created by Mikael Olsson on 27/03/16.
//
//

#ifndef APDelay_Compressor_h
#define APDelay_Compressor_h

#include <stdio.h>
#include <math.h>
#include <algorithm>

class CompressorUnit {
    
public:
    
    CompressorUnit() {
        std::cout << "init CompressorUnit";
    }
    
    
    double calcCompressorGain(float fDetectorValue, float fThreshold,
                            float fRatio, float fKneeWidth, bool bLimit) {
        // slope variable
        float CS = 1.0 - 1.0/fRatio; // [Eq. 13.1]
        // limiting is infinite ratio thus CS->1.0
        if(bLimit)
            CS = 1;
        // soft-knee with detection value in range?
        if(fKneeWidth > 0 && fDetectorValue > (fThreshold - fKneeWidth/2.0) &&
           fDetectorValue < fThreshold + fKneeWidth/2.0) {
            // setup for Lagrange
            double x[2];
            double y[2];
            x[0] = fThreshold - fKneeWidth/2.0;
            x[1] = fThreshold + fKneeWidth/2.0;
            x[1] = std::min(0.0, x[1]); // top limit is 0dBFS y[0] = 0; // CS = 0 for 1:1 ratio y[1] = CS; // current CS
            // interpolate & overwrite CS
            CS = lagrpol(&x[0], &y[0], 2, fDetectorValue);
        }
        
        // compute gain; threshold and detection values are in dB
        float yG = CS*(fThreshold - fDetectorValue); // [Eq. 13.1]
        // clamp; this allows ratios of 1:1 to still operate
        yG = std::fmin(0.0, yG);
        // convert back to linear
        return std::pow(10.0, yG/20.0);
    }
    
    float lagrpol(double *x, double *y, float a, float detector) {
        float s=1, t=1, k=0;
        int n=2,i,j;
        
        for (i = 0; i<n; i++)
        {
            s=1;
            t=1;
            for(j=0; j<n; j++)
            {
                if(j!=i)
                {
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
            k=k+((s/t)*y[i]);
        }
    }
};


#endif
