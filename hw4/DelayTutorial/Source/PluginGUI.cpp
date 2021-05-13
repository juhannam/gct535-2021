/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0
  Updated to Projucer version: 6.0.8

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  XXX-XX-2017    Created by Soonbeom Choi, KAIST
  XXX-XX-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
  May-07-2021    Modified by Minsuk Choi, KAIST
  
  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI (MyDelayAudioProcessor* p)
    : _p(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (LFORateLabel = new TextEditor ("LFORateLabel"));
    LFORateLabel->setMultiLine (false);
    LFORateLabel->setReturnKeyStartsNewLine (false);
    LFORateLabel->setReadOnly (true);
    LFORateLabel->setScrollbarsShown (true);
    LFORateLabel->setCaretVisible (true);
    LFORateLabel->setPopupMenuEnabled (true);
    LFORateLabel->setText (TRANS("LFO Rate (Hz)"));

    addAndMakeVisible (delayTimeSlider = new Slider ("delayTimeSlider"));
    delayTimeSlider->setRange (0, 2, 0.01);
    delayTimeSlider->setSliderStyle (Slider::LinearHorizontal);
    delayTimeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    delayTimeSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    delayTimeSlider->addListener (this);

    addAndMakeVisible (DelayTimeLabel = new TextEditor ("DelayTimeLabel"));
    DelayTimeLabel->setMultiLine (false);
    DelayTimeLabel->setReturnKeyStartsNewLine (false);
    DelayTimeLabel->setReadOnly (true);
    DelayTimeLabel->setScrollbarsShown (true);
    DelayTimeLabel->setCaretVisible (true);
    DelayTimeLabel->setPopupMenuEnabled (true);
    DelayTimeLabel->setText (TRANS("Delay Time (sec)"));

    addAndMakeVisible (FeedbackGainLabel = new TextEditor ("FeedbackGainLabel"));
    FeedbackGainLabel->setMultiLine (false);
    FeedbackGainLabel->setReturnKeyStartsNewLine (false);
    FeedbackGainLabel->setReadOnly (true);
    FeedbackGainLabel->setScrollbarsShown (true);
    FeedbackGainLabel->setCaretVisible (true);
    FeedbackGainLabel->setPopupMenuEnabled (true);
    FeedbackGainLabel->setText (TRANS("Feedback Gain (<1.0)"));

    addAndMakeVisible (FeedbackGainSlider = new Slider ("FeedbackGainSlider"));
    FeedbackGainSlider->setRange (0, 0.99, 0.01);
    FeedbackGainSlider->setSliderStyle (Slider::LinearHorizontal);
    FeedbackGainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    FeedbackGainSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    FeedbackGainSlider->addListener (this);

    addAndMakeVisible (WetDryLabel = new TextEditor ("WetDryLabel"));
    WetDryLabel->setMultiLine (false);
    WetDryLabel->setReturnKeyStartsNewLine (false);
    WetDryLabel->setReadOnly (true);
    WetDryLabel->setScrollbarsShown (true);
    WetDryLabel->setCaretVisible (true);
    WetDryLabel->setPopupMenuEnabled (true);
    WetDryLabel->setText (TRANS("WetDry (%)"));

    addAndMakeVisible (WetDrySlider = new Slider ("WetDrySlider"));
    WetDrySlider->setExplicitFocusOrder (50);
    WetDrySlider->setRange (0, 100, 1);
    WetDrySlider->setSliderStyle (Slider::LinearHorizontal);
    WetDrySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    WetDrySlider->setColour (Slider::textBoxTextColourId, Colours::black);
    WetDrySlider->addListener (this);

    addAndMakeVisible (DelayButton = new ToggleButton ("DelayButton"));
    DelayButton->setButtonText (TRANS("Delay"));
    DelayButton->setRadioGroupId (100);
    DelayButton->addListener (this);
    DelayButton->setColour(ToggleButton::textColourId, Colours::black);
    DelayButton->setColour(ToggleButton::tickColourId, Colours::darkslateblue);
    DelayButton->setColour(ToggleButton::tickDisabledColourId, Colours::gainsboro);
    DelayButton->setToggleState (true, dontSendNotification);

    addAndMakeVisible (ChorusButton = new ToggleButton ("ChorusButton"));
    ChorusButton->setButtonText (TRANS("Chorus"));
    ChorusButton->setRadioGroupId (100);
    ChorusButton->setColour(ToggleButton::textColourId, Colours::black);
    ChorusButton->setColour(ToggleButton::tickColourId, Colours::darkslateblue);
    ChorusButton->setColour(ToggleButton::tickDisabledColourId, Colours::gainsboro);
    ChorusButton->addListener (this);

    addAndMakeVisible (FlangerButton = new ToggleButton ("FlangerButton"));
    FlangerButton->setButtonText (TRANS("Flanger"));
    FlangerButton->setRadioGroupId (100);
    FlangerButton->setColour(ToggleButton::textColourId, Colours::black);
    FlangerButton->setColour(ToggleButton::tickColourId, Colours::darkslateblue);
    FlangerButton->setColour(ToggleButton::tickDisabledColourId, Colours::gainsboro);
    FlangerButton->addListener (this);

    addAndMakeVisible (LFORateSlider = new Slider ("LFORateSlider"));
    LFORateSlider->setRange (0, 10, 0.01);
    LFORateSlider->setSliderStyle (Slider::LinearHorizontal);
    LFORateSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    LFORateSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    LFORateSlider->addListener (this);

    addAndMakeVisible (LFODepthLabel = new TextEditor ("LFODepthLabel"));
    LFODepthLabel->setMultiLine (false);
    LFODepthLabel->setReturnKeyStartsNewLine (false);
    LFODepthLabel->setReadOnly (true);
    LFODepthLabel->setScrollbarsShown (true);
    LFODepthLabel->setCaretVisible (true);
    LFODepthLabel->setPopupMenuEnabled (true);
    LFODepthLabel->setText (TRANS("LFO Depth (<0.01)"));

    addAndMakeVisible (LFODepthSlider = new Slider ("LFODepthSlider"));
    LFODepthSlider->setRange (0, 0.01, 0.0001);
    LFODepthSlider->setSliderStyle (Slider::LinearHorizontal);
    LFODepthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    LFODepthSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    LFODepthSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    _p->loadDefaultPreset();
    delayTimeSlider->setValue(_p->getDelayTime());
    WetDrySlider->setValue(_p->getWetDry());
    FeedbackGainSlider->setValue(_p->getFeedbackGain());
    LFORateSlider->setValue(_p->getLFORate());
    LFODepthSlider->setValue(_p->getLFODepth());
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    LFORateLabel = nullptr;
    delayTimeSlider = nullptr;
    DelayTimeLabel = nullptr;
    FeedbackGainLabel = nullptr;
    FeedbackGainSlider = nullptr;
    WetDryLabel = nullptr;
    WetDrySlider = nullptr;
    DelayButton = nullptr;
    ChorusButton = nullptr;
    FlangerButton = nullptr;
    LFORateSlider = nullptr;
    LFODepthLabel = nullptr;
    LFODepthSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    LFORateLabel->setBounds (16, 192, 136, 24);
    delayTimeSlider->setBounds (163, 104, 365, 40);
    DelayTimeLabel->setBounds (16, 112, 136, 24);
    FeedbackGainLabel->setBounds (16, 152, 136, 24);
    FeedbackGainSlider->setBounds (163, 144, 365, 40);
    WetDryLabel->setBounds (16, 72, 136, 24);
    WetDrySlider->setBounds (163, 64, 365, 40);
    DelayButton->setBounds (192, 24, 72, 24);
    ChorusButton->setBounds (264, 24, 72, 24);
    FlangerButton->setBounds (336, 24, 72, 24);
    LFORateSlider->setBounds (163, 184, 365, 40);
    LFODepthLabel->setBounds (16, 232, 136, 24);
    LFODepthSlider->setBounds (163, 224, 365, 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == delayTimeSlider)
    {
        //[UserSliderCode_delayTimeSlider] -- add your slider handling code here..
        _p->setParameters(delayTimeSlider->getValue(), FeedbackGainSlider->getValue(), WetDrySlider->getValue(), LFORateSlider->getValue(), LFODepthSlider->getValue());
        //[/UserSliderCode_delayTimeSlider]
    }
    else if (sliderThatWasMoved == FeedbackGainSlider)
    {
        //[UserSliderCode_FeedbackGainSlider] -- add your slider handling code here..
        _p->setParameters(delayTimeSlider->getValue(), FeedbackGainSlider->getValue(), WetDrySlider->getValue(), LFORateSlider->getValue(), LFODepthSlider->getValue());
        //[/UserSliderCode_FeedbackGainSlider]
    }
    else if (sliderThatWasMoved == WetDrySlider)
    {
        //[UserSliderCode_WetDrySlider] -- add your slider handling code here..
        _p->setParameters(delayTimeSlider->getValue(), FeedbackGainSlider->getValue(), WetDrySlider->getValue(), LFORateSlider->getValue(), LFODepthSlider->getValue());
        //[/UserSliderCode_WetDrySlider]
    }
    else if (sliderThatWasMoved == LFORateSlider)
    {
        //[UserSliderCode_LFORateSlider] -- add your slider handling code here..
        _p->setParameters(delayTimeSlider->getValue(), FeedbackGainSlider->getValue(), WetDrySlider->getValue(), LFORateSlider->getValue(), LFODepthSlider->getValue());
        //[/UserSliderCode_LFORateSlider]
    }
    else if (sliderThatWasMoved == LFODepthSlider)
    {
        //[UserSliderCode_LFODepthSlider] -- add your slider handling code here..
        _p->setParameters(delayTimeSlider->getValue(), FeedbackGainSlider->getValue(), WetDrySlider->getValue(), LFORateSlider->getValue(), LFODepthSlider->getValue());
        //[/UserSliderCode_LFODepthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PluginGUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == DelayButton)
    {
        //[UserButtonCode_DelayButton] -- add your button handler code here..
        _p->selectEffectType(MyDelayAudioProcessor::EffectType(MyDelayAudioProcessor::DELAY));
        //[/UserButtonCode_DelayButton]
    }
    else if (buttonThatWasClicked == ChorusButton)
    {
        //[UserButtonCode_ChorusButton] -- add your button handler code here..
        _p->selectEffectType(MyDelayAudioProcessor::EffectType(MyDelayAudioProcessor::CHORUS));
        //[/UserButtonCode_ChorusButton]
    }
    else if (buttonThatWasClicked == FlangerButton)
    {
        //[UserButtonCode_FlangerButton] -- add your button handler code here..
        _p->selectEffectType(MyDelayAudioProcessor::EffectType(MyDelayAudioProcessor::FLANGER));
        //[/UserButtonCode_FlangerButton]
    }

    //[UserbuttonClicked_Post]
    delayTimeSlider->setValue(_p->getDelayTime());
    WetDrySlider->setValue(_p->getWetDry());
    FeedbackGainSlider->setValue(_p->getFeedbackGain());
    LFORateSlider->setValue(_p->getLFORate());
    LFODepthSlider->setValue(_p->getLFODepth());
    //[/UserbuttonClicked_Post]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public Component" constructorParams="MyDelayAudioProcessor* p"
                 variableInitialisers="_p(p)" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTEDITOR name="LFORateLabel" id="46ff0e08f669491c" memberName="LFORateLabel"
              virtualName="" explicitFocusOrder="0" pos="16 192 136 24" initialText="LFO Rate (Hz)"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="delayTimeSlider" id="2bdb28a94ea49d43" memberName="delayTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="163 104 365 40" min="0"
          max="2" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTEDITOR name="DelayTimeLabel" id="30d10d8c0aaaafd" memberName="DelayTimeLabel"
              virtualName="" explicitFocusOrder="0" pos="16 112 136 24" initialText="Delay Time (sec)"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="FeedbackGainLabel" id="84751e7e28711dbb" memberName="FeedbackGainLabel"
              virtualName="" explicitFocusOrder="0" pos="16 152 136 24" initialText="Feedback Gain (&lt;1.0)"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="FeedbackGainSlider" id="9cce7c8c45efae0d" memberName="FeedbackGainSlider"
          virtualName="" explicitFocusOrder="0" pos="163 144 365 40" min="0"
          max="0.98999999999999999112" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTEDITOR name="WetDryLabel" id="7170b3d4126fae4" memberName="WetDryLabel"
              virtualName="" explicitFocusOrder="0" pos="16 72 136 24" initialText="WetDry (%)"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="WetDrySlider" id="868a670c6e9ecaa8" memberName="WetDrySlider"
          virtualName="" explicitFocusOrder="50" pos="163 64 365 40" min="0"
          max="100" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TOGGLEBUTTON name="DelayButton" id="22596368dd5cabdc" memberName="DelayButton"
                virtualName="" explicitFocusOrder="0" pos="24 24 88 24" buttonText="Delay"
                connectedEdges="0" needsCallback="1" radioGroupId="100" state="1"/>
  <TOGGLEBUTTON name="ChorusButton" id="fbbe5984b5f960c5" memberName="ChorusButton"
                virtualName="" explicitFocusOrder="0" pos="160 24 72 24" buttonText="Chorus"
                connectedEdges="0" needsCallback="1" radioGroupId="100" state="0"/>
  <TOGGLEBUTTON name="FlangerButton" id="ba75054f5bae5a56" memberName="FlangerButton"
                virtualName="" explicitFocusOrder="0" pos="312 24 72 24" buttonText="Flanger"
                connectedEdges="0" needsCallback="1" radioGroupId="100" state="0"/>
  <SLIDER name="LFORateSlider" id="668f07e467390b9b" memberName="LFORateSlider"
          virtualName="" explicitFocusOrder="0" pos="163 184 365 40" min="0"
          max="10" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTEDITOR name="LFODepthLabel" id="45e46922d3781f87" memberName="LFODepthLabel"
              virtualName="" explicitFocusOrder="0" pos="16 232 136 24" initialText="LFO Depth (&lt;0.01)"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="LFODepthSlider" id="e2a9ae4bac25c4b" memberName="LFODepthSlider"
          virtualName="" explicitFocusOrder="0" pos="163 224 365 40" min="0"
          max="0.010000000000000000208" int="0.00010000000000000000479"
          style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
