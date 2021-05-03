/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  Apr-11-2017    Created by Soonbeom Choi, KAIST
  Apr-12-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
  Apr-22-2021    Modified by Minsuk Choi, KAIST

 ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI (EqtutorialAudioProcessor* p)
    : _p(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    startTimer(200);
    //[/Constructor_pre]
    
    addAndMakeVisible (gainSlider = new Slider ("new slider"));
    gainSlider->setTooltip (TRANS("Gain"));
    gainSlider->setRange (-24, 24, 0.1);
    gainSlider->setSliderStyle (Slider::Rotary);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    gainSlider->setColour (Slider::rotarySliderFillColourId, Colours::gainsboro);
    gainSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    gainSlider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    gainSlider->addListener (this);

    addAndMakeVisible (frequencySlider = new Slider ("new slider"));
    frequencySlider->setTooltip (TRANS("Cut-off frequency"));
    frequencySlider->setRange (100, 5000, 1);
    frequencySlider->setSliderStyle (Slider::Rotary);
    frequencySlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    frequencySlider->setColour (Slider::rotarySliderFillColourId, Colours::gainsboro);
    frequencySlider->setColour (Slider::textBoxTextColourId, Colours::black);
    frequencySlider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    frequencySlider->addListener (this);

    addAndMakeVisible (qSlider = new Slider ("new slider"));
    qSlider->setTooltip (TRANS("Q"));
    qSlider->setRange (0.5, 6, 0.1);
    qSlider->setSliderStyle (Slider::Rotary);
    qSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    qSlider->setColour (Slider::rotarySliderFillColourId, Colours::gainsboro);
    qSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    qSlider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    qSlider->addListener (this);

    addAndMakeVisible (consoleBox = new TextEditor ("new text editor"));
    consoleBox->setMultiLine (true);
    consoleBox->setReturnKeyStartsNewLine (false);
    consoleBox->setReadOnly (true);
    consoleBox->setScrollbarsShown (true);
    consoleBox->setCaretVisible (false);
    consoleBox->setPopupMenuEnabled (true);
    consoleBox->setText (String());

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (false);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (false);
    textEditor->setJustification (juce::Justification::centred);
    textEditor->setText (TRANS("Gain"));

    addAndMakeVisible (textEditor2 = new TextEditor ("new text editor"));
    textEditor2->setMultiLine (false);
    textEditor2->setReturnKeyStartsNewLine (false);
    textEditor2->setReadOnly (true);
    textEditor2->setScrollbarsShown (false);
    textEditor2->setCaretVisible (false);
    textEditor2->setPopupMenuEnabled (false);
    textEditor2->setJustification (juce::Justification::centred);
    textEditor2->setText (TRANS("Frequency"));

    addAndMakeVisible (textEditor3 = new TextEditor ("new text editor"));
    textEditor3->setMultiLine (false);
    textEditor3->setReturnKeyStartsNewLine (false);
    textEditor3->setReadOnly (true);
    textEditor3->setScrollbarsShown (false);
    textEditor3->setCaretVisible (false);
    textEditor3->setPopupMenuEnabled (false);
    textEditor3->setJustification (juce::Justification::centred);
    textEditor3->setText (TRANS("Q"));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginGUI::~PluginGUI ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    gainSlider = nullptr;
    frequencySlider = nullptr;
    qSlider = nullptr;
    consoleBox = nullptr;
    textEditor = nullptr;
    textEditor2 = nullptr;
    textEditor3 = nullptr;


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

    gainSlider->setBounds (proportionOfWidth (0.1809f) - (96 / 2), 56, 96, 104);
    frequencySlider->setBounds (proportionOfWidth (0.5000f) - (120 / 2), 56, 120, 104);
    qSlider->setBounds (proportionOfWidth (0.8192f) - (112 / 2), 56, 112, 104);
    consoleBox->setBounds (20, 176, proportionOfWidth (0.8989f), proportionOfHeight (0.3741f));
    textEditor->setBounds (proportionOfWidth (0.1809f) - (76 / 2), 16, 76, 24);
    textEditor2->setBounds (proportionOfWidth (0.5000f) - (76 / 2), 16, 76, 24);
    textEditor3->setBounds (proportionOfWidth (0.8178f) - (76 / 2), 16, 76, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        _p->setParameters(gainSlider->getValue(), frequencySlider->getValue(), qSlider->getValue());
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == frequencySlider)
    {
        //[UserSliderCode_frequencySlider] -- add your slider handling code here..
        _p->setParameters(gainSlider->getValue(), frequencySlider->getValue(), qSlider->getValue());
        //[/UserSliderCode_frequencySlider]
    }
    else if (sliderThatWasMoved == qSlider)
    {
        //[UserSliderCode_qSlider] -- add your slider handling code here..
        _p->setParameters(gainSlider->getValue(), frequencySlider->getValue(), qSlider->getValue());
        //[/UserSliderCode_qSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginGUI::timerCallback()
{
    consoleBox->clear();
    consoleBox->insertTextAtCaret(" gain       : " + String(_p->getGain()) + newLine);
    consoleBox->insertTextAtCaret(" fc       : " + String(_p->getCenterFrequency()) + newLine);
    consoleBox->insertTextAtCaret(" fs       : " + String(_p->getSampleRate() ) + newLine);
    consoleBox->insertTextAtCaret(" Q       : " + String(_p->getQ() ) + newLine);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public Component, public Timer" constructorParams="EqtutorialAudioProcessor* p"
                 variableInitialisers="_p(p)" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="400" initialHeight="300">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="5fe1bc0a0ce31af1" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="18.085%c 56 96 104"
          tooltip="Gain" min="-24" max="24" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="1a7f61ba4862f360" memberName="frequencySlider"
          virtualName="" explicitFocusOrder="0" pos="50%c 56 120 104" tooltip="Cut-off frequency"
          min="100" max="5000" int="1" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="52d68868c191dce1" memberName="qSlider"
          virtualName="" explicitFocusOrder="0" pos="81.915%c 56 112 104"
          tooltip="Q" rotarysliderfill="7f0000ff" textboxtext="ff000000"
          textboxbkgd="ffffffff" min="0.5" max="6" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTEDITOR name="new text editor" id="c5dd331a063320d0" memberName="consoleBox"
              virtualName="" explicitFocusOrder="0" pos="20 176 89.894% 37.414%"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="f672651233d2bde1" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="18.085%c 16 56 24"
              initialText="Gain" multiline="0" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ad79f103c40cd107" memberName="textEditor2"
              virtualName="" explicitFocusOrder="0" pos="50%c 16 72 24" initialText="Frequency"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ece56ef055dbffb8" memberName="textEditor3"
              virtualName="" explicitFocusOrder="0" pos="81.782%c 16 23 24"
              initialText="Q" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
