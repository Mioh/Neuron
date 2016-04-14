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
    void 	drawLinearSlider (Graphics & g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle sliderStyle, Slider & slider){
        
        Colour blue = Colour(33,150,243);
        Colour pink = Colour(233,30,99);
        int corner = 5;
        
        if (sliderStyle == Slider::SliderStyle::LinearHorizontal) {
            
            //Background
            g.setColour(blue);
            g.setOpacity(0.54f);
            g.fillRoundedRectangle(0, y, width, height * 0.75f, corner);
            //Slider
            g.setColour(blue);
            g.fillRoundedRectangle(0, y, (int) sliderPos - x, height * 0.75f, corner);
            
        } else {
            //Slider::SliderStyle::LinearVertical
            //TODO: Implement the rest
            
            //Background
            g.setColour(pink);
            g.setOpacity(0.54f);
            g.fillRoundedRectangle(x, 2*y, width, height, corner);
            //Slider
            g.setColour(pink);
            g.fillRoundedRectangle(x,
                                   (int) sliderPos + y,
                                   width - x,
                                   (y + height) - (int) sliderPos, corner);
        }
    
        
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
        
        Colour green = Colour(0,150,136);
        int xPos = x + width/2 - height/2;
        
        g.setColour(green);
        g.setOpacity(0.54f);
        g.fillEllipse(xPos,
                      y,
                      height,
                      height);
        
        g.setColour(green);
        g.fillEllipse(xPos + height/2 * (1 - sliderPosProportional),
                      y + height/2 * (1 - sliderPosProportional),
                      height * sliderPosProportional,
                      height * sliderPosProportional);
        
        
    }
    
    
};



#endif  // CUSTOMLOOK_H_INCLUDED
