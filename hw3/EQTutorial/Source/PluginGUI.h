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

#ifndef __JUCE_HEADER_AD07FA593BDA3138__
#define __JUCE_HEADER_AD07FA593BDA3138__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginGUI  :  public Component,
                    public Timer,
                    public juce::Slider::Listener
{
public:
    //==============================================================================
    PluginGUI (EqtutorialAudioProcessor* p);
    ~PluginGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    EqtutorialAudioProcessor* _p;
    //[/UserVariables]

    //==============================================================================
    Slider* gainSlider;
    Slider* frequencySlider;
    Slider* qSlider;
    TextEditor* consoleBox;
    TextEditor* textEditor;
    TextEditor* textEditor2;
    TextEditor* textEditor3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_AD07FA593BDA3138__
