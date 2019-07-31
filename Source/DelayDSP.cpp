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
	FAUSTFLOAT fHslider3;
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider4;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider5;
	float fVec0[2];
	float fRec5[2];
	float fConst4;
	float fConst5;
	float fRec1[2];
	float fRec2[2];
	float fRec3[2];
	float fRec4[2];
	float fConst6;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fRec15[3];
	float fRec14[3];
	float fRec12[2];
	float fRec10[2];
	float fRec8[2];
	float fRec6[2];
	int IOTA;
	float fVec1[1048576];
	float fRec0[2];
	float fVec2[131072];
	FAUSTFLOAT fHslider9;
	float fRec16[2];
	
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
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
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
		fConst1 = (60.0f * fConst0);
		fConst2 = (0.5f * fConst0);
		fConst3 = (1.0f / fConst0);
		fConst4 = (10.0f / fConst0);
		fConst5 = (0.0f - fConst4);
		fConst6 = (3.14159274f / fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(100.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(50.0f);
		fHslider3 = FAUSTFLOAT(4.0f);
		fHslider4 = FAUSTFLOAT(120.0f);
		fHslider5 = FAUSTFLOAT(0.10000000000000001f);
		fHslider6 = FAUSTFLOAT(12000.0f);
		fHslider7 = FAUSTFLOAT(120.0f);
		fHslider8 = FAUSTFLOAT(50.0f);
		fHslider9 = FAUSTFLOAT(0.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec5[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec2[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec3[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec4[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec15[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
			fRec14[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec12[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec8[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec6[l11] = 0.0f;
			
		}
		IOTA = 0;
		for (int l12 = 0; (l12 < 1048576); l12 = (l12 + 1)) {
			fVec1[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec0[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 131072); l14 = (l14 + 1)) {
			fVec2[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec16[l15] = 0.0f;
			
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
		ui_interface->declare(&fHslider4, "name", "delay (bpm)");
		ui_interface->declare(&fHslider4, "tooltip", "Delay in Beats per Minute");
		ui_interface->addHorizontalSlider("bpm", &fHslider4, 120.0f, 24.0f, 360.0f, 1.0f);
		ui_interface->declare(&fHslider8, "tooltip", "percentage of the feedback level in the delay loop");
		ui_interface->addHorizontalSlider("feedback", &fHslider8, 50.0f, 1.0f, 100.0f, 1.0f);
		ui_interface->declare(&fHslider0, "tooltip", "overall gain of the delay line in percent");
		ui_interface->addHorizontalSlider("gain", &fHslider0, 100.0f, 0.0f, 120.0f, 1.0f);
		ui_interface->declare(&fHslider5, "tooltip", "pitch in semitones");
		ui_interface->addHorizontalSlider("glitch", &fHslider5, 0.100000001f, 0.0f, 2.0f, 0.100000001f);
		ui_interface->declare(&fHslider7, "name", "highpass (hz)");
		ui_interface->declare(&fHslider7, "tooltip", "highpass filter frequency in the feddback loop");
		ui_interface->addHorizontalSlider("highpass", &fHslider7, 120.0f, 20.0f, 20000.0f, 1.0f);
		ui_interface->declare(&fHslider6, "name", "lowpass (hz)");
		ui_interface->declare(&fHslider6, "tooltip", "lowpass filter frequency in the feddback loop");
		ui_interface->addHorizontalSlider("howpass", &fHslider6, 12000.0f, 20.0f, 20000.0f, 1.0f);
		ui_interface->declare(&fHslider2, "tooltip", "percentage of the delay gain level");
		ui_interface->addHorizontalSlider("level", &fHslider2, 50.0f, 1.0f, 100.0f, 1.0f);
		ui_interface->declare(&fHslider3, "enum", "Dotted 1/2 note|1/2 note|1/2 note triplets| Dotted 1/4 note|1/4 note|1/4 note triplets|Dotted 1/8 note|1/8 note|1/8 note triplets| Dotted 1/16 note|1/16 note|1/16 note triplets|Dotted 1/32 note|1/32 note|1/32 note triplets| Dotted 1/64 note|1/64 note|1/64 note triplets");
		ui_interface->declare(&fHslider3, "name", "tact");
		ui_interface->declare(&fHslider3, "tooltip", "note setting for bpm");
		ui_interface->addHorizontalSlider("notes", &fHslider3, 4.0f, 0.0f, 17.0f, 1.0f);
		ui_interface->declare(&fHslider9, "tooltip", "pitch in semitones");
		ui_interface->addHorizontalSlider("pitch", &fHslider9, 0.0f, -24.0f, 24.0f, 1.0f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		float fSlow0 = (0.00999999978f * float(fHslider0));
		float fSlow1 = float(fHslider1);
		int iSlow2 = int(fSlow1);
		float fSlow3 = (0.00999999978f * float(fHslider2));
		float fSlow4 = float(B2N(int(float(fHslider3)), float((fConst1 / float(fHslider4)))));
		float fSlow5 = float(fHslider5);
		float fSlow6 = std::tan((fConst6 * float(fHslider6)));
		float fSlow7 = (1.0f / fSlow6);
		float fSlow8 = (1.0f / (((fSlow7 + 1.41421354f) / fSlow6) + 1.0f));
		float fSlow9 = std::tan((fConst6 * float(fHslider7)));
		float fSlow10 = (1.0f / fSlow9);
		float fSlow11 = (1.0f / (((fSlow10 + 1.41421354f) / fSlow9) + 1.0f));
		float fSlow12 = MacallaDSP_faustpower2_f(fSlow9);
		float fSlow13 = (1.0f / fSlow12);
		float fSlow14 = (0.00999999978f * float(fHslider8));
		float fSlow15 = (((fSlow10 + -1.41421354f) / fSlow9) + 1.0f);
		float fSlow16 = (2.0f * (1.0f - fSlow13));
		float fSlow17 = (0.0f - (2.0f / fSlow12));
		float fSlow18 = (((fSlow7 + -1.41421354f) / fSlow6) + 1.0f);
		float fSlow19 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fSlow6))));
		float fSlow20 = (1.0f - fSlow1);
		float fSlow21 = std::pow(2.0f, (0.0833333358f * float(fHslider9)));
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fVec0[0] = fSlow5;
			float fTemp1 = ((fConst3 * fVec0[1]) + fRec5[1]);
			fRec5[0] = (fTemp1 - std::floor(fTemp1));
			float fTemp2 = std::min<float>(524288.0f, (fSlow4 + (fConst2 * ((2.0f * (1.0f - std::fabs(((2.0f * fRec5[0]) + -1.0f)))) + -1.0f))));
			float fTemp3 = ((fRec1[1] != 0.0f)?(((fRec2[1] > 0.0f) & (fRec2[1] < 1.0f))?fRec1[1]:0.0f):(((fRec2[1] == 0.0f) & (fTemp2 != fRec3[1]))?fConst4:(((fRec2[1] == 1.0f) & (fTemp2 != fRec4[1]))?fConst5:0.0f)));
			fRec1[0] = fTemp3;
			fRec2[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec2[1] + fTemp3)));
			fRec3[0] = (((fRec2[1] >= 1.0f) & (fRec4[1] != fTemp2))?fTemp2:fRec3[1]);
			fRec4[0] = (((fRec2[1] <= 0.0f) & (fRec3[1] != fTemp2))?fTemp2:fRec4[1]);
			float fTemp4 = (0.300000012f * fRec10[1]);
			fRec15[0] = ((fSlow14 * fRec0[1]) - (fSlow11 * ((fSlow15 * fRec15[2]) + (fSlow16 * fRec15[1]))));
			fRec14[0] = ((fSlow11 * (((fSlow13 * fRec15[0]) + (fSlow17 * fRec15[1])) + (fSlow13 * fRec15[2]))) - (fSlow8 * ((fSlow18 * fRec14[2]) + (fSlow19 * fRec14[1]))));
			float fTemp5 = (fSlow8 * (fRec14[2] + (fRec14[0] + (2.0f * fRec14[1]))));
			float fTemp6 = (0.5f * fRec6[1]);
			float fTemp7 = ((0.400000006f * fRec8[1]) + fTemp6);
			float fTemp8 = ((fTemp4 + (fTemp5 + (0.200000003f * fRec12[1]))) - fTemp7);
			fRec12[0] = fTemp8;
			float fRec13 = (0.0f - (0.200000003f * fTemp8));
			fRec10[0] = (fRec13 + fRec12[1]);
			float fRec11 = (0.0f - (0.300000012f * ((fTemp5 + fTemp4) - fTemp7)));
			fRec8[0] = (fRec11 + fRec10[1]);
			float fRec9 = (0.400000006f * (fTemp5 - fTemp7));
			fRec6[0] = (fRec9 + fRec8[1]);
			float fRec7 = (0.5f * (fTemp5 - fTemp6));
			float fTemp9 = ((iSlow2?fRec0[1]:(fRec7 + fRec6[1])) + (fSlow20 * fTemp0));
			fVec1[(IOTA & 1048575)] = fTemp9;
			float fTemp10 = (((1.0f - fRec2[0]) * fVec1[((IOTA - int(std::min<float>(524288.0f, std::max<float>(0.0f, fRec3[0])))) & 1048575)]) + (fRec2[0] * fVec1[((IOTA - int(std::min<float>(524288.0f, std::max<float>(0.0f, fRec4[0])))) & 1048575)]));
			fRec0[0] = (iSlow2?fTemp10:(fSlow3 * fTemp10));
			float fTemp11 = (fRec0[0] + (fSlow1 * fTemp0));
			fVec2[(IOTA & 131071)] = fTemp11;
			fRec16[0] = std::fmod(((fRec16[1] + 1025.0f) - fSlow21), 1024.0f);
			int iTemp12 = int(fRec16[0]);
			float fTemp13 = std::floor(fRec16[0]);
			float fTemp14 = std::min<float>((0.0078125f * fRec16[0]), 1.0f);
			float fTemp15 = (fRec16[0] + 1024.0f);
			int iTemp16 = int(fTemp15);
			float fTemp17 = std::floor(fTemp15);
			output0[i] = FAUSTFLOAT((fTemp0 + (fSlow0 * ((((fVec2[((IOTA - std::min<int>(65537, std::max<int>(0, iTemp12))) & 131071)] * (fTemp13 + (1.0f - fRec16[0]))) + ((fRec16[0] - fTemp13) * fVec2[((IOTA - std::min<int>(65537, std::max<int>(0, (iTemp12 + 1)))) & 131071)])) * fTemp14) + (((fVec2[((IOTA - std::min<int>(65537, std::max<int>(0, iTemp16))) & 131071)] * (fTemp17 + (-1023.0f - fRec16[0]))) + ((fRec16[0] + (1024.0f - fTemp17)) * fVec2[((IOTA - std::min<int>(65537, std::max<int>(0, (iTemp16 + 1)))) & 131071)])) * (1.0f - fTemp14))))));
			fVec0[1] = fVec0[0];
			fRec5[1] = fRec5[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec10[1] = fRec10[0];
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			IOTA = (IOTA + 1);
			fRec0[1] = fRec0[0];
			fRec16[1] = fRec16[0];
			
		}
		
	}

	
};


#endif
