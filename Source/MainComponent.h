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
    static const char* vst_png;
    static const int vst_pngSize;
    static const char* _2_png;
    static const int _2_pngSize;
    static const char* _2_png2;
    static const int _2_png2Size;
    static const char* vst2_png;
    static const int vst2_pngSize;
    static const char* vst2_png2;
    static const int vst2_png2Size;


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
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> glitchAttachment;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> timeAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> glitchSlider;
    std::unique_ptr<Slider> dryWetSlider;
    std::unique_ptr<Slider> feedbackSlider;
    std::unique_ptr<Slider> pitchSlider;
    std::unique_ptr<Slider> timeSlider;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label5;
    Image cachedImage_vst2_png2_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

