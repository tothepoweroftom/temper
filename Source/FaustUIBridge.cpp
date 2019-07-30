/*
  ==============================================================================

    FaustUIBridge.cpp
    Created: 9 Feb 2017 5:59:55pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "FaustUIBridge.h"
#include <iostream>

FaustUIBridge::FaustUIBridge(AudioProcessorValueTreeState& vts)
: valueTreeState(vts)
{
}

FaustUIBridge::~FaustUIBridge()
{
    
    using std::cout;
    using std::endl;
    
    for (int i = 0; i < listenerAssignments.size(); ++i)
    {
        ParameterListenerPair p = listenerAssignments.getUnchecked(i);
        String paramId = p.paramId;
        cout << paramId << endl;
        FaustUIBridgeListener* listener = p.listener;
        valueTreeState.removeParameterListener(paramId, listener);
    }

    listenerAssignments.clear();
}

void FaustUIBridge::addHorizontalSlider(const char *label, float *zone, float init, float min, float max, float step)
{
    // Create the AudioProcessor parameter if not exists
    if (!valueTreeState.getParameter(label))
        valueTreeState.createAndAddParameter(label, label, String(),
                                             NormalisableRange<float>(min, max), init, nullptr, nullptr);

    // Attach the listener to keep the internal dsp values up to date
    FaustUIBridgeListener* l = new FaustUIBridgeListener(zone);
    listeners.add(l);
    listenerAssignments.add(ParameterListenerPair(String(label), l));
    valueTreeState.addParameterListener(label, l);
}
