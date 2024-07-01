#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize(600, 400);

    // Add and configure the gain knob
    addAndMakeVisible(gainKnob);
    gainKnob.setSliderStyle(juce::Slider::Rotary);
    gainKnob.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    gainKnob.setRange(0.0, 1.0, 0.01);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
    // Fill the background with a gradient
    juce::ColourGradient gradient(juce::Colours::darkslategrey, 0, 0,
        juce::Colours::black, getWidth(), getHeight(), false);
    g.setGradientFill(gradient);
    g.fillAll();

    // Set the font and draw some styled text
    juce::Font font("Arial", 32.0f, juce::Font::bold);
    g.setFont(font);
    g.setColour(juce::Colours::lightsalmon);

    // Text to be displayed
    juce::String text = "D1stroid";

    // Calculate the bounds for the text
    int margin = 10;
    float textWidth = font.getStringWidthFloat(text);
    float textHeight = font.getHeight();
    juce::Rectangle<float> textBounds(margin, margin, textWidth + 2 * margin, textHeight + 2 * margin);

    // Draw the rounded rectangle around the text with filled color
    g.setColour(juce::Colours::darkblue);
    g.fillRoundedRectangle(textBounds, 10); // 10 is the corner radius
    g.setColour(juce::Colours::lightsalmon);
    g.drawFittedText(text, textBounds.toNearestInt(), juce::Justification::centred, 1); // Draw the text
}

void MainComponent::resized()
{
    // Position the knob
    gainKnob.setBounds(250, 150, 100, 100);
}
