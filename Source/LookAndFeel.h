#pragma once

class MyLookAndFeel : public juce::LookAndFeel_V4
{
public:
	void drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
		float sliderPos, float minSliderPos, float maxSliderPos,
		juce::Slider::SliderStyle style, juce::Slider& slider) override;

private:
	// You can add any private member variables or methods here if needed.
};


void MyLookAndFeel::drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
	float sliderPos, float minSliderPos, float maxSliderPos,
	juce::Slider::SliderStyle style, juce::Slider& slider)
{
	// Custom drawing code for the linear slider goes here.
	g.fillAll (juce::Colours::lightgrey);
	g.setColour (juce::Colours::blue);
	g.fillRect (x, y + height - sliderPos, width, 10); // Draw the slider thumb
}

/** How to use LookAndFeel
 * 
 * 
 * 
 */