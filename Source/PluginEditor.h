/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_EF0499D8E4B382F3__
#define __JUCE_HEADER_EF0499D8E4B382F3__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "CustomLook.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ApdelayAudioProcessorEditor  : public AudioProcessorEditor,
                                     public SliderListener
{
public:
    //==============================================================================
    ApdelayAudioProcessorEditor (AudioProcessor& processor);
    ~ApdelayAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);

    // Binary resources:
    //static const char* screenShot20151119At18_08_57_png;
    //static const int screenShot20151119At18_08_57_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    CustomLook m_look;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> m_leftDelaySlider;
    ScopedPointer<Slider> m_rightDelaySlider;
    ScopedPointer<Slider> m_leftFeedbackSlider;
    ScopedPointer<Slider> m_rightFeedbackSlider;
    ScopedPointer<Slider> m_dryWetSlider;
    ScopedPointer<Slider> m_nUnitsSlider;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ApdelayAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_EF0499D8E4B382F3__
