#include "APVTS.h"
#include "DelayTimeParameter.h"

APVTS::APVTS(juce::AudioProcessor &processor)
:
juce::AudioProcessorValueTreeState (processor, nullptr, "STATE", createParameterLayout(processor))
{
}

APVTS::ParameterLayout APVTS::createParameterLayout(juce::AudioProcessor &processorToUse)
{
	AudioProcessorValueTreeState::ParameterLayout layout;
	
	layout.add (std::make_unique<DelayTimeParameter> (processorToUse));
	
	return layout;
}