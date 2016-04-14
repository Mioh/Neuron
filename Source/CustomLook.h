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
        
        Colour blue = Colour(33,150,243);
        //Linear
        g.setColour(blue);
        g.setOpacity(0.54f);
        
        int thirdH = height * 0.33;
        
        g.fillRoundedRectangle(x, thirdH, width, thirdH , 2);
        
        g.setColour(blue);
        g.fillRoundedRectangle(0, thirdH, (int)sliderPos, thirdH, 2);
        
        
    }
    
    void drawRotarySlider (	Graphics & 	g,
                                                 int 	x,
                                                 int 	y,
                                                 int 	width,
                                                 int 	height,
                                                 float 	sliderPosProportional,
                                                 float 	rotaryStartAngle,
                                                 float 	rotaryEndAngle,
                                                 Slider & 	slider )
    {
        
        
        Colour blue = Colour(33,150,243);
        int xPos = x + width/2 - height/2;
        
        g.setColour(blue);
        g.setOpacity(0.54f);
        g.fillEllipse(xPos,
                      y,
                      height,
                      height);
        
        g.setColour(blue);
        g.fillEllipse(xPos + height/2 * (1 - sliderPosProportional),
                      y + height/2 * (1 - sliderPosProportional),
                      height * sliderPosProportional,
                      height * sliderPosProportional);
        
        
    }
    
    
};



#endif  // CUSTOMLOOK_H_INCLUDED
