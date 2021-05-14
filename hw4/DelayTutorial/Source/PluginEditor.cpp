/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

    XXX-XX-2017    Created by Soonbeom Choi, KAIST
    XXX-XX-2017    Modified by Juhan Nam, KAIST as starter code for GCT535 homework
    May-07-2021    Modified by Minsuk Choi, KAIST
    
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MyDelayAudioProcessorEditor::MyDelayAudioProcessorEditor (MyDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), pluginGUI(&p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(pluginGUI);
    setSize (600, 300);
}

MyDelayAudioProcessorEditor::~MyDelayAudioProcessorEditor()
{
}

//==============================================================================
void MyDelayAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

//    g.setColour (Colours::black);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void MyDelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
