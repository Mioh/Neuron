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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ApdelayAudioProcessorEditor::ApdelayAudioProcessorEditor (AudioProcessor& processor)
    : AudioProcessorEditor(processor)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_leftDelaySlider = new Slider ("left Delay"));
    m_leftDelaySlider->setRange (1, 100, 1);
    m_leftDelaySlider->setTextValueSuffix (" ms");
    m_leftDelaySlider->setSliderStyle (Slider::LinearHorizontal);
    m_leftDelaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_leftDelaySlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_leftDelaySlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_leftDelaySlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_leftDelaySlider->addListener (this);

    addAndMakeVisible (m_rightDelaySlider = new Slider ("Right Delay"));
    m_rightDelaySlider->setRange (1, 100, 1);
    m_rightDelaySlider->setTextValueSuffix (" ms");
    m_rightDelaySlider->setSliderStyle (Slider::LinearHorizontal);
    m_rightDelaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_rightDelaySlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_rightDelaySlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_rightDelaySlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_rightDelaySlider->addListener (this);

    addAndMakeVisible (m_leftFeedbackSlider = new Slider ("Left Feedback"));
    m_leftFeedbackSlider->setRange (0, 100, 1);
    m_leftFeedbackSlider->setTextValueSuffix (" %");
    m_leftFeedbackSlider->setSliderStyle (Slider::LinearHorizontal);
    m_leftFeedbackSlider->setColour(Slider::backgroundColourId, Colours::black);
    m_leftFeedbackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_leftFeedbackSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_leftFeedbackSlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_leftFeedbackSlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_leftFeedbackSlider->addListener (this);

    addAndMakeVisible (m_rightFeedbackSlider = new Slider ("Right Feedback"));
    m_rightFeedbackSlider->setRange (0, 100, 1);
    m_rightFeedbackSlider->setTextValueSuffix (" %");
    m_rightFeedbackSlider->setSliderStyle (Slider::LinearHorizontal);
    m_rightFeedbackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_rightFeedbackSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_rightFeedbackSlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_rightFeedbackSlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_rightFeedbackSlider->addListener (this);

    addAndMakeVisible (m_dryWetSlider = new Slider ("Dry/Wet"));
    m_dryWetSlider->setRange (0, 100, 1);
    m_dryWetSlider->setTextValueSuffix (" %");
    m_dryWetSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    m_dryWetSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_dryWetSlider->setColour(Slider::rotarySliderFillColourId, Colours::black);
    m_dryWetSlider->setColour(Slider::rotarySliderOutlineColourId, Colours::transparentBlack);
    m_dryWetSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_dryWetSlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_dryWetSlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_dryWetSlider->addListener (this);
    
    addAndMakeVisible (m_nUnitsSlider = new Slider ("Number of Units"));
    m_nUnitsSlider->setRange (1, 16, 1);
    m_nUnitsSlider->setSliderStyle (Slider::LinearVertical);
    m_nUnitsSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_nUnitsSlider->setColour(Slider::rotarySliderFillColourId, Colours::black);
    m_nUnitsSlider->setColour(Slider::rotarySliderOutlineColourId, Colours::transparentBlack);
    m_nUnitsSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_nUnitsSlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_nUnitsSlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_nUnitsSlider->addListener (this);
    
    addAndMakeVisible (m_depthSlider = new Slider ("Depth"));
    m_depthSlider->setRange (1, 100, 1);
    m_dryWetSlider->setTextValueSuffix (" %");
    m_depthSlider->setSliderStyle (Slider::LinearHorizontal);
    m_depthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_depthSlider->setColour(Slider::rotarySliderFillColourId, Colours::black);
    m_depthSlider->setColour(Slider::rotarySliderOutlineColourId, Colours::transparentBlack);
    m_depthSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_depthSlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_depthSlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_depthSlider->addListener (this);
    
    addAndMakeVisible (m_speedSlider = new Slider ("Speed"));
    m_speedSlider->setRange (1, 100, 1);
    m_dryWetSlider->setTextValueSuffix (" %");
    m_speedSlider->setSliderStyle (Slider::LinearHorizontal);
    m_speedSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 20);
    m_speedSlider->setColour(Slider::rotarySliderFillColourId, Colours::black);
    m_speedSlider->setColour(Slider::rotarySliderOutlineColourId, Colours::transparentBlack);
    m_speedSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    m_speedSlider->setColour (Slider::textBoxBackgroundColourId, Colours::transparentBlack);
    m_speedSlider->setColour (Slider::textBoxOutlineColourId, Colours::transparentBlack);
    m_speedSlider->addListener (this);

    //[UserPreSize]
    
    
    //[/UserPreSize]

    setSize (WIDTH, HEIGHT);

    //[Constructor] You can add your own custom stuff here..

    float leftDelay = processor.getParameter(ApdelayAudioProcessor::Parameters::LeftDelayTimeMS);
    float rightDelay = processor.getParameter(ApdelayAudioProcessor::Parameters::RightDelayTimeMS);
    float leftFeedBack = processor.getParameter(ApdelayAudioProcessor::Parameters::LeftFeedback);
    float rightFeedback = processor.getParameter(ApdelayAudioProcessor::Parameters::RightFeedback);
    float dryWet = processor.getParameter(ApdelayAudioProcessor::Parameters::DryWet);
    float numberOfUnits = processor.getParameter(ApdelayAudioProcessor::Parameters::nUnits);
    float depth = processor.getParameter(ApdelayAudioProcessor::Parameters::Depth);
    float speed = processor.getParameter(ApdelayAudioProcessor::Parameters::Speed);

    m_leftDelaySlider->setValue(leftDelay);
    m_rightDelaySlider->setValue(rightDelay);
    m_leftFeedbackSlider->setValue(leftFeedBack);
    m_rightFeedbackSlider->setValue(rightFeedback);
    m_dryWetSlider->setValue(dryWet);
    m_nUnitsSlider->setValue(numberOfUnits);
    m_depthSlider->setValue(depth);
    m_speedSlider->setValue(speed);


    LookAndFeel::setDefaultLookAndFeel(&m_look);


    //[/Constructor]
}

ApdelayAudioProcessorEditor::~ApdelayAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_leftDelaySlider = nullptr;
    m_rightDelaySlider = nullptr;
    m_leftFeedbackSlider = nullptr;
    m_rightFeedbackSlider = nullptr;
    m_dryWetSlider = nullptr;
    m_nUnitsSlider = nullptr;
    m_depthSlider = nullptr;
    m_speedSlider = nullptr;

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ApdelayAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour(224,224,224));

    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("LEFT DELAY"),
                WINDOW_MARGIN,
                WINDOW_MARGIN + BAR_TEXT_MARGIN,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredLeft, true);

    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("RIGHT DELAY"),
                WINDOW_MARGIN,
                WINDOW_MARGIN + BAR_TEXT_MARGIN + BAR_WIDTH  + MARGIN,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredLeft, true);

    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("LEFT FEEDBACK"),
                WINDOW_MARGIN,
                WINDOW_MARGIN + BAR_TEXT_MARGIN + 2*BAR_WIDTH  + 2*MARGIN,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredLeft, true);

    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("RIGHT FEEDBACK"),
                WINDOW_MARGIN,
                WINDOW_MARGIN + BAR_TEXT_MARGIN + 3*BAR_WIDTH  + 3*MARGIN,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredLeft, true);
                
    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("DRY/WET"),
                (WIDTH - TEXT_WIDTH) / 2,
                WINDOW_MARGIN + TEXT_HEIGHT + 3*BAR_WIDTH  + 4*MARGIN + DIAMETER,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredBottom, true);
    
    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("VOICES"),
                WIDTH/6 - TEXT_WIDTH/2 + WINDOW_MARGIN/2,
                WINDOW_MARGIN + TEXT_HEIGHT + 3*BAR_WIDTH  + 4*MARGIN + DIAMETER,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredBottom, true);
    
    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("DEPTH"),
                WIDTH/2 - TEXT_WIDTH/2 + DIAMETER/2 + MARGIN + 20,
                WINDOW_MARGIN + 20 + 4*BAR_WIDTH + 4*MARGIN - 8,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredBottom, true);
    
    g.setColour (Colours::black);
    g.setOpacity(0.54f);
    g.setFont (Font (14.00f, Font::plain));
    g.drawText (TRANS("SPEED"),
                WIDTH/2 - TEXT_WIDTH/2 + DIAMETER/2 + MARGIN + 20,
                WINDOW_MARGIN + TEXT_HEIGHT + 3*BAR_WIDTH  + 4*MARGIN + DIAMETER,
                TEXT_WIDTH,
                TEXT_HEIGHT,
                Justification::centredBottom, true);
  

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ApdelayAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_leftDelaySlider->setBounds    (WINDOW_MARGIN,
                                     WINDOW_MARGIN,
                                     WIDTH - WINDOW_MARGIN,
                                     BAR_WIDTH);
    
    m_rightDelaySlider->setBounds   (WINDOW_MARGIN,
                                     WINDOW_MARGIN + BAR_WIDTH + MARGIN,
                                     WIDTH - WINDOW_MARGIN,
                                     BAR_WIDTH);
    
    m_leftFeedbackSlider->setBounds (WINDOW_MARGIN,
                                     WINDOW_MARGIN + 2*BAR_WIDTH + 2*MARGIN,
                                     WIDTH - WINDOW_MARGIN,
                                     BAR_WIDTH);
    
    m_rightFeedbackSlider->setBounds (WINDOW_MARGIN,
                                      WINDOW_MARGIN + 3*BAR_WIDTH + 3*MARGIN,
                                      WIDTH - WINDOW_MARGIN,
                                      BAR_WIDTH);
    
    m_dryWetSlider->setBounds        ((WIDTH - DIAMETER) / 2,
                                      WINDOW_MARGIN + 4*BAR_WIDTH + 4*MARGIN,
                                      DIAMETER,
                                      DIAMETER);
    
    m_nUnitsSlider->setBounds        (WIDTH / 6,
                                      WINDOW_MARGIN + 4*BAR_WIDTH + 4*MARGIN -15,
                                      BAR_WIDTH * 0.5,
                                      DIAMETER + 15);
    
    m_depthSlider->setBounds (WIDTH/2 + DIAMETER/2 + MARGIN,
                              WINDOW_MARGIN + 4*BAR_WIDTH + 4*MARGIN,
                              WIDTH - (WIDTH/2.0 + DIAMETER/2) - WINDOW_MARGIN,
                              BAR_WIDTH);
    
    
    m_speedSlider->setBounds (WIDTH/2 + DIAMETER/2 + MARGIN,
                              WINDOW_MARGIN + 4*BAR_WIDTH + 4*MARGIN + 62,
                              WIDTH - (WIDTH/2.0 + DIAMETER/2) - WINDOW_MARGIN,
                              BAR_WIDTH);
    
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ApdelayAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_leftDelaySlider)
    {
        //[UserSliderCode_m_leftDelaySlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::LeftDelayTimeMS , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_leftDelaySlider]
    }
    else if (sliderThatWasMoved == m_rightDelaySlider)
    {
        //[UserSliderCode_m_rightDelaySlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::RightDelayTimeMS , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_rightDelaySlider]
    }
    else if (sliderThatWasMoved == m_leftFeedbackSlider)
    {
        //[UserSliderCode_m_leftFeedbackSlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::LeftFeedback , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_leftFeedbackSlider]
    }
    else if (sliderThatWasMoved == m_rightFeedbackSlider)
    {
        //[UserSliderCode_m_rightFeedbackSlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::RightFeedback , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_rightFeedbackSlider]
    }
    else if (sliderThatWasMoved == m_dryWetSlider)
    {
        //[UserSliderCode_m_dryWetSlider] -- add your slider handling code here..
               processor.setParameter( ApdelayAudioProcessor::Parameters::DryWet , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_dryWetSlider]
    }
    else if (sliderThatWasMoved == m_nUnitsSlider)
    {
        //[UserSliderCode_m_nUnitsSlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::nUnits , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_nUnitsSlider]
    }
    else if (sliderThatWasMoved == m_depthSlider)
    {
        //[UserSliderCode_m_depthSlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::Depth , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_depthSlider]
    }
    
    else if (sliderThatWasMoved == m_speedSlider)
    {
        //[UserSliderCode_m_speedSlider] -- add your slider handling code here..
        processor.setParameter( ApdelayAudioProcessor::Parameters::Speed , sliderThatWasMoved->getValue());
        //[/UserSliderCode_m_speedSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ApdelayAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="AudioProcessor&amp; processor" variableInitialisers="AudioProcessorEditor(processor)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="500" initialHeight="500">
  <BACKGROUND backgroundColour="ff626262">
    <ROUNDRECT pos="24 11 312 333" cornerSize="10" fill="solid: ff7d7d7d" hasStroke="0"/>
    <TEXT pos="48 51 200 30" fill="solid: ffffffff" hasStroke="0" text="Left Delay Time(MS)"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
    <TEXT pos="48 123 200 30" fill="solid: ffffffff" hasStroke="0" text="Right Delay Time(MS)"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
    <TEXT pos="48 195 200 30" fill="solid: ffffffff" hasStroke="0" text="Left Feedback"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
    <TEXT pos="48 275 200 30" fill="solid: ffffffff" hasStroke="0" text="Right Feedback"
          fontname="Default font" fontsize="12" bold="0" italic="0" justification="33"/>
    <IMAGE pos="264 275 60 63" resource="screenShot20151119At18_08_57_png"
           opacity="1" mode="0"/>
  </BACKGROUND>
  <SLIDER name="left Delay" id="6d33b0fdfb0536c1" memberName="m_leftDelaySlider"
          virtualName="" explicitFocusOrder="0" pos="24 16 312 64" textboxtext="ffffffff"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="5000"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Right Delay" id="1237722c5fc9e601" memberName="m_rightDelaySlider"
          virtualName="" explicitFocusOrder="0" pos="24 88 312 64" textboxtext="ffffffff"
          textboxbkgd="ffffff" textboxoutline="808080" min="1" max="5000"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Left Feedback" id="6a6a725cebfbb99b" memberName="m_leftFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="24 160 312 64" textboxtext="ffffffff"
          textboxbkgd="ffffff" textboxoutline="808080" min="0" max="1"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Right Feedback" id="aa0861c77e95e052" memberName="m_rightFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="24 240 312 64" textboxtext="ffffffff"
          textboxbkgd="ffffff" textboxoutline="808080" min="0" max="1"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Dry/Wet" id="be196ce6c72d36bc" memberName="m_dryWetSlider"
          virtualName="" explicitFocusOrder="0" pos="24 312 312 64" textboxtext="ffffffff"
          textboxbkgd="ffffff" textboxoutline="808080" min="0" max="1"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: screenShot20151119At18_08_57_png, 17569, "../../Screen Shot 2015-11-19 at 18.08.57.png"
static const unsigned char resource_ApdelayAudioProcessorEditor_screenShot20151119At18_08_57_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,201,8,2,0,0,0,233,102,234,108,0,0,1,
137,105,67,67,80,73,67,67,32,80,114,111,102,105,108,101,0,0,40,21,173,145,61,75,3,65,16,134,223,139,209,40,9,24,36,104,10,145,5,69,44,238,228,140,69,76,180,201,7,152,136,69,136,10,106,119,185,156,137,
144,143,227,114,33,250,3,236,108,180,16,109,20,245,47,136,54,22,150,98,161,133,32,8,193,223,32,4,2,34,225,156,189,67,82,5,27,7,118,231,217,119,103,63,102,6,112,153,138,174,151,220,0,202,21,211,200,46,
199,217,230,214,54,243,52,225,133,15,35,136,98,76,81,107,122,44,147,89,165,144,30,214,126,131,192,183,94,37,126,215,78,250,235,125,233,160,113,113,51,176,114,54,17,53,197,30,135,126,101,111,94,171,169,
128,48,72,130,154,175,169,101,226,18,177,168,234,134,73,124,74,44,53,76,157,243,35,113,192,160,15,18,55,57,23,28,254,228,156,179,217,197,83,9,24,235,217,4,224,10,18,251,115,14,207,112,46,56,188,192,89,
45,42,121,138,73,17,139,206,31,136,128,161,84,146,133,229,136,20,179,87,255,56,149,75,117,202,211,54,94,45,159,86,217,88,35,239,167,49,142,20,146,96,8,67,70,4,18,98,166,182,71,249,2,137,170,190,111,236,
22,138,38,139,81,101,53,150,168,150,245,186,169,25,34,75,87,212,89,145,133,228,57,153,199,241,158,113,15,180,178,118,47,132,209,151,174,86,189,4,34,147,64,223,97,87,203,157,0,119,247,64,240,169,171,77,
157,3,195,139,192,237,179,174,24,138,115,31,205,66,219,253,215,186,182,51,31,178,227,5,95,28,232,255,176,172,214,52,224,57,6,58,71,150,245,125,101,89,157,107,122,159,122,246,80,250,1,36,119,105,224,161,
75,188,147,0,0,1,157,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,
115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,88,77,80,32,67,111,114,101,32,53,46,52,46,48,34,62,10,32,32,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,114,100,102,61,34,104,
116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,115,
99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,101,120,105,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,
111,98,101,46,99,111,109,47,101,120,105,102,47,49,46,48,47,34,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,110,115,105,111,110,62,50,48,48,60,47,101,120,
105,102,58,80,105,120,101,108,88,68,105,109,101,110,115,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,115,105,111,110,62,50,48,49,60,47,101,
120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,115,105,111,110,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,60,47,114,100,102,58,82,68,
70,62,10,60,47,120,58,120,109,112,109,101,116,97,62,10,90,48,104,40,0,0,64,0,73,68,65,84,120,1,237,157,89,140,100,201,117,158,115,223,106,95,122,155,233,230,44,156,125,134,226,144,154,133,38,135,226,72,
196,208,18,69,193,128,108,67,130,0,193,132,13,216,15,54,108,25,126,243,139,95,13,27,6,12,251,217,134,1,193,144,101,91,144,12,18,130,57,35,154,212,131,72,145,166,185,204,214,179,116,79,247,204,116,79,111,
213,93,123,85,238,233,239,143,147,25,21,117,115,169,172,234,234,238,204,202,140,206,190,21,55,226,68,220,136,19,255,61,113,226,196,114,227,95,250,210,75,49,92,92,151,208,181,5,16,25,13,139,183,5,132,57,
116,244,199,219,210,116,32,139,102,203,131,219,130,34,201,218,178,221,43,129,210,247,87,152,104,78,209,251,246,178,237,77,161,135,71,106,208,41,160,141,38,154,134,42,68,130,162,247,7,203,246,32,169,118,
23,5,222,182,21,37,82,212,193,190,109,236,179,248,9,234,219,136,53,26,141,193,174,214,208,151,46,49,244,53,24,87,96,32,57,48,244,18,171,31,174,198,19,129,88,107,137,170,177,208,234,135,117,7,166,25,13,
137,5,152,252,175,197,170,97,215,1,90,245,24,208,191,71,31,88,33,128,18,137,93,245,149,184,30,114,21,115,64,97,229,6,70,65,55,49,176,197,60,104,193,250,196,205,184,91,60,40,131,187,166,59,178,175,108,
159,144,242,140,25,99,203,179,226,80,60,187,186,134,67,201,113,156,201,152,3,112,32,53,230,130,201,42,147,112,99,185,117,88,120,24,75,172,254,236,239,135,197,239,145,201,103,12,44,53,245,126,21,178,145,
129,199,193,43,122,52,187,194,16,40,17,19,131,103,85,189,94,247,254,177,231,208,57,64,19,28,41,115,67,88,157,110,144,242,76,108,199,214,88,199,242,204,185,77,207,81,0,150,127,51,66,84,197,227,187,122,
249,93,179,58,216,225,91,147,208,17,108,249,240,219,100,235,56,249,208,119,133,66,85,107,250,47,20,190,30,109,196,11,112,45,26,91,13,65,200,24,67,119,20,253,67,15,44,193,198,113,200,214,195,120,102,9,
57,186,105,128,164,166,244,114,247,241,22,194,76,106,145,86,1,30,134,62,214,103,52,246,28,136,3,195,14,44,68,143,186,188,4,224,105,8,97,220,128,164,70,188,46,172,196,235,13,225,168,81,23,120,232,12,53,
83,24,175,73,102,113,95,71,100,137,82,63,252,146,97,30,94,6,180,250,24,101,7,194,148,75,52,124,192,82,191,182,227,0,142,48,97,61,157,139,112,55,141,88,173,86,171,39,26,14,113,80,59,204,8,96,192,11,4,9,
73,120,184,198,16,108,192,143,12,240,115,167,156,117,33,80,222,177,59,40,7,134,15,88,187,107,234,176,32,80,168,195,107,33,4,113,37,196,176,10,11,140,0,154,68,76,94,254,234,42,225,37,32,57,159,137,45,133,
225,132,51,39,204,220,93,243,50,198,87,200,141,254,253,195,7,172,221,74,183,132,13,240,113,248,18,154,156,200,1,12,10,183,159,235,37,133,173,132,196,22,125,164,156,27,36,186,78,212,165,16,190,156,50,70,
20,84,136,54,101,234,252,138,194,55,118,251,228,192,240,1,171,189,130,52,60,226,71,93,153,131,149,96,22,147,184,138,57,16,185,8,69,130,38,201,49,93,137,87,54,38,209,240,36,21,224,58,63,167,111,185,56,
137,49,126,245,88,77,183,99,183,79,14,12,31,176,118,233,88,130,70,11,39,230,115,104,16,168,26,130,11,30,255,51,228,52,18,187,181,39,165,134,68,87,132,23,0,4,80,46,71,124,46,70,55,99,183,111,14,12,31,176,
194,42,74,170,56,84,32,136,156,210,100,208,16,62,146,26,1,106,144,152,74,36,227,117,245,138,38,192,4,28,156,19,97,238,175,101,225,114,113,50,143,123,167,207,115,133,200,193,45,124,100,203,239,34,91,55,
227,191,109,28,72,238,18,0,109,209,3,31,208,112,248,161,152,250,75,55,167,2,11,36,18,59,72,172,84,34,158,76,38,248,231,122,61,23,202,104,80,38,47,167,129,137,184,41,232,24,49,146,166,249,115,29,34,88,
237,1,44,61,104,236,186,115,96,136,37,22,175,4,112,113,26,19,194,8,184,36,109,164,23,107,212,132,170,184,67,21,166,171,186,169,230,240,64,189,156,4,151,11,32,129,128,67,40,234,24,100,53,55,166,108,137,
43,1,206,253,119,36,146,94,221,121,56,142,233,192,129,33,6,150,48,33,27,104,45,73,191,151,72,202,36,42,245,73,54,81,4,87,38,30,75,131,45,217,24,4,17,126,78,125,2,83,76,15,74,127,114,164,177,26,144,81,
255,9,170,220,120,208,105,252,2,17,41,198,88,234,0,152,126,131,134,27,88,180,189,179,81,105,184,39,221,169,81,7,30,233,120,60,157,72,230,51,73,80,133,220,106,2,68,162,13,76,33,121,18,13,68,149,235,231,
24,239,73,120,9,140,82,192,188,199,152,39,64,142,177,213,47,144,162,116,67,14,44,169,231,210,159,36,134,156,196,73,37,98,217,100,34,147,136,21,50,217,52,54,82,68,81,189,234,76,9,53,52,120,112,23,143,39,
157,212,114,189,103,141,104,135,172,22,170,60,144,12,144,99,104,69,241,210,247,253,112,3,203,201,24,7,42,9,39,105,229,136,171,100,189,22,175,214,179,249,108,166,81,79,34,115,64,29,130,9,81,150,192,210,
32,123,87,181,129,22,22,227,10,22,147,241,70,77,226,206,75,54,113,206,163,202,252,30,109,125,115,117,76,56,244,155,41,26,85,183,16,20,100,48,250,75,51,252,107,212,19,85,0,19,139,151,183,83,136,46,193,
205,193,9,176,36,144,105,169,106,173,81,137,233,7,216,16,96,192,75,202,151,250,81,239,192,96,83,41,35,8,68,142,123,68,207,154,254,61,195,45,177,92,195,183,48,225,102,107,24,4,166,211,241,116,165,145,75,
38,11,233,84,33,149,68,38,33,177,248,213,128,79,60,217,72,165,203,245,70,177,86,45,86,171,181,74,85,211,135,228,82,119,157,100,19,81,132,8,105,54,222,172,237,194,92,255,140,29,117,202,225,6,22,152,106,
246,98,244,110,213,90,50,81,79,100,210,169,100,58,155,143,103,243,133,28,192,202,32,200,176,36,212,42,172,118,144,153,10,193,150,78,162,116,85,42,224,44,137,184,170,86,5,44,117,127,200,166,166,116,50,
168,58,89,213,3,31,150,174,157,160,5,244,246,152,81,10,25,118,3,169,218,10,169,131,189,193,44,165,40,75,44,187,106,36,19,197,90,189,88,175,151,19,169,90,38,83,140,199,55,233,248,82,233,236,196,196,212,
204,116,38,155,193,198,133,106,85,172,86,202,21,4,151,134,132,152,32,156,117,148,252,144,81,234,32,235,238,39,52,118,112,45,52,10,139,225,79,201,59,144,143,94,208,112,75,44,215,94,180,63,202,56,125,153,
51,25,72,114,213,24,40,86,43,178,102,165,147,171,233,140,86,43,52,170,177,68,42,150,205,198,231,166,102,27,18,96,245,82,181,90,44,149,100,249,146,173,43,214,154,107,198,71,144,83,178,200,221,197,234,58,
118,251,228,0,61,201,80,191,97,12,4,177,74,181,140,80,206,52,10,7,168,18,111,12,120,48,49,102,33,4,50,201,99,126,174,146,82,14,78,85,67,100,2,65,229,244,41,217,89,137,145,19,107,186,246,136,221,248,54,
134,161,99,221,176,3,203,90,223,222,14,167,39,57,243,167,147,56,182,186,161,137,143,150,244,81,165,157,191,217,254,9,173,98,198,250,208,68,21,30,7,83,143,26,71,230,239,44,245,248,186,55,7,134,190,43,148,
125,83,138,149,160,133,97,93,2,12,155,41,11,26,232,16,83,140,9,147,245,106,181,94,171,170,55,196,194,128,36,75,39,153,21,228,231,148,42,18,201,106,15,159,156,148,106,74,39,238,21,212,114,99,17,212,226,
196,62,254,14,61,176,16,49,104,235,224,202,153,208,181,140,61,1,172,18,201,108,54,151,214,194,6,12,91,224,168,138,68,178,112,32,85,229,63,58,187,0,39,211,169,147,95,64,201,176,212,234,249,12,110,202,125,
31,220,28,147,122,14,12,253,168,48,174,133,87,134,10,91,166,220,2,2,22,118,212,120,4,151,174,110,104,39,59,22,83,139,204,89,39,181,164,65,107,149,157,168,3,151,140,41,141,196,100,149,67,85,0,180,86,158,
158,109,59,158,118,113,214,131,120,39,217,145,247,13,191,196,210,108,160,3,5,240,112,82,7,57,212,192,104,149,78,215,170,216,213,153,200,177,245,88,52,101,5,36,105,57,67,179,239,147,207,214,183,131,51,
215,210,194,4,97,77,72,201,139,227,142,95,59,128,92,164,197,183,188,61,168,60,201,136,120,232,67,140,141,195,90,95,89,203,91,206,234,210,189,62,138,145,185,202,57,193,139,233,30,117,133,56,178,1,117,192,
171,25,43,40,185,177,33,247,32,211,133,11,163,216,89,193,99,42,149,146,193,85,78,217,180,6,145,186,31,118,126,170,14,135,225,134,91,98,25,170,60,146,66,144,181,49,71,80,33,144,62,175,21,5,66,154,129,224,
193,25,24,124,148,35,138,203,58,97,121,186,35,30,36,225,156,148,107,101,64,172,44,96,152,243,149,208,201,191,157,168,17,247,13,183,142,101,144,178,171,26,216,251,58,183,42,241,154,114,246,198,45,80,163,
84,45,98,36,152,207,66,210,75,63,141,9,16,66,2,13,247,45,243,190,225,140,112,18,16,136,179,76,20,176,3,206,86,190,35,249,119,184,37,22,141,72,139,250,166,164,249,155,45,188,131,150,94,173,74,90,77,223,
8,80,194,148,203,141,60,4,18,250,65,243,224,71,121,227,191,3,147,195,82,172,206,104,147,97,129,96,228,156,19,99,77,191,133,140,175,195,13,172,22,48,118,218,209,84,38,107,255,157,208,150,207,97,69,243,
128,173,128,136,53,65,208,114,139,181,136,23,80,180,46,94,38,46,97,11,67,152,83,200,44,45,79,144,190,15,254,80,186,124,110,14,106,59,183,62,124,4,61,221,154,96,136,88,209,89,84,200,180,213,86,9,215,230,
22,140,87,119,166,161,227,17,116,92,135,103,87,23,2,0,227,153,76,126,114,114,34,157,78,139,184,94,199,254,85,41,151,17,81,197,98,209,13,71,33,111,205,255,116,120,32,137,70,212,29,1,137,37,193,18,109,61,
141,253,218,2,5,37,97,69,230,43,73,36,27,32,106,112,135,159,112,130,65,137,117,166,194,165,28,171,185,72,6,189,148,45,122,67,172,98,197,34,75,34,202,232,85,132,56,40,18,235,16,27,45,196,72,223,15,59,176,
122,53,94,199,214,118,128,19,20,136,117,170,185,161,202,161,171,133,69,135,40,25,197,216,149,56,49,89,96,77,78,181,82,65,68,33,174,232,249,106,245,58,83,69,85,172,249,202,65,24,21,50,199,216,114,140,240,
151,97,7,150,211,188,157,220,240,85,234,237,145,185,65,226,9,125,201,144,33,114,22,116,177,126,57,145,192,62,149,42,151,203,14,37,137,90,181,50,53,53,129,156,218,220,92,47,105,129,141,128,202,173,196,
148,38,145,236,57,134,222,142,24,54,130,17,189,234,229,60,146,85,239,82,47,42,107,214,78,84,238,166,110,164,234,11,159,105,173,129,151,45,2,87,159,91,152,97,251,116,9,69,10,124,149,203,149,74,197,50,108,
118,126,71,148,105,174,238,135,115,25,118,137,213,149,11,134,128,246,104,32,225,162,92,151,24,68,131,41,172,157,200,177,108,46,151,205,166,114,185,220,198,230,70,5,149,170,92,102,106,8,194,8,176,186,229,
31,100,57,210,222,35,11,172,110,173,74,95,230,122,186,38,48,2,209,131,110,142,34,159,152,154,204,207,206,205,210,39,110,109,111,186,110,83,6,82,28,218,58,202,59,158,110,57,143,195,67,14,140,28,176,28,
170,28,7,164,189,183,60,210,185,234,185,92,97,114,98,98,122,122,250,198,141,27,149,42,218,250,22,40,108,146,96,221,114,179,132,198,187,49,188,66,12,117,244,15,247,148,78,199,42,245,12,244,242,70,43,104,
90,210,7,156,104,181,41,93,32,166,132,82,185,180,181,181,101,177,181,74,197,114,11,59,62,168,113,61,159,50,142,116,251,135,71,138,13,104,233,178,96,237,88,22,24,223,105,242,112,102,122,122,106,122,138,
238,112,123,123,27,138,106,5,123,66,37,153,98,135,152,70,124,134,36,174,154,22,52,43,197,72,113,109,255,149,181,65,208,254,211,13,103,10,228,140,236,159,82,220,229,245,63,0,195,191,181,181,245,173,173,
109,96,198,226,210,90,173,130,0,51,181,61,172,43,56,163,211,12,5,88,24,59,246,123,14,240,250,141,144,84,23,168,180,86,38,193,114,120,167,147,39,50,153,244,118,177,180,48,55,183,93,100,151,33,251,245,57,
39,132,149,130,242,64,156,78,165,25,24,122,102,141,61,253,115,96,180,36,150,217,49,25,241,57,27,122,163,82,102,79,116,226,212,201,147,133,201,73,162,64,28,107,22,216,120,207,90,121,153,28,146,144,85,70,
232,181,235,31,53,125,80,142,154,242,142,205,28,113,149,214,146,132,56,123,241,51,39,79,156,156,159,95,44,22,183,193,16,120,98,95,15,63,132,86,165,194,198,158,6,119,227,94,175,15,20,117,32,25,57,115,3,
107,96,152,159,201,100,11,233,116,54,195,86,158,252,196,242,202,234,202,234,90,150,53,242,117,172,242,232,96,169,82,60,206,196,14,61,38,192,66,134,117,96,219,56,104,47,14,140,154,196,138,35,145,80,190,
57,198,97,122,102,38,95,152,98,204,119,107,249,86,177,84,102,6,177,92,229,232,16,52,42,9,170,76,58,195,220,51,71,59,72,203,215,72,114,220,37,238,5,165,221,241,35,7,44,116,41,80,85,41,215,38,39,39,115,
185,9,236,7,96,102,187,84,46,110,108,232,172,172,120,3,89,133,133,43,155,1,88,73,140,90,2,150,115,99,108,237,70,206,30,119,163,7,44,45,99,72,22,242,133,201,169,105,102,7,83,236,140,78,167,43,213,82,82,
243,131,25,196,85,5,208,49,57,232,214,64,32,207,116,224,200,216,237,159,3,35,7,172,148,116,169,198,3,15,62,120,242,212,105,86,88,149,202,218,206,58,53,53,125,252,216,2,27,166,183,139,219,44,17,165,235,
195,244,128,232,218,181,2,98,255,204,29,229,20,71,80,121,15,251,172,112,76,231,194,133,152,76,174,240,240,35,143,108,108,85,146,185,137,175,126,245,215,50,153,220,250,234,173,226,214,141,31,255,240,47,
177,140,114,38,169,91,56,175,211,255,28,176,156,161,222,25,192,70,25,40,251,173,251,17,148,88,33,176,66,118,24,176,52,61,147,72,110,151,138,156,251,247,192,195,79,126,253,183,254,110,50,145,69,209,250,
228,242,7,151,62,190,176,181,193,138,134,6,167,254,49,233,172,110,80,212,228,161,117,201,97,86,99,255,158,28,24,45,3,41,236,208,249,183,141,198,213,235,215,175,126,114,249,233,167,63,51,81,152,224,68,
26,38,158,153,207,41,149,203,76,215,104,238,16,12,114,177,249,159,61,89,56,38,232,196,129,145,3,22,115,203,116,117,204,218,48,16,124,244,177,199,55,54,54,96,203,230,198,198,250,218,42,129,152,24,192,150,
155,207,209,150,11,192,229,150,34,71,197,85,55,161,216,137,195,35,26,54,90,192,66,8,37,245,217,166,120,189,84,90,88,56,118,252,248,49,182,118,161,62,1,172,181,181,85,102,158,101,118,103,154,25,83,169,
172,87,174,47,28,81,96,220,110,181,71,11,88,112,75,50,73,231,121,52,78,158,60,53,53,53,197,36,52,129,155,91,27,152,227,153,121,54,81,68,87,8,25,225,104,86,214,47,70,216,60,86,185,34,12,105,191,29,57,96,
217,146,152,88,42,185,176,184,48,59,59,203,10,247,233,217,217,124,97,34,133,169,157,227,255,152,148,214,113,12,124,221,130,254,144,179,149,189,125,180,157,117,227,144,94,28,24,53,96,113,2,145,206,144,
225,115,2,44,235,3,73,249,124,129,43,211,210,133,9,182,59,167,164,126,105,25,160,173,174,1,126,250,102,10,110,172,84,137,11,251,113,67,12,44,26,59,108,111,187,13,67,224,131,15,244,225,190,23,67,69,207,
228,178,172,98,192,142,117,252,196,73,125,78,160,30,203,23,242,242,104,227,160,190,105,81,44,237,152,221,45,171,61,121,219,145,44,44,134,47,201,158,89,13,53,193,16,3,235,96,124,103,84,88,152,40,144,246,
218,181,107,233,76,118,114,122,134,105,105,86,58,208,27,22,10,5,144,56,49,49,129,122,207,150,103,224,149,203,75,3,11,157,135,72,24,24,241,123,236,90,248,136,32,41,194,132,145,3,150,91,148,172,241,222,
205,165,37,237,150,119,150,80,206,234,99,198,48,147,205,3,38,6,132,4,179,84,185,90,111,108,111,115,186,100,132,99,123,220,70,80,181,7,245,209,141,30,61,96,37,226,91,155,91,232,228,107,152,68,177,179,199,
19,19,83,83,96,10,15,32,67,111,103,233,12,139,1,89,172,197,78,232,116,90,31,60,188,29,172,140,166,184,226,125,25,45,96,161,136,35,141,116,208,114,50,141,105,116,121,101,25,85,29,117,10,96,161,192,99,121,
231,42,197,44,153,44,22,75,234,12,91,150,81,129,203,57,47,98,186,245,137,80,133,52,222,63,106,158,209,2,22,173,203,130,119,148,42,190,53,32,132,37,146,44,34,69,86,157,62,243,192,99,79,62,131,10,159,201,
230,248,46,24,63,186,70,150,151,218,136,208,99,162,163,248,233,24,72,146,48,60,68,155,207,237,104,123,142,224,234,134,61,27,140,51,137,48,148,210,197,177,72,230,204,108,178,184,125,156,111,56,177,133,
16,132,177,84,102,102,102,170,82,170,108,109,108,36,115,200,176,34,182,8,212,50,134,144,123,102,219,141,96,4,81,5,43,70,78,98,177,248,24,21,138,141,93,171,27,27,239,190,249,122,173,204,58,247,202,133,
247,222,126,243,231,63,93,186,118,141,207,206,253,198,111,252,214,75,47,125,121,118,126,150,21,240,241,100,134,126,17,225,227,190,106,129,66,175,237,135,186,104,134,186,221,17,168,30,146,8,47,174,12,85,
35,136,173,33,91,54,163,118,107,57,107,216,214,93,199,150,142,182,189,107,121,250,55,45,140,169,111,151,127,246,211,31,189,244,197,151,210,241,218,183,254,244,143,223,254,197,255,91,89,89,206,167,51,191,
243,59,191,119,242,212,169,149,213,213,235,55,110,48,17,141,165,158,233,29,118,177,242,25,2,28,39,56,112,149,25,85,121,9,66,45,24,201,227,252,90,235,236,93,199,226,117,12,244,73,134,203,131,106,65,117,
40,179,93,125,225,71,77,98,201,122,128,86,94,45,151,248,11,146,254,213,191,252,231,31,95,124,119,50,159,154,155,153,226,35,59,215,175,47,189,245,230,27,207,60,243,25,20,172,45,157,224,167,227,36,217,47,
198,2,64,76,169,76,248,176,51,140,243,72,25,42,122,14,6,30,242,14,48,21,68,28,97,175,23,198,222,99,149,29,53,96,241,94,37,178,76,60,35,113,176,130,86,42,191,248,201,79,255,251,31,255,215,7,30,252,212,
246,246,214,194,220,52,128,251,179,63,253,31,213,106,121,109,117,133,1,164,150,55,52,226,218,99,88,107,228,114,121,20,126,76,169,197,109,41,94,218,222,26,216,184,76,8,29,97,0,117,171,154,22,25,117,58,
115,96,248,186,194,110,53,236,39,28,121,194,96,16,185,130,230,142,189,29,134,36,178,233,243,231,207,253,202,151,95,186,121,227,250,91,111,188,153,205,166,49,205,95,191,118,117,107,107,243,230,242,173,
137,66,110,114,34,207,230,104,4,61,66,171,94,173,113,42,27,123,194,48,41,68,36,191,147,85,66,87,63,197,24,5,154,145,3,22,106,55,26,18,118,118,29,207,206,134,104,192,85,169,228,11,153,207,61,251,217,31,
252,224,175,242,185,12,3,195,243,231,63,88,88,156,127,230,233,167,179,233,12,11,0,215,215,55,89,243,135,168,207,100,50,165,82,101,98,162,224,79,142,12,32,50,162,144,178,30,176,253,141,26,181,174,80,95,
92,106,110,156,111,212,226,44,139,137,213,83,185,212,235,191,248,217,212,100,33,151,77,150,138,91,250,230,92,172,94,220,222,250,189,223,253,189,199,31,127,130,126,80,139,31,210,233,47,124,225,11,167,79,
159,166,19,172,85,245,101,138,182,129,161,198,4,173,95,128,183,17,240,182,163,138,74,143,156,29,75,163,188,120,146,189,56,26,199,36,99,249,124,110,123,115,139,243,107,183,54,215,83,201,132,128,149,136,
167,83,201,171,87,174,252,219,127,243,175,129,24,43,1,51,233,233,217,185,249,167,159,122,102,117,117,5,96,113,208,3,61,158,190,182,233,214,49,143,0,114,122,85,209,163,202,60,38,192,184,142,28,176,56,153,
8,29,28,145,131,20,98,213,40,40,65,204,28,59,182,128,218,206,111,162,144,71,133,42,87,107,216,171,206,158,125,155,13,173,136,43,14,11,121,236,177,227,239,188,251,206,229,203,151,73,192,185,183,206,110,
175,227,141,198,216,50,208,121,120,121,12,14,13,176,218,139,238,235,176,47,143,230,148,57,248,42,157,46,150,74,200,44,151,182,113,230,244,233,107,215,174,112,132,159,83,192,56,187,129,211,224,81,216,99,
201,20,200,98,41,115,99,121,121,121,125,131,145,226,42,98,202,132,86,74,221,168,220,129,177,101,47,183,101,18,169,29,81,161,0,48,154,65,187,134,37,12,235,66,57,137,26,57,29,139,65,31,50,168,88,42,162,
137,179,46,25,139,20,92,248,212,233,51,55,151,110,178,108,20,160,161,221,75,193,135,76,223,252,106,20,183,183,73,242,241,165,75,87,174,92,103,98,17,14,114,150,36,66,107,208,154,121,208,202,51,52,18,235,
176,24,151,214,169,107,124,123,34,206,98,172,154,14,147,209,102,84,244,168,75,151,46,35,201,208,191,193,22,130,140,131,252,232,45,49,85,229,242,128,41,198,17,146,196,17,130,214,158,74,36,248,252,137,151,
88,183,95,48,123,245,125,62,254,237,247,30,31,53,68,158,145,3,150,237,106,206,102,179,24,14,16,79,249,92,30,100,49,69,120,227,198,18,162,10,96,209,156,154,117,70,253,84,191,88,171,150,180,148,20,7,218,
56,158,141,117,241,153,108,186,82,193,112,191,227,92,111,232,136,154,97,161,127,135,172,163,47,130,42,79,51,212,168,162,22,163,213,21,242,165,66,214,241,9,63,78,185,226,216,181,237,237,210,236,220,28,
7,204,108,172,110,166,19,204,213,152,5,213,181,111,156,187,122,46,159,41,76,228,178,185,52,136,76,165,121,15,27,27,235,235,116,163,157,0,33,97,231,145,49,226,158,145,147,88,82,198,27,238,16,172,84,166,
84,68,240,36,62,243,204,179,23,47,126,196,80,144,94,146,254,209,0,193,242,81,205,52,171,199,172,150,139,101,214,6,98,119,144,213,94,226,139,143,9,232,211,58,200,48,39,87,4,38,204,90,182,178,198,217,183,
58,192,139,121,143,126,160,214,91,80,241,200,222,4,253,60,226,238,208,140,150,196,50,158,234,0,82,247,105,56,112,195,217,13,143,63,254,20,51,128,38,188,105,57,44,17,64,7,107,22,182,83,237,153,110,212,
115,5,84,117,108,20,130,24,114,139,93,23,90,188,37,115,232,93,117,2,242,240,184,81,147,88,204,40,51,145,204,23,157,99,76,203,160,140,111,110,109,94,189,122,249,129,51,159,66,135,210,146,5,36,21,221,25,
255,248,0,102,163,150,76,102,94,120,254,249,251,239,191,255,173,183,222,250,248,227,143,74,154,183,46,51,93,13,236,220,128,218,176,101,87,66,36,193,244,225,76,247,199,66,185,73,168,223,213,240,155,16,
215,5,243,23,74,247,24,205,57,118,64,40,98,201,101,231,113,180,115,71,177,124,232,32,123,134,102,174,80,205,118,219,78,45,76,171,51,247,12,128,184,209,78,137,234,39,159,92,66,73,207,230,51,232,94,156,
203,253,248,19,79,165,50,57,157,250,94,137,229,115,19,159,126,248,145,249,185,249,15,62,248,128,239,160,148,217,134,95,169,48,15,141,1,98,119,105,244,225,86,48,162,37,128,53,14,136,103,19,181,32,214,72,
52,16,124,73,86,12,178,75,3,176,48,49,73,32,37,136,19,158,72,213,89,112,72,42,7,70,87,50,74,103,213,108,254,105,66,200,61,202,125,162,197,225,125,23,23,68,233,220,174,208,224,166,119,108,64,216,213,219,
158,67,123,72,123,98,209,180,135,14,96,200,161,148,147,170,106,205,30,29,155,14,254,168,179,72,77,231,249,53,98,116,136,216,180,80,179,230,231,231,95,126,249,215,24,249,125,235,219,223,98,15,15,223,232,
229,11,189,88,222,183,183,54,11,19,44,155,193,218,206,201,15,85,198,134,8,188,128,75,146,118,96,11,180,50,149,168,83,69,56,50,30,212,136,183,241,36,107,235,27,16,8,82,213,152,236,174,200,175,4,91,58,4,
49,48,30,3,109,205,172,76,160,185,81,168,168,66,96,181,48,103,75,121,252,163,61,91,200,222,7,134,30,35,232,22,27,82,246,239,247,15,37,73,183,156,161,161,10,67,224,14,165,156,84,21,37,90,7,126,176,109,
176,198,30,104,185,173,173,34,75,28,104,199,135,30,124,240,225,135,31,193,179,186,186,122,245,234,85,118,135,97,183,226,35,152,172,26,101,7,6,103,147,50,147,88,40,228,202,76,254,84,193,150,219,170,223,
228,156,36,22,121,72,24,1,30,212,116,240,162,179,189,1,21,184,97,241,87,235,20,55,125,114,90,66,147,142,87,75,120,248,186,24,1,14,79,190,13,124,83,69,176,37,14,200,2,162,178,122,231,217,226,83,249,40,
243,24,65,183,216,8,113,255,183,123,62,119,228,186,66,211,205,93,159,162,47,197,177,120,129,185,64,54,171,162,53,173,175,111,156,60,121,130,229,163,207,61,247,194,245,235,215,145,103,156,77,138,158,206,
249,202,184,19,199,143,103,179,153,205,205,45,120,202,212,53,0,85,67,203,145,52,65,99,171,189,105,120,188,186,103,198,7,228,57,108,40,196,121,213,33,178,125,17,153,201,61,159,53,151,184,146,241,172,135,
179,132,238,202,227,154,79,113,244,238,209,68,236,225,32,219,131,98,119,180,101,187,223,84,187,243,208,221,200,1,139,94,76,159,96,106,168,31,116,38,0,189,204,72,32,125,83,174,84,226,171,170,23,47,92,100,
151,253,111,254,230,55,22,143,31,251,232,195,15,183,138,69,240,199,212,245,194,194,2,230,9,78,210,66,188,57,84,193,124,48,97,45,111,77,142,125,2,12,129,35,13,44,101,44,83,247,84,215,196,144,107,92,46,
41,14,145,71,132,105,1,107,131,190,82,58,189,67,93,123,195,24,80,9,223,193,133,33,176,213,242,157,146,116,8,219,47,68,246,75,223,225,145,46,168,231,235,210,45,209,48,135,131,30,102,145,181,156,42,30,7,
91,204,70,35,126,48,157,111,109,111,113,221,88,223,92,186,177,196,0,240,107,95,251,218,241,99,199,182,182,183,79,28,63,153,205,22,88,239,190,185,201,103,81,106,199,142,29,71,15,67,9,179,173,173,160,210,
28,44,17,2,28,144,52,16,228,22,56,197,171,169,120,61,85,175,102,26,117,108,175,153,88,45,133,234,149,96,233,132,58,75,117,159,1,108,58,48,149,28,93,63,9,46,245,83,15,218,129,234,112,131,90,21,162,6,183,
229,132,255,219,202,224,110,37,62,148,114,82,85,132,13,194,137,175,135,11,3,206,104,105,42,60,189,33,173,71,56,141,153,74,164,239,63,115,191,212,249,74,237,183,255,246,239,166,82,153,183,223,122,29,179,
251,242,205,165,245,181,229,165,165,235,236,55,92,91,93,181,143,132,217,190,29,216,224,4,25,160,146,45,2,163,5,155,243,19,146,74,26,24,186,78,83,156,2,80,168,72,85,236,251,40,93,174,3,21,247,119,55,34,
77,43,210,54,81,230,26,202,65,204,69,71,46,173,84,145,96,117,214,202,171,139,106,31,165,62,188,251,145,235,10,105,117,245,125,117,244,241,20,154,59,157,32,204,20,247,27,49,54,229,176,57,135,118,0,27,43,
203,171,75,75,55,9,230,75,3,95,255,250,111,125,114,229,202,173,91,75,107,107,43,56,22,113,233,19,97,24,196,232,18,101,108,109,190,228,214,40,32,138,71,52,101,145,218,84,153,227,36,225,4,49,9,51,161,138,
63,178,51,32,131,212,242,246,179,28,162,87,151,137,229,227,162,90,247,1,93,15,220,240,232,128,240,32,94,87,252,14,153,216,67,187,229,191,55,176,186,229,123,144,50,222,70,154,110,21,216,87,150,176,199,
113,72,230,71,198,255,8,155,86,182,26,218,195,41,227,31,30,237,179,72,38,209,214,111,221,90,89,60,118,226,228,201,147,63,249,241,143,174,93,187,74,51,1,38,70,136,40,106,156,181,108,159,112,162,63,37,92,
162,43,25,203,240,157,11,108,93,217,92,73,159,174,139,241,153,233,88,58,223,72,229,146,217,66,42,91,96,5,161,219,69,198,115,200,95,133,17,10,185,113,171,119,236,233,186,109,9,24,52,66,122,107,158,37,120,
98,249,128,30,123,9,93,41,99,91,22,73,3,107,29,30,30,142,79,155,252,128,220,156,207,106,79,70,25,125,59,25,225,237,129,132,116,163,55,226,190,128,213,49,223,187,28,216,173,122,251,42,6,28,234,204,36,36,
137,198,106,180,93,2,172,52,71,244,90,151,204,153,51,108,200,36,56,1,152,110,46,221,224,11,228,106,234,76,218,125,183,130,147,32,104,84,0,170,17,34,77,8,125,169,84,102,224,89,175,86,102,102,102,56,23,
105,27,157,42,63,153,46,204,2,175,82,45,206,78,31,172,22,236,232,207,102,82,60,142,125,139,212,75,168,114,237,228,234,162,246,226,142,156,89,48,198,83,144,142,19,147,147,218,130,166,113,168,116,98,131,
20,30,158,232,250,113,193,171,157,63,237,33,189,121,213,141,190,91,120,239,220,198,192,50,254,32,177,16,7,50,159,34,201,0,146,36,69,6,189,62,63,51,51,79,235,178,0,43,155,203,210,21,34,201,80,173,42,88,
183,52,182,212,121,127,92,117,92,169,80,73,75,3,136,60,107,234,19,245,50,39,143,228,38,38,23,78,126,234,201,231,95,201,45,60,184,180,86,218,220,220,172,214,43,236,232,143,203,112,95,175,50,33,153,204,
56,76,232,237,39,43,178,80,33,28,248,121,16,79,224,0,75,142,220,229,91,81,116,219,124,246,53,147,205,128,51,104,13,79,172,55,164,108,200,75,160,102,250,162,82,7,110,95,152,232,70,220,45,60,120,78,7,239,
168,205,21,118,96,129,11,82,131,186,182,129,141,106,99,224,149,73,177,162,33,131,30,36,181,125,229,22,235,70,1,19,177,224,195,157,187,236,250,47,55,170,6,16,180,46,61,36,80,136,167,232,236,202,147,105,
148,247,242,169,19,199,178,115,167,226,233,201,74,172,180,120,234,145,205,91,55,98,37,214,15,58,241,166,245,57,177,108,33,199,233,110,206,172,37,92,243,80,95,62,246,199,210,165,110,109,110,163,157,177,
62,154,110,149,207,118,50,152,224,65,139,139,11,160,249,214,173,91,192,29,122,160,137,166,216,177,249,137,242,25,222,101,207,24,88,8,8,113,159,207,173,170,119,195,20,110,218,125,181,198,231,229,52,57,
35,205,9,51,196,58,43,226,117,44,105,6,117,74,93,35,84,44,164,145,50,86,115,198,5,2,234,124,179,85,7,153,22,88,194,204,102,216,106,109,50,155,166,35,189,250,225,185,51,143,191,176,148,136,127,136,209,
148,67,72,26,101,152,158,76,51,86,224,171,99,13,167,104,249,70,23,166,113,60,193,129,38,158,43,76,0,214,92,62,7,218,121,40,3,206,199,30,253,52,171,165,223,123,239,61,27,118,96,185,181,111,32,88,194,193,
185,142,60,176,28,170,104,15,32,226,90,133,249,105,84,99,137,1,13,249,56,51,50,129,136,218,96,26,135,125,170,137,196,228,250,234,42,10,53,148,204,27,162,86,89,235,210,226,46,135,70,54,151,41,110,85,178,
153,92,58,153,169,86,182,55,150,151,63,117,252,83,191,120,235,237,107,151,62,212,65,92,155,203,36,205,34,3,221,44,56,139,7,183,75,204,255,160,152,235,100,74,247,116,245,197,202,138,15,38,230,80,176,200,
190,190,184,48,95,152,152,100,55,209,169,251,238,63,113,108,241,218,213,79,120,1,232,10,41,33,93,33,226,19,122,235,19,239,161,124,178,194,135,215,209,214,177,154,168,66,98,105,181,40,13,3,170,232,61,104,
93,132,18,90,23,3,195,237,82,137,46,18,41,85,200,229,232,148,110,222,228,228,210,90,33,159,55,217,66,111,5,242,56,217,155,15,103,2,68,22,194,23,114,136,149,250,236,228,12,75,3,111,94,189,158,99,121,96,
105,163,178,181,180,116,249,124,188,178,49,141,96,212,17,35,21,62,11,156,200,176,250,190,152,70,35,115,34,208,84,43,215,54,228,45,53,127,113,113,158,3,119,95,122,233,87,40,192,51,159,249,236,83,79,61,
243,218,171,223,121,255,253,119,103,103,103,56,161,126,105,105,137,210,82,24,80,133,120,163,132,184,176,105,247,235,239,150,188,91,120,239,252,135,23,88,112,81,191,160,61,122,215,84,177,45,250,86,170,
102,67,184,63,180,174,12,242,52,85,149,49,34,203,106,232,251,56,60,178,180,93,70,0,241,151,228,139,11,11,172,156,65,148,49,94,131,24,36,161,196,179,124,126,97,97,17,53,159,15,214,129,199,87,94,121,229,
242,229,79,86,151,150,81,204,177,184,174,111,172,67,152,197,134,213,216,206,196,93,175,201,74,7,86,213,208,173,165,19,152,196,242,28,118,138,95,63,230,165,77,108,38,27,177,228,241,227,11,159,122,224,33,
22,132,61,250,232,19,11,139,139,79,63,243,204,127,249,207,255,9,3,199,201,19,199,103,103,167,153,202,164,168,44,216,159,95,152,103,119,36,101,115,218,148,199,150,85,176,85,77,85,125,111,231,1,20,73,6,
99,90,76,118,140,114,57,133,15,136,208,219,147,6,174,43,148,165,210,245,5,189,57,225,170,168,139,134,249,189,73,131,88,137,38,97,145,103,184,68,50,79,154,79,227,50,156,147,37,32,12,79,57,155,207,177,61,
21,130,155,75,215,233,250,38,88,249,158,98,180,135,0,171,78,78,77,146,83,190,52,113,108,225,228,241,99,199,159,125,254,243,63,253,201,79,86,110,174,28,59,126,234,249,23,191,50,57,123,98,107,109,253,187,
175,189,186,189,177,13,78,231,38,242,167,79,223,183,244,243,27,233,172,54,141,113,186,41,246,120,108,165,181,98,149,245,15,165,109,9,155,169,233,57,105,238,213,82,188,22,43,109,99,246,202,62,246,228,211,
31,126,244,241,125,167,30,152,93,56,249,228,147,143,254,209,31,253,225,194,177,99,108,252,47,209,193,222,90,153,152,152,196,150,187,189,181,141,159,15,90,171,70,59,92,112,188,105,214,218,213,184,89,197,
102,80,183,63,214,147,26,119,160,225,173,117,89,202,224,39,238,184,111,192,48,192,65,71,128,6,88,99,221,229,166,25,46,150,54,7,31,202,135,113,107,183,199,28,213,240,29,254,239,174,33,236,192,156,158,206,
100,48,37,96,202,98,62,7,0,9,132,76,243,101,178,213,122,117,233,198,181,141,227,39,54,55,214,54,182,75,191,250,242,87,103,230,22,64,101,165,88,62,113,226,228,226,201,227,175,255,236,245,205,149,226,175,
191,242,194,155,111,191,207,180,243,63,249,131,127,241,202,43,191,254,31,255,253,191,123,239,236,217,66,97,242,230,173,101,76,237,12,26,201,176,162,165,96,13,86,249,73,68,98,228,79,38,48,93,108,172,111,
112,230,41,221,100,169,86,121,238,197,23,78,221,119,230,177,39,30,251,193,143,255,195,51,207,60,247,224,67,143,172,174,173,159,63,127,14,113,56,61,53,49,51,85,224,75,101,156,236,181,190,182,206,84,166,
175,4,77,239,253,7,246,24,170,44,163,29,70,185,156,41,45,72,195,144,130,80,133,0,37,130,43,162,140,110,218,40,225,134,8,5,65,101,48,112,192,218,169,79,79,246,64,166,226,187,23,165,39,225,94,145,122,27,
69,163,125,247,104,196,117,237,49,68,59,102,165,40,22,35,89,189,43,245,106,17,227,100,245,107,127,243,235,216,54,217,173,90,220,216,222,222,220,152,154,152,124,228,209,199,151,110,222,194,42,95,226,131,
191,165,10,86,9,212,160,111,189,246,157,249,99,139,236,206,96,137,196,151,190,248,165,231,62,255,185,159,255,252,167,23,46,156,135,223,116,157,52,2,255,41,60,198,48,89,17,82,234,79,217,44,132,22,135,118,
191,93,222,154,159,157,251,242,87,94,62,113,226,190,215,223,248,89,109,11,235,125,133,239,147,125,251,91,127,206,122,158,231,159,127,177,81,173,252,241,127,251,67,86,29,154,206,142,10,239,230,194,105,
93,62,99,189,243,17,141,221,117,238,147,163,187,18,33,202,119,37,227,70,115,3,250,218,35,216,130,97,50,184,200,174,11,142,90,138,42,213,106,253,35,175,230,96,100,87,174,247,246,134,82,27,100,34,197,176,
112,127,117,144,218,85,249,8,125,255,183,228,210,208,166,123,26,7,60,129,170,233,169,105,204,160,172,233,3,9,88,207,153,46,126,250,137,39,255,225,223,255,7,200,127,90,154,240,165,235,215,214,87,87,104,
77,36,28,102,241,242,118,9,37,234,169,167,159,90,60,118,28,89,82,200,51,130,156,100,253,224,141,165,155,95,254,210,151,127,245,43,47,163,126,1,44,56,15,168,232,67,172,87,209,187,157,76,114,78,4,11,158,
115,249,252,167,31,121,84,171,104,98,241,251,78,221,143,210,246,215,63,252,33,197,66,186,113,112,215,231,63,255,121,102,145,222,127,247,236,95,126,255,123,8,42,148,42,165,117,71,146,160,165,241,99,12,
209,226,135,171,140,80,225,127,253,51,162,73,73,202,93,206,221,83,20,2,193,155,222,6,12,200,216,100,157,98,152,225,229,227,141,116,123,121,81,216,177,158,48,234,209,111,87,22,3,112,211,228,135,196,238,
238,95,192,42,209,180,98,247,91,100,75,24,73,5,92,129,84,62,139,18,165,141,206,235,235,107,244,140,219,91,69,186,171,114,169,178,48,55,251,79,255,209,63,190,240,222,121,70,99,124,108,135,149,11,171,203,
183,22,231,231,46,94,252,96,110,97,14,235,65,58,145,68,152,125,230,153,207,174,111,109,210,198,147,88,7,182,139,128,104,102,122,230,250,141,165,75,151,47,111,23,183,200,16,84,225,192,21,176,160,0,116,
184,252,227,179,137,15,61,252,233,71,31,123,242,137,39,158,102,85,51,130,242,196,137,83,172,95,189,126,253,26,242,97,110,118,142,179,147,126,252,163,31,98,125,93,89,94,126,243,141,55,176,128,144,156,215,
192,137,43,154,84,83,233,12,12,35,53,58,196,219,214,187,204,107,33,237,10,129,101,207,102,32,204,15,235,110,138,245,251,152,136,25,173,112,134,185,251,229,82,204,88,141,188,83,35,59,71,111,130,168,87,
227,179,179,94,91,165,139,180,43,141,248,219,127,235,239,20,183,138,31,126,116,225,225,135,30,250,252,231,158,253,232,131,11,24,29,120,97,223,62,251,206,11,47,125,249,230,141,155,200,155,197,197,99,191,
244,217,207,45,175,175,162,45,161,218,51,123,93,220,72,240,105,49,254,189,249,246,91,188,9,152,15,220,148,30,121,171,207,82,119,136,25,172,86,127,224,129,135,142,159,224,203,137,179,44,15,99,193,196,228,
228,212,169,147,167,94,123,237,53,245,55,124,249,188,94,187,244,209,69,244,100,142,193,249,241,143,126,178,176,56,199,248,20,73,137,149,65,197,116,19,74,102,75,51,176,186,122,28,252,66,142,166,24,40,235,
192,81,22,222,6,134,195,236,139,227,65,26,193,34,117,85,0,254,210,189,183,88,232,94,29,210,233,253,9,146,15,174,215,84,197,86,241,15,179,156,150,39,87,32,128,161,1,213,97,110,110,238,229,151,95,158,155,
159,123,248,225,135,115,153,204,243,207,189,128,224,249,206,107,175,97,122,120,245,213,87,191,250,213,95,67,226,48,229,119,233,202,165,229,213,91,116,124,55,111,221,196,226,254,240,163,143,242,193,214,
171,215,174,161,42,177,53,131,179,144,40,229,196,228,196,185,243,231,223,123,231,189,124,110,210,116,92,26,129,31,45,66,71,166,230,137,39,238,187,239,244,242,242,90,169,92,89,93,93,67,254,48,20,192,148,
176,190,182,86,173,212,82,217,244,230,250,250,210,141,235,171,43,43,231,207,189,127,223,169,19,136,10,6,19,116,214,24,174,232,16,241,168,9,145,178,132,31,146,3,44,17,84,249,140,85,112,176,213,92,136,33,
193,203,219,165,41,121,126,230,16,158,153,12,133,193,13,1,176,90,202,161,175,224,33,123,12,91,236,22,68,192,208,78,95,252,27,95,124,244,211,143,208,111,89,203,61,254,216,19,231,206,159,99,219,87,110,162,
240,214,155,111,94,248,224,131,23,191,240,2,95,218,65,152,204,206,207,173,174,44,79,77,79,78,206,76,221,119,230,12,235,16,150,156,249,116,118,102,134,198,102,199,34,67,203,239,125,255,123,188,230,91,156,
194,197,155,46,36,185,218,224,69,71,129,251,137,196,204,236,60,32,153,158,154,65,20,49,2,56,115,230,204,249,247,223,103,220,55,63,55,91,200,103,39,38,242,175,126,231,207,223,127,247,29,122,106,190,91,
125,245,234,21,70,15,38,162,12,79,202,208,173,255,57,100,166,52,179,243,239,178,192,198,13,163,99,39,183,12,126,77,4,2,49,21,70,91,7,132,50,176,133,109,111,111,96,81,110,220,157,41,247,94,185,218,11,46,
249,44,246,81,126,84,69,87,28,105,181,52,12,126,106,69,46,86,66,170,71,123,217,45,195,96,110,237,1,188,64,16,16,162,40,247,69,113,187,133,128,229,3,211,51,179,167,78,221,247,208,67,15,161,183,115,139,
220,186,116,233,18,22,44,228,1,203,10,88,53,250,206,187,103,245,224,60,179,44,217,111,127,251,219,191,244,236,179,133,169,137,249,99,104,216,11,103,223,126,11,197,107,163,180,245,244,179,159,65,59,163,
84,83,147,19,168,127,243,243,179,116,125,140,221,174,93,191,230,206,167,73,232,12,65,189,228,20,41,206,192,144,37,206,167,79,159,65,106,49,217,71,209,192,180,134,117,141,58,242,242,187,223,125,141,211,
117,57,85,240,185,231,126,249,255,254,248,175,217,43,75,121,110,220,184,206,202,85,70,129,116,130,212,34,196,19,126,156,213,244,80,175,150,39,87,181,190,113,15,221,28,24,51,8,213,40,81,141,192,251,165,
67,123,8,147,10,233,174,138,169,106,65,255,128,185,54,12,11,52,252,119,115,248,178,50,215,27,188,24,156,109,101,35,94,244,95,192,132,36,166,26,110,84,87,129,5,78,24,51,115,194,146,19,57,16,2,1,175,17,
76,96,131,188,94,169,92,150,175,19,30,63,126,252,155,223,252,38,67,184,43,87,62,97,94,112,241,216,49,50,249,206,255,254,14,201,167,167,103,54,86,215,32,195,116,126,246,221,119,80,25,166,102,166,212,3,
109,110,253,197,255,249,238,239,127,243,239,161,109,127,244,241,71,239,190,115,86,135,123,39,227,151,175,93,185,112,225,252,202,202,45,154,97,121,121,137,181,203,132,111,109,177,243,66,38,69,186,88,52,
108,70,148,154,124,196,154,158,201,112,18,9,159,31,163,84,215,174,94,101,183,25,203,83,217,7,155,159,204,191,249,198,47,206,158,125,227,198,245,43,116,41,155,28,84,178,185,6,186,129,141,235,98,88,227,
160,245,174,161,19,115,238,160,243,120,213,96,22,227,2,216,135,153,176,145,90,128,102,214,15,241,112,84,190,106,185,66,67,168,48,116,148,106,175,193,179,99,33,112,41,49,194,137,191,238,95,147,109,8,34,
189,152,84,198,237,66,70,120,108,215,75,147,51,19,216,7,48,19,0,5,166,207,48,29,65,189,190,190,126,243,38,171,138,155,142,198,163,194,176,131,251,249,249,5,174,132,48,167,203,206,230,111,124,227,27,79,
61,245,212,247,191,247,253,43,159,124,194,40,12,91,118,185,88,226,61,188,112,241,226,243,47,60,255,39,127,242,63,79,205,76,95,252,232,2,106,197,212,236,116,42,147,158,152,158,44,110,110,114,184,242,47,
127,225,197,199,158,120,114,149,117,239,55,87,174,94,253,228,236,249,115,63,248,171,191,226,99,98,169,120,114,125,115,227,127,253,217,159,188,245,230,235,152,188,110,92,187,186,177,182,142,152,97,165,
3,168,2,2,148,19,73,38,178,245,117,132,25,139,189,222,63,247,238,230,230,250,71,31,93,160,77,216,184,248,193,7,231,150,174,175,1,163,106,21,115,21,22,51,22,198,52,15,146,64,86,117,20,76,212,142,74,29,
22,186,44,163,118,180,234,149,80,103,200,142,91,45,65,163,49,210,57,70,129,216,249,36,192,88,235,72,213,88,129,33,244,49,33,229,26,241,208,202,116,56,117,163,248,192,74,115,30,210,71,164,149,8,103,116,
31,245,73,198,78,204,147,77,79,231,221,39,82,153,241,96,108,143,220,162,98,208,0,23,28,2,2,196,208,108,132,80,30,150,20,51,139,199,232,29,89,115,255,253,216,135,22,222,57,251,238,250,198,6,234,13,111,
63,185,209,132,44,38,94,190,181,12,61,243,128,104,199,216,156,120,16,122,55,82,132,193,127,38,83,96,20,196,6,252,135,30,122,240,163,115,231,110,221,188,201,6,174,197,19,167,126,255,155,223,252,139,87,
255,226,220,187,231,160,228,21,94,89,91,47,36,211,91,27,155,104,179,96,157,89,106,123,119,121,167,51,238,136,239,114,173,140,209,75,34,180,198,107,144,6,106,32,184,144,159,100,59,63,205,84,40,240,13,206,
234,141,165,43,168,39,229,34,253,59,203,111,182,221,2,252,12,173,88,143,1,119,146,106,193,42,3,140,195,225,115,167,92,196,50,195,148,233,130,14,73,46,72,157,6,134,6,90,5,20,209,205,77,20,178,172,185,200,
102,178,107,43,235,229,173,18,13,148,159,156,144,249,20,148,107,148,8,59,15,15,236,157,138,186,255,48,215,57,183,80,165,161,19,22,57,254,152,205,151,236,212,193,241,18,167,82,171,43,107,52,21,29,59,106,
163,169,86,180,129,180,72,92,146,133,3,26,151,33,168,112,0,142,48,18,178,192,87,98,73,33,58,173,143,142,149,252,105,107,24,4,49,108,67,158,171,249,193,171,12,226,4,2,104,50,169,96,245,171,150,203,19,217,
116,174,80,64,43,103,210,39,197,12,76,34,133,149,11,92,243,226,86,138,69,212,48,30,204,120,175,84,44,163,150,147,9,205,192,24,9,17,11,13,26,34,241,204,34,243,24,40,201,147,229,18,74,46,20,177,211,191,
150,209,58,135,10,199,193,49,207,230,116,69,122,112,114,200,33,144,18,41,170,44,37,45,197,113,38,149,187,0,44,216,15,192,154,18,71,72,193,110,40,29,87,175,187,12,165,46,110,114,2,108,77,111,174,172,87,
57,1,42,153,2,88,0,15,209,101,146,97,239,213,13,251,135,198,237,165,112,213,113,239,134,108,149,52,188,80,227,212,114,98,220,139,208,220,15,136,121,110,122,122,74,96,66,158,57,7,68,144,97,8,39,190,23,
71,33,24,64,25,164,0,16,205,131,21,17,15,58,50,126,114,68,174,160,171,201,112,133,53,89,176,211,198,155,124,161,64,114,176,197,3,55,183,182,96,33,10,131,54,30,242,205,1,237,19,140,147,55,250,29,94,134,
114,176,151,233,63,178,101,91,69,38,157,194,218,132,25,147,228,0,136,252,57,12,144,98,83,12,128,69,37,40,186,89,178,36,147,74,21,22,38,32,26,21,18,67,101,212,216,130,149,133,236,201,224,173,81,53,99,40,
85,104,84,28,1,65,241,216,39,230,212,23,171,191,107,243,219,99,113,215,212,60,1,39,88,217,197,8,93,40,53,50,219,153,62,21,42,37,74,243,72,160,140,5,211,108,106,99,40,8,171,29,2,53,198,162,69,6,17,88,72,
14,157,86,44,25,229,4,149,161,137,21,154,200,134,84,146,129,27,251,20,136,224,216,108,118,104,185,174,80,124,55,108,193,10,58,55,244,116,110,129,11,88,33,202,60,8,42,36,153,196,155,219,25,129,181,137,
190,207,245,183,13,183,157,144,101,122,89,192,4,44,180,115,65,249,164,24,234,176,242,189,194,193,238,236,173,65,57,77,196,52,175,167,33,79,60,159,211,56,14,100,40,135,74,37,67,239,13,220,40,55,8,227,156,
15,103,18,227,97,14,181,156,6,24,103,246,81,61,58,8,163,11,116,179,108,0,142,10,210,130,212,5,131,42,199,79,2,52,6,33,168,1,60,157,34,145,79,42,153,197,207,50,84,158,174,126,70,19,192,82,99,172,197,15,
253,234,129,213,124,68,235,126,231,65,238,241,20,140,24,117,117,72,81,117,140,113,20,80,189,69,188,106,114,200,181,193,219,98,15,14,40,22,2,67,5,116,229,183,33,33,253,9,168,162,153,233,208,214,214,86,
249,6,189,94,104,72,91,206,58,65,174,64,10,12,129,66,114,48,192,225,7,109,32,10,36,64,142,65,1,89,197,193,201,180,25,56,112,131,24,73,35,250,74,61,212,117,142,240,12,80,82,10,136,97,153,94,71,122,129,
68,28,187,36,165,74,196,147,152,166,84,200,116,10,100,231,147,44,50,230,172,82,222,94,225,76,31,219,209,19,133,97,117,103,137,100,201,141,158,64,53,64,132,158,119,195,122,97,144,7,92,24,247,145,63,17,
44,108,38,128,126,152,80,74,129,81,8,36,81,128,84,58,65,245,121,61,0,50,37,164,10,118,109,85,253,48,255,90,246,46,71,67,87,179,75,36,92,63,9,42,215,27,210,70,50,236,16,160,159,154,75,112,210,13,94,88,
74,9,117,63,56,142,230,163,68,52,9,204,117,94,225,74,42,10,10,144,124,20,153,139,248,75,109,64,134,4,201,62,74,47,169,65,54,46,69,51,29,127,90,96,234,144,17,229,32,84,79,2,145,98,152,44,56,142,78,130,
159,34,225,151,254,1,91,85,36,49,147,64,253,49,42,71,10,9,101,150,87,17,210,95,154,94,110,244,6,53,95,0,84,20,213,58,198,201,242,250,130,129,136,220,249,71,26,104,41,141,203,117,95,213,85,22,251,118,238,
193,122,100,203,121,175,60,142,131,186,202,207,0,80,27,199,245,29,53,190,59,196,110,74,252,204,79,83,167,67,155,10,104,21,226,16,254,82,100,176,131,0,32,47,26,206,112,224,38,64,197,91,187,229,138,18,227,
218,217,241,161,223,199,234,85,178,28,250,76,97,32,148,160,195,185,151,144,55,22,47,72,2,239,205,183,146,63,116,4,174,180,130,137,72,85,212,93,206,90,71,87,243,53,255,152,88,80,42,210,57,97,109,20,22,
174,76,196,2,194,34,217,237,202,251,112,111,92,249,154,133,220,157,179,43,131,83,230,169,48,81,106,28,198,137,40,151,8,248,106,25,206,214,56,246,139,206,129,241,200,238,148,247,254,142,87,161,9,166,22,
176,40,19,111,169,73,4,53,154,251,47,217,37,134,239,219,132,67,183,216,94,201,142,129,70,230,163,218,165,26,33,208,0,8,67,170,81,34,106,219,243,239,39,196,242,239,8,250,142,129,253,228,121,231,104,168,
172,170,47,84,169,105,224,41,211,150,216,73,193,19,214,25,222,189,193,3,150,142,36,19,96,236,29,21,120,212,118,92,232,142,8,109,189,201,220,186,53,178,138,191,147,206,26,149,18,120,132,69,158,230,91,221,
112,230,111,33,179,36,22,30,73,229,111,155,45,212,34,38,156,103,129,78,203,167,219,67,125,242,123,232,81,217,132,42,153,227,213,92,82,21,164,179,163,137,210,130,122,231,6,202,73,160,184,98,58,206,194,
100,233,32,78,243,80,49,17,83,16,160,114,241,19,153,85,232,206,87,32,132,75,248,52,152,43,254,58,52,0,160,16,67,22,30,18,119,244,251,36,222,99,192,242,196,221,30,237,9,238,178,39,82,30,90,64,179,57,188,
239,58,97,39,198,104,6,51,28,33,3,39,177,90,229,214,43,128,31,96,201,227,152,231,212,29,121,91,29,162,139,57,168,196,178,7,209,138,46,111,61,203,60,125,94,13,55,150,10,63,176,32,43,159,91,152,137,197,
134,33,161,223,39,193,67,38,190,24,97,254,33,253,160,249,53,152,130,115,234,89,196,73,180,78,166,8,176,3,15,36,176,40,33,237,221,146,91,48,92,234,148,33,202,53,159,131,156,171,141,129,108,127,144,56,72,
211,248,230,183,196,52,191,133,132,225,4,226,58,230,110,40,233,24,101,73,52,10,118,167,199,64,233,178,233,154,85,199,76,238,114,160,149,57,168,187,244,19,128,69,225,233,72,164,111,97,68,188,203,101,218,
251,113,26,199,58,100,57,213,24,122,153,24,154,33,194,155,117,25,78,121,87,27,236,157,225,109,83,4,28,220,201,139,71,91,184,239,194,8,129,177,118,139,103,135,180,167,15,171,27,144,130,132,220,112,106,
155,86,223,218,158,14,130,187,83,229,246,71,183,135,168,36,12,170,232,1,93,225,49,184,107,222,73,203,0,101,156,81,101,218,211,220,195,16,21,86,37,53,94,187,174,65,186,84,131,157,153,252,176,80,95,188,
120,145,111,113,201,172,197,124,136,206,189,110,86,172,189,204,214,198,180,156,242,115,213,60,64,171,68,248,179,103,14,208,123,168,89,145,12,40,237,197,179,144,144,216,40,247,124,68,183,172,238,114,120,
147,51,52,128,27,72,161,104,97,213,101,102,7,108,49,41,50,112,202,59,197,100,0,104,157,182,20,117,19,73,241,248,23,94,124,241,15,254,217,31,176,161,96,115,125,67,211,55,238,152,117,77,234,185,78,164,227,
133,54,163,242,230,14,133,233,125,54,185,100,78,224,14,229,209,3,155,9,54,210,230,143,183,151,82,74,105,81,155,137,237,3,85,104,103,210,149,113,221,149,138,210,9,250,252,97,245,203,233,211,247,191,247,
222,251,78,193,170,179,88,133,3,140,169,3,211,130,86,254,176,34,132,219,173,111,95,95,199,62,193,225,233,125,182,7,78,104,89,129,114,10,227,179,53,143,47,103,24,190,223,7,133,105,239,166,31,206,0,29,122,
64,30,42,205,132,78,144,73,94,86,106,208,149,176,102,206,51,238,110,150,169,199,179,124,121,76,125,82,199,98,22,7,173,148,210,177,159,72,33,38,13,217,66,67,83,177,248,83,219,139,29,8,195,62,197,231,143,
104,195,89,139,134,77,219,127,227,89,121,250,167,247,88,241,21,177,194,132,79,39,196,103,24,33,11,163,124,45,6,211,67,201,219,129,197,196,168,112,165,85,129,131,230,76,176,170,84,194,11,175,2,23,160,133,
7,5,139,66,219,27,194,244,109,90,167,181,48,221,107,178,77,214,200,118,71,251,17,72,62,29,97,167,135,244,225,60,8,250,160,149,112,237,72,102,197,176,168,48,195,208,79,108,228,182,99,86,3,27,72,75,216,
120,10,207,192,45,155,209,212,141,153,68,28,151,157,150,164,21,62,104,133,172,176,115,75,151,180,232,138,85,200,180,32,109,232,199,133,190,69,219,219,134,16,139,245,81,158,248,14,53,82,143,252,125,25,
34,143,238,145,36,66,57,32,183,20,24,254,115,113,47,175,107,51,252,26,182,234,85,31,56,96,25,82,192,147,13,15,37,108,93,95,200,161,66,44,188,116,29,91,109,178,80,216,218,218,164,232,44,44,97,48,98,140,
246,13,227,61,22,174,138,6,192,66,116,113,59,32,109,51,212,197,48,62,11,88,166,139,184,23,29,137,101,166,161,1,4,22,47,129,123,15,28,215,53,68,108,46,28,96,115,145,246,168,128,57,116,195,41,14,18,102,
29,127,151,245,73,190,206,214,114,118,75,103,4,164,238,52,176,12,181,246,68,123,122,123,136,133,251,216,144,56,140,26,112,127,171,216,212,207,189,168,14,88,254,149,37,182,179,78,112,15,107,21,22,200,23,
15,45,30,5,139,82,105,17,104,203,118,202,45,53,49,26,175,69,133,74,149,69,81,115,67,149,120,208,18,87,120,44,48,172,169,127,156,145,113,245,33,33,217,158,126,159,202,63,110,207,36,67,71,64,29,213,159,
56,35,22,218,186,202,31,96,105,240,44,239,14,43,198,101,74,110,111,0,160,81,45,220,36,143,60,26,43,54,135,29,33,140,44,21,81,4,226,240,24,50,72,130,161,203,183,177,197,218,173,114,107,169,246,132,227,
247,100,68,225,252,173,101,62,190,118,224,0,246,119,230,115,92,243,120,137,53,112,192,162,45,173,117,205,131,223,99,200,16,99,21,179,88,187,26,80,34,21,246,169,64,6,100,222,25,153,183,65,116,203,223,200,
194,39,70,242,239,1,56,158,21,33,62,194,183,246,234,171,223,112,246,81,106,234,94,255,1,220,176,234,26,161,91,219,120,184,64,5,141,221,114,109,111,102,98,219,3,73,5,10,53,2,112,198,45,104,112,38,168,220,
99,117,33,196,39,140,68,121,26,35,11,111,71,217,79,59,104,169,159,231,154,227,197,192,73,172,110,45,20,182,55,52,212,130,16,60,108,49,176,91,95,47,11,7,19,120,184,90,184,93,9,193,84,225,3,141,50,204,13,
140,18,104,196,70,230,105,32,59,128,243,185,29,32,237,80,36,65,62,185,46,70,133,149,244,226,134,113,33,38,248,65,43,189,199,135,21,140,134,161,129,77,50,133,109,76,160,17,68,232,9,180,16,174,230,16,78,
120,8,183,228,108,197,9,111,201,217,103,101,168,130,12,103,52,246,136,241,181,7,7,108,147,136,222,113,167,94,129,45,77,148,112,218,120,143,52,131,16,69,3,211,204,214,246,30,97,96,133,178,113,53,88,64,
208,173,168,36,199,133,177,225,45,126,242,244,33,62,127,232,125,96,152,118,236,143,112,192,189,175,10,131,199,174,63,84,0,139,102,104,15,189,157,17,234,123,123,27,182,168,149,205,174,132,227,84,92,87,
96,252,148,19,191,97,206,5,55,43,98,81,237,181,8,19,18,235,201,44,188,157,190,119,200,190,82,249,103,245,206,115,184,98,197,1,116,43,97,74,77,162,69,88,218,136,27,227,200,19,233,19,46,112,8,106,212,173,
156,251,109,51,163,111,207,205,66,58,230,214,78,12,89,123,96,111,38,118,204,185,119,146,193,143,5,71,28,149,33,251,162,118,137,131,178,122,38,206,6,224,234,252,220,226,160,119,133,135,206,220,253,2,130,
2,68,96,100,16,233,6,148,3,228,127,232,117,188,155,25,106,197,28,54,69,237,44,148,53,139,5,79,217,120,70,199,221,222,205,66,236,247,89,183,211,72,221,210,118,3,4,101,235,29,101,25,246,160,177,218,237,
73,176,95,38,12,58,61,226,138,221,219,66,84,131,109,208,28,50,193,233,132,250,124,232,192,150,59,68,70,56,118,235,179,192,251,109,224,61,233,247,36,232,179,96,71,141,140,101,75,44,123,71,193,226,12,31,
167,254,114,148,33,231,162,12,46,176,250,108,128,16,127,97,146,67,199,65,159,18,43,44,195,136,248,57,151,2,157,93,67,39,78,241,212,49,43,41,140,14,131,183,208,175,213,26,33,50,108,232,215,138,185,173,
191,224,195,187,61,51,130,210,104,218,61,123,166,29,5,2,55,159,35,157,93,231,205,49,48,140,197,248,86,163,45,152,25,104,137,21,98,203,55,109,164,193,232,37,35,33,118,123,251,88,180,39,182,63,215,66,194,
178,117,44,192,136,4,202,26,170,227,10,65,149,38,118,114,133,156,83,225,7,117,174,208,36,43,109,35,107,21,82,86,162,182,37,60,8,107,134,42,190,189,225,149,34,152,186,182,91,127,237,19,112,145,108,67,248,
122,203,153,207,51,244,140,30,224,220,9,77,2,150,90,40,203,233,174,58,219,232,78,118,133,180,77,164,121,172,1,96,189,119,97,147,152,159,145,5,63,183,104,52,193,90,119,109,48,228,215,72,112,250,231,137,
147,167,88,1,207,71,219,32,161,117,57,172,140,43,83,202,228,214,79,206,237,207,138,132,88,105,45,55,144,228,193,100,30,12,253,56,67,21,9,35,100,61,106,20,121,74,63,183,190,70,158,216,241,178,51,63,61,
205,189,240,240,206,211,99,196,117,102,107,172,49,57,61,3,176,216,77,193,78,157,123,208,21,118,68,155,49,5,200,51,203,226,252,120,237,29,192,195,235,16,231,11,51,156,64,156,204,100,249,88,22,49,172,245,
211,45,235,26,2,118,146,115,123,147,16,239,209,16,208,70,141,11,134,12,79,64,18,11,33,79,159,156,16,43,188,127,138,143,34,97,88,47,79,224,51,220,151,39,204,202,18,250,71,239,43,159,59,77,220,84,218,17,
85,174,67,84,33,57,82,149,213,111,152,30,238,244,179,247,155,191,77,106,210,76,32,70,71,187,130,43,57,206,202,46,114,4,227,220,204,244,218,42,223,153,41,81,1,164,7,3,16,201,144,96,150,218,55,124,216,54,
126,149,95,55,28,52,159,209,90,135,163,231,57,140,34,162,194,124,204,143,0,11,243,129,216,90,157,112,8,140,134,16,28,100,92,45,243,253,94,45,159,48,213,129,179,10,51,57,116,191,118,73,9,88,90,55,195,146,
113,100,122,198,241,96,224,128,21,212,156,38,17,186,112,252,185,114,249,74,58,151,93,156,159,165,19,47,151,248,76,151,56,207,166,66,139,53,4,0,32,146,91,139,218,114,26,110,69,231,2,173,97,124,7,23,60,
168,233,53,74,174,56,178,2,22,118,181,232,48,57,4,190,153,33,227,150,108,113,150,16,122,2,113,230,105,230,222,229,143,207,39,140,39,159,240,214,252,246,80,187,182,199,222,155,16,53,17,167,100,33,212,249,
211,208,55,180,179,85,78,100,69,11,190,131,155,41,58,114,167,119,253,3,118,146,154,174,16,114,11,163,6,38,24,98,27,27,27,120,57,231,146,143,229,113,190,173,65,79,116,174,177,105,39,115,97,3,248,146,16,
101,205,79,72,196,133,57,16,229,112,34,160,144,132,171,197,250,180,220,90,72,152,9,177,0,209,135,144,16,26,95,24,151,162,175,139,61,174,35,169,47,73,15,154,142,9,239,80,160,36,85,171,1,152,214,225,208,
242,116,50,157,231,228,103,14,232,190,67,143,236,152,109,55,118,88,27,144,132,66,210,152,150,214,29,117,105,97,10,224,172,108,190,144,187,182,186,34,164,49,207,169,111,11,54,41,137,245,57,251,172,76,96,
88,75,115,133,6,169,198,213,19,224,15,157,207,129,132,248,185,2,148,144,128,132,158,134,240,208,111,183,145,16,2,73,98,46,204,39,226,39,21,52,145,64,255,104,171,133,197,90,160,15,233,152,48,146,207,93,
184,101,41,3,79,113,85,208,209,126,250,168,78,78,134,135,93,188,187,11,229,216,243,17,104,37,246,163,180,252,212,119,59,15,103,86,187,99,160,27,124,84,194,50,41,149,171,12,32,225,47,184,49,215,108,198,
150,168,48,50,8,104,18,28,52,92,185,221,179,12,16,144,21,77,232,177,104,109,111,87,139,237,24,66,146,144,38,188,221,243,161,150,208,74,11,177,21,149,171,127,156,135,212,158,89,221,101,2,87,114,29,193,
79,131,25,199,154,107,198,239,78,57,250,108,81,21,134,166,71,196,182,222,99,188,146,77,26,45,98,127,208,55,112,32,201,230,244,185,47,219,87,104,141,193,21,167,228,78,156,144,220,144,225,243,177,40,139,
53,98,79,79,32,100,158,18,143,165,53,54,69,18,250,219,144,222,231,224,243,196,99,224,240,33,62,97,63,158,246,119,192,74,21,166,61,88,206,97,14,135,227,183,83,14,220,8,93,239,18,226,138,131,240,239,85,
225,194,231,226,247,142,38,22,176,28,56,220,40,214,176,162,206,66,52,130,156,76,39,72,19,233,96,46,0,142,131,0,123,161,45,159,38,177,221,184,190,134,88,115,124,73,192,165,106,202,36,210,250,36,122,106,
11,97,22,110,183,173,108,84,18,194,113,162,219,237,60,141,17,216,179,66,18,194,141,134,81,69,8,26,159,208,19,67,73,114,187,245,82,214,63,20,122,79,137,167,61,121,24,123,231,253,90,212,32,89,165,110,166,
145,210,20,97,125,186,48,133,38,113,87,117,172,126,235,105,13,7,3,241,184,233,168,93,9,21,72,192,46,254,238,34,112,55,214,144,92,113,180,147,191,154,192,227,150,38,177,142,6,114,110,125,14,4,66,239,163,
194,216,72,163,250,36,237,158,48,195,72,172,69,121,232,68,98,253,45,4,160,42,146,79,255,5,240,249,220,105,79,179,72,110,164,197,219,192,216,144,1,34,204,189,103,192,138,176,44,168,127,11,49,102,194,114,
86,146,157,88,3,64,203,186,229,195,169,94,36,67,223,6,8,51,31,11,13,192,242,2,195,135,71,144,20,162,202,63,2,79,248,8,159,127,72,96,254,144,204,199,26,61,81,30,82,29,201,140,222,19,135,201,123,208,67,
214,173,60,189,83,249,252,111,215,163,3,22,213,9,210,43,242,18,75,67,188,221,28,15,63,61,192,106,97,203,50,7,76,254,183,243,56,35,219,33,142,112,150,91,31,226,153,75,8,126,160,134,243,129,100,217,141,
15,62,135,157,199,182,124,62,185,247,180,98,246,248,11,189,185,144,142,144,240,22,63,33,106,42,231,12,139,61,10,19,73,123,151,111,145,80,246,68,107,37,140,164,20,245,158,73,172,46,149,247,144,242,158,
46,132,10,54,154,157,38,49,214,183,55,146,101,17,198,90,179,17,110,144,10,163,140,184,247,149,150,142,96,145,12,251,204,196,23,175,31,122,131,84,239,194,244,142,181,167,64,227,159,219,155,126,223,177,
62,95,39,168,248,82,13,218,46,74,198,160,1,139,122,121,184,52,61,33,196,28,136,194,128,14,124,128,149,84,214,215,183,3,133,11,50,2,90,14,85,198,104,44,97,72,223,59,19,98,125,179,145,202,136,125,72,183,
180,246,20,79,22,62,46,226,15,115,240,244,97,96,72,239,9,194,192,208,111,207,13,67,110,223,79,75,72,74,73,220,202,86,202,14,48,214,190,187,183,14,157,107,64,29,101,22,128,12,68,205,155,214,173,251,107,
49,157,75,223,206,68,42,239,234,191,75,23,177,198,8,195,247,108,30,123,158,23,87,150,54,82,8,61,201,117,109,161,188,9,115,14,253,145,180,221,110,125,158,221,8,238,85,184,0,133,115,99,85,129,204,217,128,
184,29,64,137,229,224,127,219,124,162,241,124,251,209,42,230,55,143,15,231,33,6,17,31,142,39,242,100,79,220,30,21,161,220,243,214,103,5,101,255,185,89,217,44,243,30,169,186,69,133,15,221,179,132,7,38,
192,238,172,201,104,55,134,119,134,159,129,3,150,161,106,167,117,35,247,173,136,214,223,238,156,128,161,240,58,100,119,200,98,31,142,22,111,121,248,88,243,24,129,147,234,189,132,186,201,36,208,73,42,75,
24,230,70,56,4,132,171,28,109,144,237,94,246,93,49,97,182,187,34,118,223,244,67,230,105,14,92,152,221,207,108,222,33,178,26,21,29,184,207,7,209,89,61,199,136,131,79,235,12,166,196,218,85,254,54,16,181,
5,236,34,111,222,24,239,60,43,61,73,55,158,26,194,12,34,16,147,176,27,165,207,10,143,9,60,11,129,222,167,194,143,11,41,7,202,239,203,121,155,165,162,134,166,145,240,98,81,95,235,20,249,195,241,24,3,8,
172,219,172,108,51,121,4,82,123,54,179,137,22,174,94,151,223,87,57,196,214,22,22,253,179,76,158,145,143,143,218,87,158,251,34,246,15,141,164,138,240,193,199,70,194,187,37,247,244,221,60,192,136,55,200,
222,33,174,90,149,197,172,72,99,48,45,239,221,42,177,255,240,126,248,101,44,134,210,136,17,93,38,135,60,44,250,124,172,37,239,150,234,46,96,171,99,57,173,84,68,69,144,20,169,163,103,66,199,76,122,6,242,
70,237,196,11,91,245,58,135,195,246,82,32,118,200,135,208,231,59,41,225,197,185,222,149,128,179,158,185,96,11,215,155,254,0,177,254,17,7,72,123,251,73,224,193,158,153,24,7,246,36,11,8,118,242,180,252,
185,231,35,221,44,129,63,178,93,33,149,7,91,221,228,71,192,154,93,246,39,15,65,88,140,159,107,152,131,7,107,152,60,244,135,196,97,120,232,183,156,195,144,187,230,183,26,217,227,250,41,106,127,5,19,182,
224,12,199,162,107,50,71,167,56,212,49,190,31,101,96,89,133,61,31,237,149,234,193,44,35,240,111,173,121,194,198,8,211,90,195,236,9,181,48,201,61,241,71,112,220,206,4,95,95,43,94,228,214,151,185,61,161,
69,121,254,152,236,146,196,2,88,71,91,199,130,71,230,172,242,244,110,160,193,160,208,206,38,31,66,18,207,205,8,239,124,120,132,134,91,159,220,211,244,240,236,151,190,71,86,253,68,89,105,187,149,144,240,
72,117,250,201,179,35,141,97,139,117,164,244,134,131,43,177,34,140,216,87,229,61,122,72,101,235,159,76,103,178,60,125,206,29,57,238,99,141,119,254,185,161,112,242,52,237,29,138,39,107,143,10,27,195,103,
75,32,185,113,107,9,189,32,196,227,159,2,13,4,225,109,152,85,111,127,63,169,66,154,176,96,97,206,62,220,19,155,135,165,201,224,136,53,35,218,138,231,102,163,83,169,116,181,86,61,178,202,59,140,48,7,119,
60,47,8,161,253,184,26,203,124,120,200,193,136,191,27,141,7,80,132,222,110,123,163,170,99,146,246,64,95,78,239,105,167,185,251,33,190,48,120,154,126,108,163,158,165,140,10,49,144,54,234,247,108,5,233,
126,57,226,139,222,79,66,136,173,227,131,24,187,148,79,107,30,174,221,224,210,45,115,75,226,243,49,50,110,205,133,185,225,15,111,187,101,24,9,183,124,8,180,180,62,91,31,78,20,254,72,170,59,113,219,207,
83,66,26,235,254,28,180,220,142,29,202,201,111,0,79,77,14,11,125,59,140,179,125,133,200,21,156,217,60,237,90,44,22,173,145,124,243,219,19,253,237,237,60,244,112,211,82,114,223,51,146,243,161,72,193,3,
151,208,23,198,114,104,54,147,109,77,0,241,134,47,23,135,196,170,84,170,131,171,99,29,152,5,190,230,96,197,156,233,43,214,48,198,17,216,20,90,170,32,235,246,56,162,72,98,87,114,32,97,55,202,195,13,183,
135,30,110,158,183,147,91,255,176,198,248,206,183,186,143,44,176,96,4,14,41,101,216,50,158,18,226,81,98,8,35,188,7,170,136,245,100,62,7,243,180,95,45,159,8,125,59,217,193,66,40,249,193,18,238,55,85,55,
110,236,89,47,18,162,190,218,201,27,204,241,28,89,96,33,90,204,209,39,242,161,98,248,107,167,66,208,21,194,35,199,5,201,30,107,48,110,247,100,156,111,161,110,172,55,2,31,219,127,134,62,231,110,30,95,200,
110,4,119,33,220,215,107,215,179,16,244,78,241,147,94,229,118,87,137,183,238,93,61,178,192,178,221,56,72,44,186,60,152,130,163,121,24,194,59,78,52,97,68,224,46,54,117,191,241,40,233,63,73,247,204,250,
138,233,248,32,2,125,73,250,202,229,174,16,217,70,42,55,19,77,233,56,255,135,206,240,222,237,43,236,93,229,125,176,207,222,148,230,242,141,102,174,214,42,72,44,128,197,85,213,69,55,106,104,169,144,57,
255,116,163,228,182,247,19,125,44,30,115,62,135,61,61,208,240,44,33,171,0,0,1,30,73,68,65,84,247,166,49,130,176,96,248,45,144,107,88,194,61,179,234,253,160,59,17,235,235,166,162,210,3,160,89,240,152,129,
92,143,117,104,213,247,109,3,188,24,15,235,64,1,54,82,215,152,33,221,209,171,76,9,147,40,235,91,122,29,90,249,142,86,70,17,225,127,100,187,66,90,205,176,194,149,222,16,144,105,149,16,152,114,35,100,2,
229,239,219,65,63,8,210,194,106,212,119,169,239,37,225,145,5,150,250,62,135,45,26,195,28,82,73,59,147,28,176,64,21,142,240,61,225,210,15,205,157,107,64,10,233,51,167,36,222,63,248,158,35,11,44,88,15,104,
204,53,213,44,29,16,216,224,19,229,4,70,26,6,130,208,172,21,198,182,19,135,177,99,127,55,14,28,101,96,153,160,226,202,123,15,62,116,230,92,203,153,184,226,206,248,210,13,85,221,184,230,19,118,35,104,15,
239,150,164,27,112,67,89,69,110,221,146,183,63,104,64,66,142,50,176,172,61,60,104,232,85,28,194,118,116,175,176,193,186,53,176,181,147,143,29,186,6,190,87,56,59,202,192,2,13,56,179,56,208,217,153,196,
210,138,142,96,90,102,79,160,144,131,111,27,79,140,39,12,247,4,99,143,231,192,255,7,92,92,162,196,185,164,0,25,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

//const char* ApdelayAudioProcessorEditor::screenShot20151119At18_08_57_png = (const char*) resource_ApdelayAudioProcessorEditor_screenShot20151119At18_08_57_png;
//const int ApdelayAudioProcessorEditor::screenShot20151119At18_08_57_pngSize = 17569;


//[EndFile] You can add extra defines here...
//[/EndFile]
