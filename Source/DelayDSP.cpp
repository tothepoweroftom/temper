/* ------------------------------------------------------------
name: "Macalla"
Code generated with Faust 2.14.4 (https://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __MacallaDSP_H__
#define  __MacallaDSP_H__

/************************************************************************
 ************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------

    This is sample code. This file is provided as an example of minimal
    FAUST architecture file. Redistribution and use in source and binary
    forms, with or without modification, in part or in full are permitted.
    In particular you can create a derived work of this FAUST architecture
    and distribute that work under terms of your choice.

    This sample code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ************************************************************************
 ************************************************************************/
 
#include <math.h>
#include <algorithm>

#include "faust/gui/UI.h"
#include "faust/gui/meta.h"
#include "faust/dsp/dsp.h"

using std::max;
using std::min;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/******************************************************************************
*******************************************************************************

			ABSTRACT USER INTERFACE

*******************************************************************************
*******************************************************************************/

//----------------------------------------------------------------------------
//  FAUST generated signal processor
//----------------------------------------------------------------------------

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include "faust/beat.h"
#include <algorithm>
#include <cmath>
#include <math.h>

static float MacallaDSP_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS MacallaDSP
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class MacallaDSP : public ::dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec10[3];
	float fRec9[3];
	float fRec7[2];
	float fRec5[2];
	float fRec3[2];
	float fRec1[2];
	int IOTA;
	float fVec0[1048576];
	FAUSTFLOAT fHslider6;
	float fConst2;
	FAUSTFLOAT fHslider7;
	float fConst3;
	FAUSTFLOAT fHslider8;
	float fVec1[2];
	float fRec15[2];
	float fConst4;
	float fConst5;
	float fRec11[2];
	float fRec12[2];
	float fRec13[2];
	float fRec14[2];
	float fRec0[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("category", "Echo / Delay");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.0");
		m->declare("description", "Macalla Delay");
		m->declare("filename", "Macalla");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("id", "maca");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "Macalla");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 1;
		
	}
	virtual int getNumOutputs() {
		return 1;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (60.0f * fConst0);
		fConst3 = (1.0f / fConst0);
		fConst4 = (10.0f / fConst0);
		fConst5 = (0.0f - fConst4);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(100.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(50.0f);
		fHslider3 = FAUSTFLOAT(12000.0f);
		fHslider4 = FAUSTFLOAT(120.0f);
		fHslider5 = FAUSTFLOAT(50.0f);
		fHslider6 = FAUSTFLOAT(4.0f);
		fHslider7 = FAUSTFLOAT(120.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
			fRec10[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 3); l1 = (l1 + 1)) {
			fRec9[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec7[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec5[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec1[l5] = 0.0f;
			
		}
		IOTA = 0;
		for (int l6 = 0; (l6 < 1048576); l6 = (l6 + 1)) {
			fVec0[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec15[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec11[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec12[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec13[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec14[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec0[l13] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual MacallaDSP* clone() {
		return new MacallaDSP();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Macalla");
		ui_interface->declare(&fHslider1, "tooltip", "Freeze the current delay");
		ui_interface->addHorizontalSlider("Freeze", &fHslider1, 0.0f, 0.0f, 1.0f, 1.0f);
		ui_interface->declare(&fHslider7, "name", "delay (bpm)");
		ui_interface->declare(&fHslider7, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("bpm", &fHslider7, 120.0f, 24.0f, 360.0f, 1.0f);
		ui_interface->declare(&fHslider5, "tooltip", "percentage of the feedback level in the delay loop");
		ui_interface->addHorizontalSlider("feedback", &fHslider5, 50.0f, 1.0f, 100.0f, 1.0f);
		ui_interface->declare(&fHslider0, "tooltip", "overall gain of the delay line in percent");
		ui_interface->addHorizontalSlider("gain", &fHslider0, 100.0f, 0.0f, 120.0f, 1.0f);
		ui_interface->declare(&fHslider8, "tooltip", "pitch in semitones");
		ui_interface->addHorizontalSlider("glitch", &fHslider8, 0.0f, 0.0f, 5.0f, 0.00999999978f);
		ui_interface->declare(&fHslider4, "name", "highpass (hz)");
		ui_interface->declare(&fHslider4, "tooltip", "highpass filter frequency in the feddback loop");
		ui_interface->addHorizontalSlider("highpass", &fHslider4, 120.0f, 20.0f, 20000.0f, 1.0f);
		ui_interface->declare(&fHslider3, "name", "lowpass (hz)");
		ui_interface->declare(&fHslider3, "tooltip", "lowpass filter frequency in the feddback loop");
		ui_interface->addHorizontalSlider("lowpass", &fHslider3, 12000.0f, 20.0f, 20000.0f, 1.0f);
		ui_interface->declare(&fHslider2, "tooltip", "percentage of the delay gain level");
		ui_interface->addHorizontalSlider("level", &fHslider2, 50.0f, 1.0f, 100.0f, 1.0f);
		ui_interface->declare(&fHslider6, "enum", "Dotted 1/2 note|1/2 note|1/2 note triplets| Dotted 1/4 note|1/4 note|1/4 note triplets|Dotted 1/8 note|1/8 note|1/8 note triplets| Dotted 1/16 note|1/16 note|1/16 note triplets|Dotted 1/32 note|1/32 note|1/32 note triplets| Dotted 1/64 note|1/64 note|1/64 note triplets");
		ui_interface->declare(&fHslider6, "name", "tact");
		ui_interface->declare(&fHslider6, "tooltip", "note setting for bpm");
		ui_interface->addHorizontalSlider("notes", &fHslider6, 4.0f, 0.0f, 17.0f, 1.0f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.00999999978f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		int iSlow2 = int(fSlow1);
		float fSlow3 = (0.00999999978f * float(fHslider2));
		float fSlow4 = std::tan((fConst1 * float(fHslider3)));
		float fSlow5 = (1.0f / fSlow4);
		float fSlow6 = (1.0f / (((fSlow5 + 1.41421354f) / fSlow4) + 1.0f));
		float fSlow7 = std::tan((fConst1 * float(fHslider4)));
		float fSlow8 = (1.0f / fSlow7);
		float fSlow9 = (1.0f / (((fSlow8 + 1.41421354f) / fSlow7) + 1.0f));
		float fSlow10 = MacallaDSP_faustpower2_f(fSlow7);
		float fSlow11 = (1.0f / fSlow10);
		float fSlow12 = (0.00999999978f * float(fHslider5));
		float fSlow13 = (((fSlow8 + -1.41421354f) / fSlow7) + 1.0f);
		float fSlow14 = (2.0f * (1.0f - fSlow11));
		float fSlow15 = (0.0f - (2.0f / fSlow10));
		float fSlow16 = (((fSlow5 + -1.41421354f) / fSlow4) + 1.0f);
		float fSlow17 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fSlow4))));
		float fSlow18 = (1.0f - fSlow1);
		float fSlow19 = float(B2N(int(float(fHslider6)), float((fConst2 / float(fHslider7)))));
		float fSlow20 = float(fHslider8);
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			float fTemp1 = (0.300000012f * fRec5[1]);
			fRec10[0] = ((fSlow12 * fRec0[1]) - (fSlow9 * ((fSlow13 * fRec10[2]) + (fSlow14 * fRec10[1]))));
			fRec9[0] = ((fSlow9 * (((fSlow11 * fRec10[0]) + (fSlow15 * fRec10[1])) + (fSlow11 * fRec10[2]))) - (fSlow6 * ((fSlow16 * fRec9[2]) + (fSlow17 * fRec9[1]))));
			float fTemp2 = (fSlow6 * (fRec9[2] + ((2.0f * fRec9[1]) + fRec9[0])));
			float fTemp3 = (0.5f * fRec1[1]);
			float fTemp4 = ((0.400000006f * fRec3[1]) + fTemp3);
			float fTemp5 = ((fTemp1 + (fTemp2 + (0.200000003f * fRec7[1]))) - fTemp4);
			fRec7[0] = fTemp5;
			float fRec8 = (0.0f - (0.200000003f * fTemp5));
			fRec5[0] = (fRec7[1] + fRec8);
			float fRec6 = (0.0f - (0.300000012f * ((fTemp2 + fTemp1) - fTemp4)));
			fRec3[0] = (fRec5[1] + fRec6);
			float fRec4 = (0.400000006f * (fTemp2 - fTemp4));
			fRec1[0] = (fRec3[1] + fRec4);
			float fRec2 = (0.5f * (fTemp2 - fTemp3));
			float fTemp6 = ((iSlow2?fRec0[1]:(fRec1[1] + fRec2)) + (fSlow18 * fTemp0));
			fVec0[(IOTA & 1048575)] = fTemp6;
			fVec1[0] = fSlow20;
			float fTemp7 = ((fConst3 * fVec1[1]) + fRec15[1]);
			fRec15[0] = (fTemp7 - std::floor(fTemp7));
			float fTemp8 = std::min<float>(524288.0f, (fSlow19 + (fConst0 * ((2.0f * (1.0f - std::fabs(((2.0f * fRec15[0]) + -1.0f)))) + -1.0f))));
			float fTemp9 = ((fRec11[1] != 0.0f)?(((fRec12[1] > 0.0f) & (fRec12[1] < 1.0f))?fRec11[1]:0.0f):(((fRec12[1] == 0.0f) & (fTemp8 != fRec13[1]))?fConst4:(((fRec12[1] == 1.0f) & (fTemp8 != fRec14[1]))?fConst5:0.0f)));
			fRec11[0] = fTemp9;
			fRec12[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec12[1] + fTemp9)));
			fRec13[0] = (((fRec12[1] >= 1.0f) & (fRec14[1] != fTemp8))?fTemp8:fRec13[1]);
			fRec14[0] = (((fRec12[1] <= 0.0f) & (fRec13[1] != fTemp8))?fTemp8:fRec14[1]);
			float fTemp10 = ((fVec0[((IOTA - int(std::min<float>(524288.0f, std::max<float>(0.0f, fRec13[0])))) & 1048575)] * (1.0f - fRec12[0])) + (fVec0[((IOTA - int(std::min<float>(524288.0f, std::max<float>(0.0f, fRec14[0])))) & 1048575)] * fRec12[0]));
			fRec0[0] = (iSlow2?fTemp10:(fSlow3 * fTemp10));
			output0[i] = FAUSTFLOAT(((fSlow0 * ((fSlow1 * fTemp0) + fRec0[0])) + fTemp0));
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
			IOTA = (IOTA + 1);
			fVec1[1] = fVec1[0];
			fRec15[1] = fRec15[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec0[1] = fRec0[0];
			
		}
		
	}

	
};


#endif
