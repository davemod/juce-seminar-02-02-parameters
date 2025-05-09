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
    
    auto findParameter = [&](const juce::ParameterID& paramId)
    {
        for (auto param : p.getParameters ())
            if (auto ranged = dynamic_cast<juce::RangedAudioParameter*> (param))
                if (ranged->getParameterID () == paramId.getParamID())
                    return ranged;
        
        return static_cast<juce::RangedAudioParameter*> (nullptr);
    };

    if (auto delayParam = findParameter (Params::delayTimeId))
        delayAttachment = std::make_unique<juce::SliderParameterAttachment> (*delayParam, delaySlider, nullptr);
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
