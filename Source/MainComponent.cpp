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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent (AudioProcessorValueTreeState& vts)
    : m_vts(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (744, 476);


    //[Constructor] You can add your own custom stuff here..
   /*filterFreqAttachment = new SliderAttachment(m_vts, "Cutoff", *m_cutoffSlider);
    filterResoAttachment = new SliderAttachment(m_vts, "Resonance", *m_resoSlider);
    driveAttachment = new SliderAttachment(m_vts, "Drive", *m_driveSlider);
    curveAttachment = new SliderAttachment(m_vts, "Curve", *m_curveSlider);
    satAttachment = new SliderAttachment(m_vts, "Saturation", *m_satSlider);
    feedbackAttachment = new SliderAttachment(m_vts, "Feedback", *m_feedbackSlider);
    levelAttachment = new SliderAttachment(m_vts, "Level", *m_gainSlider);

    m_cutoffSlider->setTextValueSuffix("Hz");
    m_cutoffSlider->setSkewFactorFromMidPoint(800.0);
    m_feedbackSlider->setTextValueSuffix("dB");
    m_gainSlider->setTextValueSuffix("dB");
    */
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    // This has to happen before we null out the Sliders themselves because
    // when the ScopedPointer<> delete policy tries to remove Listeners from
    // the SliderAttachment it refers to the Sliders themselves. If the Sliders
    // have already been deleted at that point then we get a null pointer error.
    filterFreqAttachment = nullptr;
    filterResoAttachment = nullptr;
    driveAttachment = nullptr;
    curveAttachment = nullptr;
    satAttachment = nullptr;
    feedbackAttachment = nullptr;
    levelAttachment = nullptr;
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::bisque);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="m_vts(vts)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="744"
                 initialHeight="476">
  <BACKGROUND backgroundColour="ffffe4c4"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

