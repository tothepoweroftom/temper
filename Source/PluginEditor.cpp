/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TemperAudioProcessorEditor::TemperAudioProcessorEditor (TemperAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), m_vts(vts)
{
    addAndMakeVisible(m_main = new MainComponent(m_vts));


    m_main->setAlwaysOnTop(true);



    m_glContext.setComponentPaintingEnabled(true);
    m_glContext.attachTo(*this);

    setSize (1024, 768);
    setLookAndFeel(&laf);
}

TemperAudioProcessorEditor::~TemperAudioProcessorEditor()
{
    m_glContext.detach();
    setLookAndFeel(nullptr);
}

//==============================================================================
void TemperAudioProcessorEditor::paint (Graphics& g)
{
   

  
}

void TemperAudioProcessorEditor::resized()
{
    m_main->setBounds(0, 0, 1024,768);

}
