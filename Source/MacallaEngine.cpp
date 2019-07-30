/* ------------------------------------------------------------
 name: "Digital Delay"
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
    
    FAUSTFLOAT fVslider0;
    FAUSTFLOAT fHslider0;
    FAUSTFLOAT fVslider1;
    FAUSTFLOAT fHslider1;
    int fSamplingFreq;
    float fConst0;
    float fConst1;
    FAUSTFLOAT fHslider2;
    float fConst2;
    float fConst3;
    float fRec1[2];
    float fRec2[2];
    float fRec3[2];
    float fRec4[2];
    FAUSTFLOAT fHslider3;
    float fConst4;
    FAUSTFLOAT fHslider4;
    FAUSTFLOAT fHslider5;
    FAUSTFLOAT fVslider2;
    float fRec6[3];
    float fRec5[3];
    float fVec0[2];
    float fConst5;
    float fConst6;
    float fConst7;
    float fConst8;
    float fConst9;
    float fConst10;
    float fConst11;
    float fConst12;
    float fConst13;
    float fConst14;
    float fConst15;
    float fConst16;
    float fConst17;
    float fConst18;
    float fConst19;
    float fConst20;
    float fConst21;
    float fConst22;
    float fConst23;
    float fConst24;
    float fConst25;
    float fConst26;
    float fConst27;
    float fConst28;
    float fConst29;
    float fConst30;
    float fConst31;
    float fConst32;
    float fConst33;
    float fConst34;
    float fConst35;
    float fConst36;
    float fConst37;
    float fConst38;
    float fConst39;
    float fConst40;
    float fConst41;
    float fConst42;
    float fConst43;
    float fConst44;
    float fConst45;
    float fConst46;
    float fConst47;
    float fConst48;
    float fConst49;
    float fConst50;
    float fConst51;
    float fRec15[2];
    float fConst52;
    float fConst53;
    float fRec14[3];
    float fConst54;
    float fConst55;
    float fRec13[3];
    float fConst56;
    float fConst57;
    float fConst58;
    float fConst59;
    float fRec12[3];
    float fConst60;
    float fConst61;
    float fConst62;
    float fConst63;
    float fRec11[3];
    float fConst64;
    float fConst65;
    float fConst66;
    float fConst67;
    float fRec10[3];
    float fConst68;
    float fConst69;
    float fConst70;
    float fConst71;
    float fRec9[3];
    float fConst72;
    float fConst73;
    float fConst74;
    float fVec1[2];
    float fRec8[2];
    float fConst75;
    float fConst76;
    float fConst77;
    float fRec7[3];
    float fRec22[2];
    float fRec20[2];
    float fRec18[2];
    float fRec16[2];
    float fRec30[2];
    float fRec28[2];
    float fRec26[2];
    float fRec24[2];
    int IOTA;
    float fVec2[1048576];
    float fRec0[2];
    
public:
    
    void metadata(Meta* m) {
        m->declare("basics.lib/name", "Faust Basic Element Library");
        m->declare("basics.lib/version", "0.0");
        m->declare("category", "Echo / Delay");
        m->declare("delays.lib/name", "Faust Delay Library");
        m->declare("delays.lib/version", "0.0");
        m->declare("description", "Digital Delay");
        m->declare("filename", "Macalla");
        m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
        m->declare("filter.lib/copyright", "Julius O. Smith III");
        m->declare("filter.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
        m->declare("filter.lib/license", "STK-4.3");
        m->declare("filter.lib/name", "Faust Filter Library");
        m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
        m->declare("filter.lib/version", "1.29");
        m->declare("filters.lib/name", "Faust Filters Library");
        m->declare("filters.lib/version", "0.0");
        m->declare("id", "dide");
        m->declare("math.lib/author", "GRAME");
        m->declare("math.lib/copyright", "GRAME");
        m->declare("math.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
        m->declare("math.lib/license", "LGPL with exception");
        m->declare("math.lib/name", "Math Library");
        m->declare("math.lib/version", "1.0");
        m->declare("maths.lib/author", "GRAME");
        m->declare("maths.lib/copyright", "GRAME");
        m->declare("maths.lib/license", "LGPL with exception");
        m->declare("maths.lib/name", "Faust Math Library");
        m->declare("maths.lib/version", "2.1");
        m->declare("music.lib/author", "GRAME");
        m->declare("music.lib/copyright", "GRAME");
        m->declare("music.lib/deprecated", "This library is deprecated and is not maintained anymore. It will be removed in August 2017.");
        m->declare("music.lib/license", "LGPL with exception");
        m->declare("music.lib/name", "Music Library");
        m->declare("music.lib/version", "1.0");
        m->declare("name", "Digital Delay");
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
        fConst2 = (10.0f / fConst0);
        fConst3 = (0.0f - fConst2);
        fConst4 = (3.14159274f / fConst0);
        fConst5 = std::tan((37699.1133f / fConst0));
        fConst6 = (1.0f / fConst5);
        fConst7 = (((fConst6 + 1.0f) / fConst5) + 1.0f);
        fConst8 = (0.800000012f / fConst7);
        fConst9 = (1.0f / (fConst6 + 1.0f));
        fConst10 = (1.0f - fConst6);
        fConst11 = (25132.7422f / fConst0);
        fConst12 = std::tan(fConst11);
        fConst13 = (1.0f / fConst12);
        fConst14 = (fConst0 * std::sin((50265.4844f / fConst0)));
        fConst15 = (3141.59277f / fConst14);
        fConst16 = (1.0f / (((fConst13 + fConst15) / fConst12) + 1.0f));
        fConst17 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fConst12))));
        fConst18 = (12566.3711f / fConst0);
        fConst19 = std::tan(fConst18);
        fConst20 = (1.0f / fConst19);
        fConst21 = (fConst0 * std::sin(fConst11));
        fConst22 = (6268.30127f / fConst21);
        fConst23 = (1.0f / (((fConst20 + fConst22) / fConst19) + 1.0f));
        fConst24 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fConst19))));
        fConst25 = std::tan((6283.18555f / fConst0));
        fConst26 = (1.0f / fConst25);
        fConst27 = (fConst0 * std::sin(fConst18));
        fConst28 = (1570.79639f / fConst27);
        fConst29 = (1.0f / (((fConst26 + fConst28) / fConst25) + 1.0f));
        fConst30 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fConst25))));
        fConst31 = std::tan((1178.09729f / fConst0));
        fConst32 = (1.0f / fConst31);
        fConst33 = (fConst0 * std::sin((2356.19458f / fConst0)));
        fConst34 = (392.699097f / fConst33);
        fConst35 = (1.0f / (((fConst32 + fConst34) / fConst31) + 1.0f));
        fConst36 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fConst31))));
        fConst37 = std::tan((628.318542f / fConst0));
        fConst38 = (1.0f / fConst37);
        fConst39 = (fConst0 * std::sin((1256.63708f / fConst0)));
        fConst40 = (221.880875f / fConst39);
        fConst41 = (1.0f / (((fConst38 + fConst40) / fConst37) + 1.0f));
        fConst42 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fConst37))));
        fConst43 = std::tan((251.327408f / fConst0));
        fConst44 = (1.0f / fConst43);
        fConst45 = (1.0f / (((fConst44 + 1.0f) / fConst43) + 1.0f));
        fConst46 = MacallaDSP_faustpower2_f(fConst43);
        fConst47 = (1.0f / fConst46);
        fConst48 = (fConst44 + 1.0f);
        fConst49 = (0.0f - (1.0f / (fConst43 * fConst48)));
        fConst50 = (1.0f / fConst48);
        fConst51 = (1.0f - fConst44);
        fConst52 = (((fConst44 + -1.0f) / fConst43) + 1.0f);
        fConst53 = (2.0f * (1.0f - fConst47));
        fConst54 = (0.0f - (2.0f / fConst46));
        fConst55 = (((fConst38 - fConst40) / fConst37) + 1.0f);
        fConst56 = (157.079636f / fConst39);
        fConst57 = (((fConst38 + fConst56) / fConst37) + 1.0f);
        fConst58 = (((fConst38 - fConst56) / fConst37) + 1.0f);
        fConst59 = (((fConst32 - fConst34) / fConst31) + 1.0f);
        fConst60 = (466.723724f / fConst33);
        fConst61 = (((fConst32 + fConst60) / fConst31) + 1.0f);
        fConst62 = (((fConst32 - fConst60) / fConst31) + 1.0f);
        fConst63 = (((fConst26 - fConst28) / fConst25) + 1.0f);
        fConst64 = (2218.80884f / fConst27);
        fConst65 = (((fConst26 + fConst64) / fConst25) + 1.0f);
        fConst66 = (((fConst26 - fConst64) / fConst25) + 1.0f);
        fConst67 = (((fConst20 - fConst22) / fConst19) + 1.0f);
        fConst68 = (3141.59277f / fConst21);
        fConst69 = (((fConst20 + fConst68) / fConst19) + 1.0f);
        fConst70 = (((fConst20 - fConst68) / fConst19) + 1.0f);
        fConst71 = (((fConst13 - fConst15) / fConst12) + 1.0f);
        fConst72 = (3955.03076f / fConst14);
        fConst73 = (((fConst13 + fConst72) / fConst12) + 1.0f);
        fConst74 = (((fConst13 - fConst72) / fConst12) + 1.0f);
        fConst75 = (1.0f / fConst7);
        fConst76 = (((fConst6 + -1.0f) / fConst5) + 1.0f);
        fConst77 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fConst5))));
        
    }
    
    virtual void instanceResetUserInterface() {
        fVslider0 = FAUSTFLOAT(100.0f);
        fHslider0 = FAUSTFLOAT(0.0f);
        fVslider1 = FAUSTFLOAT(50.0f);
        fHslider1 = FAUSTFLOAT(4.0f);
        fHslider2 = FAUSTFLOAT(120.0f);
        fHslider3 = FAUSTFLOAT(0.0f);
        fHslider4 = FAUSTFLOAT(12000.0f);
        fHslider5 = FAUSTFLOAT(120.0f);
        fVslider2 = FAUSTFLOAT(50.0f);
        
    }
    
    virtual void instanceClear() {
        for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
            fRec1[l0] = 0.0f;
            
        }
        for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
            fRec2[l1] = 0.0f;
            
        }
        for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
            fRec3[l2] = 0.0f;
            
        }
        for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
            fRec4[l3] = 0.0f;
            
        }
        for (int l4 = 0; (l4 < 3); l4 = (l4 + 1)) {
            fRec6[l4] = 0.0f;
            
        }
        for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
            fRec5[l5] = 0.0f;
            
        }
        for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
            fVec0[l6] = 0.0f;
            
        }
        for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
            fRec15[l7] = 0.0f;
            
        }
        for (int l8 = 0; (l8 < 3); l8 = (l8 + 1)) {
            fRec14[l8] = 0.0f;
            
        }
        for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
            fRec13[l9] = 0.0f;
            
        }
        for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
            fRec12[l10] = 0.0f;
            
        }
        for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
            fRec11[l11] = 0.0f;
            
        }
        for (int l12 = 0; (l12 < 3); l12 = (l12 + 1)) {
            fRec10[l12] = 0.0f;
            
        }
        for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
            fRec9[l13] = 0.0f;
            
        }
        for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
            fVec1[l14] = 0.0f;
            
        }
        for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
            fRec8[l15] = 0.0f;
            
        }
        for (int l16 = 0; (l16 < 3); l16 = (l16 + 1)) {
            fRec7[l16] = 0.0f;
            
        }
        for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
            fRec22[l17] = 0.0f;
            
        }
        for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
            fRec20[l18] = 0.0f;
            
        }
        for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
            fRec18[l19] = 0.0f;
            
        }
        for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
            fRec16[l20] = 0.0f;
            
        }
        for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
            fRec30[l21] = 0.0f;
            
        }
        for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
            fRec28[l22] = 0.0f;
            
        }
        for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
            fRec26[l23] = 0.0f;
            
        }
        for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
            fRec24[l24] = 0.0f;
            
        }
        IOTA = 0;
        for (int l25 = 0; (l25 < 1048576); l25 = (l25 + 1)) {
            fVec2[l25] = 0.0f;
            
        }
        for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
            fRec0[l26] = 0.0f;
            
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
        ui_interface->openVerticalBox("Digital Delay");
        ui_interface->declare(&fHslider0, "tooltip", "Freeze the current delay");
        ui_interface->addHorizontalSlider("Freeze", &fHslider0, 0.0f, 0.0f, 1.0f, 1.0f);
        ui_interface->declare(&fHslider2, "name", "delay (bpm)");
        ui_interface->declare(&fHslider2, "tooltip", "Delay in Beats per Minute");
        ui_interface->addHorizontalSlider("bpm", &fHslider2, 120.0f, 24.0f, 360.0f, 1.0f);
        ui_interface->declare(&fVslider2, "tooltip", "percentage of the feedback level in the delay loop");
        ui_interface->addVerticalSlider("feedback", &fVslider2, 50.0f, 1.0f, 100.0f, 1.0f);
        ui_interface->declare(&fVslider0, "tooltip", "overall gain of the delay line in percent");
        ui_interface->addVerticalSlider("gain", &fVslider0, 100.0f, 0.0f, 120.0f, 1.0f);
        ui_interface->declare(&fHslider5, "name", "highpass (hz)");
        ui_interface->declare(&fHslider5, "tooltip", "highpass filter frequency in the feddback loop");
        ui_interface->addHorizontalSlider("highpass", &fHslider5, 120.0f, 20.0f, 20000.0f, 1.0f);
        ui_interface->declare(&fHslider4, "name", "lowpass (hz)");
        ui_interface->declare(&fHslider4, "tooltip", "lowpass filter frequency in the feddback loop");
        ui_interface->addHorizontalSlider("howpass", &fHslider4, 12000.0f, 20.0f, 20000.0f, 1.0f);
        ui_interface->declare(&fVslider1, "tooltip", "percentage of the delay gain level");
        ui_interface->addVerticalSlider("level", &fVslider1, 50.0f, 1.0f, 100.0f, 1.0f);
        ui_interface->declare(&fHslider3, "enum", "plain|presence|tape|tape2");
        ui_interface->addHorizontalSlider("mode", &fHslider3, 0.0f, 0.0f, 3.0f, 1.0f);
        ui_interface->declare(&fHslider1, "enum", "Dotted 1/2 note|1/2 note|1/2 note triplets| Dotted 1/4 note|1/4 note|1/4 note triplets|Dotted 1/8 note|1/8 note|1/8 note triplets| Dotted 1/16 note|1/16 note|1/16 note triplets|Dotted 1/32 note|1/32 note|1/32 note triplets| Dotted 1/64 note|1/64 note|1/64 note triplets");
        ui_interface->declare(&fHslider1, "name", "tact");
        ui_interface->declare(&fHslider1, "tooltip", "note setting for bpm");
        ui_interface->addHorizontalSlider("notes", &fHslider1, 4.0f, 0.0f, 17.0f, 1.0f);
        ui_interface->closeBox();
        
    }
    
    virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
        FAUSTFLOAT* input0 = inputs[0];
        FAUSTFLOAT* output0 = outputs[0];
        float fSlow0 = (0.00999999978f * float(fVslider0));
        float fSlow1 = float(fHslider0);
        int iSlow2 = int(fSlow1);
        float fSlow3 = (0.00999999978f * float(fVslider1));
        float fSlow4 = std::min<float>(524288.0f, float(B2N(int(float(fHslider1)), float((fConst1 / float(fHslider2))))));
        float fSlow5 = float(fHslider3);
        int iSlow6 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fSlow5 + -2.0f))));
        int iSlow7 = (iSlow6 == 0);
        int iSlow8 = (iSlow6 == 1);
        int iSlow9 = int(std::min<float>(2.0f, std::max<float>(0.0f, (fSlow5 + -1.0f))));
        int iSlow10 = (iSlow9 == 0);
        int iSlow11 = (iSlow9 == 1);
        int iSlow12 = int(std::min<float>(2.0f, std::max<float>(0.0f, fSlow5)));
        int iSlow13 = (iSlow12 == 0);
        int iSlow14 = (iSlow12 == 1);
        float fSlow15 = std::tan((fConst4 * float(fHslider4)));
        float fSlow16 = (1.0f / fSlow15);
        float fSlow17 = (((fSlow16 + 1.41421354f) / fSlow15) + 1.0f);
        float fSlow18 = (1.0f / fSlow17);
        float fSlow19 = std::tan((fConst4 * float(fHslider5)));
        float fSlow20 = (1.0f / fSlow19);
        float fSlow21 = (1.0f / (((fSlow20 + 1.41421354f) / fSlow19) + 1.0f));
        float fSlow22 = MacallaDSP_faustpower2_f(fSlow19);
        float fSlow23 = (1.0f / fSlow22);
        float fSlow24 = (0.00999999978f * float(fVslider2));
        float fSlow25 = (((fSlow20 + -1.41421354f) / fSlow19) + 1.0f);
        float fSlow26 = (2.0f * (1.0f - fSlow23));
        float fSlow27 = (0.0f - (2.0f / fSlow22));
        float fSlow28 = (((fSlow16 + -1.41421354f) / fSlow15) + 1.0f);
        float fSlow29 = (2.0f * (1.0f - (1.0f / MacallaDSP_faustpower2_f(fSlow15))));
        float fSlow30 = (fConst44 / fSlow17);
        float fSlow31 = (1.0f - fSlow1);
        for (int i = 0; (i < count); i = (i + 1)) {
            float fTemp0 = float(input0[i]);
            float fTemp1 = ((fRec1[1] != 0.0f)?(((fRec2[1] > 0.0f) & (fRec2[1] < 1.0f))?fRec1[1]:0.0f):(((fRec2[1] == 0.0f) & (fSlow4 != fRec3[1]))?fConst2:(((fRec2[1] == 1.0f) & (fSlow4 != fRec4[1]))?fConst3:0.0f)));
            fRec1[0] = fTemp1;
            fRec2[0] = std::max<float>(0.0f, std::min<float>(1.0f, (fRec2[1] + fTemp1)));
            fRec3[0] = (((fRec2[1] >= 1.0f) & (fRec4[1] != fSlow4))?fSlow4:fRec3[1]);
            fRec4[0] = (((fRec2[1] <= 0.0f) & (fRec3[1] != fSlow4))?fSlow4:fRec4[1]);
            fRec6[0] = ((fSlow24 * fRec0[1]) - (fSlow21 * ((fSlow25 * fRec6[2]) + (fSlow26 * fRec6[1]))));
            fRec5[0] = ((fSlow21 * (((fSlow23 * fRec6[0]) + (fSlow27 * fRec6[1])) + (fSlow23 * fRec6[2]))) - (fSlow18 * ((fSlow28 * fRec5[2]) + (fSlow29 * fRec5[1]))));
            float fTemp2 = (fRec5[2] + (fRec5[0] + (2.0f * fRec5[1])));
            float fTemp3 = (fSlow18 * fTemp2);
            fVec0[0] = fTemp3;
            fRec15[0] = ((fConst49 * fVec0[1]) - (fConst50 * ((fConst51 * fRec15[1]) - (fSlow30 * fTemp2))));
            fRec14[0] = (fRec15[0] - (fConst45 * ((fConst52 * fRec14[2]) + (fConst53 * fRec14[1]))));
            float fTemp4 = (fConst42 * fRec13[1]);
            fRec13[0] = ((fConst45 * (((fConst47 * fRec14[0]) + (fConst54 * fRec14[1])) + (fConst47 * fRec14[2]))) - (fConst41 * (fTemp4 + (fConst55 * fRec13[2]))));
            float fTemp5 = (fConst36 * fRec12[1]);
            fRec12[0] = ((fConst41 * ((fTemp4 + (fConst57 * fRec13[0])) + (fConst58 * fRec13[2]))) - (fConst35 * (fTemp5 + (fConst59 * fRec12[2]))));
            float fTemp6 = (fConst30 * fRec11[1]);
            fRec11[0] = ((fConst35 * ((fTemp5 + (fConst61 * fRec12[0])) + (fConst62 * fRec12[2]))) - (fConst29 * (fTemp6 + (fConst63 * fRec11[2]))));
            float fTemp7 = (fConst24 * fRec10[1]);
            fRec10[0] = ((fConst29 * ((fTemp6 + (fConst65 * fRec11[0])) + (fConst66 * fRec11[2]))) - (fConst23 * (fTemp7 + (fConst67 * fRec10[2]))));
            float fTemp8 = (fConst17 * fRec9[1]);
            fRec9[0] = ((fConst23 * ((fTemp7 + (fConst69 * fRec10[0])) + (fConst70 * fRec10[2]))) - (fConst16 * (fTemp8 + (fConst71 * fRec9[2]))));
            float fTemp9 = ((fTemp8 + (fConst73 * fRec9[0])) + (fConst74 * fRec9[2]));
            fVec1[0] = fTemp9;
            fRec8[0] = (0.0f - (fConst9 * ((fConst10 * fRec8[1]) - (fConst16 * (fTemp9 + fVec1[1])))));
            fRec7[0] = (fRec8[0] - (fConst75 * ((fConst76 * fRec7[2]) + (fConst77 * fRec7[1]))));
            float fTemp10 = (iSlow13?fTemp3:(iSlow14?(fConst8 * (fRec7[2] + (fRec7[0] + (2.0f * fRec7[1])))):fTemp3));
            float fTemp11 = (0.200000003f * fRec18[1]);
            float fTemp12 = (0.100000001f * fRec16[1]);
            float fTemp13 = ((0.400000006f * fRec20[1]) + fTemp12);
            float fTemp14 = ((fTemp11 + (fTemp10 + (0.600000024f * fRec22[1]))) - fTemp13);
            fRec22[0] = fTemp14;
            float fRec23 = (0.0f - (0.600000024f * fTemp14));
            fRec20[0] = (fRec23 + fRec22[1]);
            float fTemp15 = (fTemp10 + fTemp11);
            float fRec21 = (0.400000006f * (fTemp15 - fTemp13));
            fRec18[0] = (fRec21 + fRec20[1]);
            float fRec19 = (0.0f - (0.200000003f * (fTemp15 - fTemp12)));
            fRec16[0] = (fRec19 + fRec18[1]);
            float fRec17 = (0.100000001f * (fTemp10 - fTemp12));
            float fTemp16 = (iSlow10?fTemp10:(iSlow11?(fRec17 + fRec16[1]):fTemp10));
            float fTemp17 = (0.300000012f * fRec28[1]);
            float fTemp18 = (0.5f * fRec24[1]);
            float fTemp19 = ((0.400000006f * fRec26[1]) + fTemp18);
            float fTemp20 = ((fTemp17 + (fTemp16 + (0.200000003f * fRec30[1]))) - fTemp19);
            fRec30[0] = fTemp20;
            float fRec31 = (0.0f - (0.200000003f * fTemp20));
            fRec28[0] = (fRec31 + fRec30[1]);
            float fRec29 = (0.0f - (0.300000012f * ((fTemp16 + fTemp17) - fTemp19)));
            fRec26[0] = (fRec29 + fRec28[1]);
            float fRec27 = (0.400000006f * (fTemp16 - fTemp19));
            fRec24[0] = (fRec27 + fRec26[1]);
            float fRec25 = (0.5f * (fTemp16 - fTemp18));
            float fTemp21 = ((iSlow2?fRec0[1]:(iSlow7?fTemp16:(iSlow8?(fRec25 + fRec24[1]):fTemp16))) + (fSlow31 * fTemp0));
            fVec2[(IOTA & 1048575)] = fTemp21;
            float fTemp22 = (((1.0f - fRec2[0]) * fVec2[((IOTA - int(std::min<float>(524288.0f, std::max<float>(0.0f, fRec3[0])))) & 1048575)]) + (fRec2[0] * fVec2[((IOTA - int(std::min<float>(524288.0f, std::max<float>(0.0f, fRec4[0])))) & 1048575)]));
            fRec0[0] = (iSlow2?fTemp22:(fSlow3 * fTemp22));
            output0[i] = FAUSTFLOAT((fTemp0 + (fSlow0 * (fRec0[0] + (fSlow1 * fTemp0)))));
            fRec1[1] = fRec1[0];
            fRec2[1] = fRec2[0];
            fRec3[1] = fRec3[0];
            fRec4[1] = fRec4[0];
            fRec6[2] = fRec6[1];
            fRec6[1] = fRec6[0];
            fRec5[2] = fRec5[1];
            fRec5[1] = fRec5[0];
            fVec0[1] = fVec0[0];
            fRec15[1] = fRec15[0];
            fRec14[2] = fRec14[1];
            fRec14[1] = fRec14[0];
            fRec13[2] = fRec13[1];
            fRec13[1] = fRec13[0];
            fRec12[2] = fRec12[1];
            fRec12[1] = fRec12[0];
            fRec11[2] = fRec11[1];
            fRec11[1] = fRec11[0];
            fRec10[2] = fRec10[1];
            fRec10[1] = fRec10[0];
            fRec9[2] = fRec9[1];
            fRec9[1] = fRec9[0];
            fVec1[1] = fVec1[0];
            fRec8[1] = fRec8[0];
            fRec7[2] = fRec7[1];
            fRec7[1] = fRec7[0];
            fRec22[1] = fRec22[0];
            fRec20[1] = fRec20[0];
            fRec18[1] = fRec18[0];
            fRec16[1] = fRec16[0];
            fRec30[1] = fRec30[0];
            fRec28[1] = fRec28[0];
            fRec26[1] = fRec26[0];
            fRec24[1] = fRec24[0];
            IOTA = (IOTA + 1);
            fRec0[1] = fRec0[0];
            
        }
        
    }
    
    
};


#endif

