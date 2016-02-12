/*
  ==============================================================================

    CustomLook.h
    Created: 19 Nov 2015 5:54:44pm
    Author:  asmprog

  ==============================================================================
*/

#ifndef CUSTOMLOOK_H_INCLUDED
#define CUSTOMLOOK_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class CustomLook : public LookAndFeel_V3{
    
public:
    void 	drawLinearSlider (Graphics & g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider & slider){
        
        g.setColour(Colours::lightgrey);
        
        int thirdH = height * 0.33;
        
        
        g.fillRoundedRectangle(x,thirdH,width   ,thirdH,2);
        
        g.setColour(Colour(125,125,125));
        g.fillRoundedRectangle(x + 2,thirdH +2 ,width - 4   ,thirdH -4,2);
        
        
        g.setColour(Colours::whitesmoke);
        
        
        
        
        g.fillRect((int)sliderPos, thirdH +2 , 2, thirdH -4);
        
        
        
        
    }
    
    
};



#endif  // CUSTOMLOOK_H_INCLUDED
