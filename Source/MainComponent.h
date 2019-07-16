/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public Component,
                       public Slider::Listener
{
public:
    //==============================================================================
    MainComponent (AudioProcessorValueTreeState& vts);
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* macalladly_png;
    static const int macalladly_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AudioProcessorValueTreeState& m_vts;
    /*
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterFreqAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterResoAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> satAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> curveAttachment;
    */
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> timeAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> slider;
    std::unique_ptr<Slider> slider3;
    std::unique_ptr<Slider> slider2;
    Image cachedImage_macalladly_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

