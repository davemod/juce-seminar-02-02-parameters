/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ParamsAudioProcessorEditor::ParamsAudioProcessorEditor (ParamsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(delaySlider);
    
	delayAttachment = std::make_unique<APVTS::SliderAttachment> (p.getPluginState (), Params::delayTimeId.getParamID (), delaySlider);
}

ParamsAudioProcessorEditor::~ParamsAudioProcessorEditor()
{
}

//==============================================================================
void ParamsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ParamsAudioProcessorEditor::resized()
{
    delaySlider.setBounds (getLocalBounds ().reduced (20));
}
