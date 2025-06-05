/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ParamsAudioProcessorEditor::ParamsAudioProcessorEditor (ParamsAudioProcessor& p)
: AudioProcessorEditor (&p)
, audioProcessor (p)
, delayAttachment (p.getPluginState (), Params::delayTimeId.getParamID (), delaySlider)
, timeSignatureAttachment (p.getPluginState (), Params::delayTimeSignatureId.getParamID (), timeSignatureBox)
, syncAttachment (p.getPluginState (), Params::delaySyncId.getParamID (), syncBox)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(delaySlider);
	addAndMakeVisible(timeSignatureBox);
	addAndMakeVisible(syncBox);

	delaySlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
}

ParamsAudioProcessorEditor::~ParamsAudioProcessorEditor()
{
}

//==============================================================================
void ParamsAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void ParamsAudioProcessorEditor::resized()
{
    auto size = juce::jmin(getWidth(), getHeight());
	auto bounds = getLocalBounds ().withSizeKeepingCentre (size, size);

	syncBox.setBounds (bounds.removeFromTop (40).reduced (6));
	timeSignatureBox.setBounds (bounds.removeFromTop (40).reduced (6));
	delaySlider.setBounds (bounds.reduced (6));
}
