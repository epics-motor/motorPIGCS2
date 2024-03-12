/*
FILENAME...     PIGCS2PiezoCL.h
 
*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************
 

Augusto Horita and Guilherme Rodrigues de Lima
Mar 01, 2024

*/

#ifndef PI_GCS2CLPARAMS_INCLUDED_
#define PI_GCS2CLPARAMS_INCLUDED_

#include <algorithm>
#include <string>


#define PIGCS2_CL_PARAM_QTT ((sizeof(PIGCS2PiezoCLParams)/sizeof(int))/2)

#define PI_X_CL_IDX     0
#define PI_Y_CL_IDX     1
#define PI_Z_CL_IDX     2

// ------------- X Axis Closed loop Parameters -------------

#define KP_String                   "PI_SUP_KP"
#define KI_String		            "PI_SUP_KI"         // I-term Gain
#define KFF_String		            "PI_SUP_KFF"        // Feed Foward Gain
#define NTCHFR1_String              "PI_SUP_NTCHFR1"    // Notch frequncy 1
#define NTCHFR2_String              "PI_SUP_NTCHFR2"    // Notch frequncy 2
#define NTCHRJT1_String             "PI_SUP_NTCHRJT1"   // Notch reject 1
#define NTCHRJT2_String             "PI_SUP_NTCHRJT2"   // Notch reject 2
#define NTCHBDWDT1_String           "PI_SUP_NTCHBDWDT1" // Notch bandwidth 1
#define NTCHBDWDT2_String           "PI_SUP_NTCHBDWDT2" // Notch bandwidth 2
#define RBKP_String		            "PI_SUP_RBKP"
#define RBKI_String		            "PI_SUP_RBKI"
#define RBKFF_String		        "PI_SUP_RBKFF"
#define RBNTCHFR1_String            "PI_SUP_RBNTCHFR1"
#define RBNTCHFR2_String            "PI_SUP_RBNTCHFR2"
#define RBNTCHRJT1_String           "PI_SUP_RBNTCHRJT1"
#define RBNTCHRJT2_String           "PI_SUP_RBNTCHRJT2"
#define RBNTCHBDWDT1_String         "PI_SUP_RBNTCHBDWDT1"
#define RBNTCHBDWDT2_String         "PI_SUP_RBNTCHBDWDT2"
#define RBONT_String                "PI_SUP_RBONT"
#define RBOVF_String                "PI_SUP_RBOVF"
#define ANALOGTARGET_String         "PI_SUP_ANALOGTARGET"
#define RBANALOGTARGET_String       "PI_SUP_RBANALOGTARGET"

typedef struct PIGCS2PiezoCLValues{

    int PI_SUP_RBONT;
    int PI_SUP_RBOVF;

}PIGCS2PiezoCLValues;

typedef struct PIGCS2PiezoCLParams{
    int PI_SUP_KP;
    int PI_SUP_KI;
    int PI_SUP_KFF;
    int PI_SUP_NTCHFR1;
    int PI_SUP_NTCHFR2;
    int PI_SUP_NTCHRJT1;
    int PI_SUP_NTCHRJT2;
    int PI_SUP_NTCHBDWDT1;
    int PI_SUP_NTCHBDWDT2;
    int PI_SUP_ANALOGTARGET;
    int PI_SUP_RBKP;
    int PI_SUP_RBKI;
    int PI_SUP_RBKFF;
    int PI_SUP_RBNTCHFR1;
    int PI_SUP_RBNTCHFR2;
    int PI_SUP_RBNTCHRJT1;
    int PI_SUP_RBNTCHRJT2;
    int PI_SUP_RBNTCHBDWDT1;
    int PI_SUP_RBNTCHBDWDT2;
    int PI_SUP_RBANALOGTARGET;
}PIGCS2PiezoCLParams;


typedef union u_PIGCS2PiezoCLParams
{
    PIGCS2PiezoCLParams CLParams_str;
    int CLParams_arr[PIGCS2_CL_PARAM_QTT*2];    // Params AND Readback
}u_PIGCS2PiezoCLParams;


namespace PI727_CL_PARAM_ADDR
{
    enum CL_PARAM
    {
        KP			    = 0x07000300UL,
        KI			    = 0x07000301UL,
        KFF             = 0x07030600UL,
        NOTCHFREQ1      = 0x08000100UL,
        NOTCHFREQ2      = 0x08000101UL,
        NOTCHREJEC1     = 0x07000200UL,
        NOTCHREJEC2     = 0x07000201UL,
        NOTCHBDWDT1     = 0x08000300UL,
        NOTCHBDWDT2     = 0x08000301UL,
        ANALOGCHANNEL   = 0x06000500,
    };

    static const CL_PARAM All[] = { KP , KI , KFF , NOTCHFREQ1 , NOTCHFREQ2 , \
                                    NOTCHREJEC1 , NOTCHREJEC2 , NOTCHBDWDT1 , NOTCHBDWDT2, ANALOGCHANNEL };
}


#endif // PI_GCS2CLPARAMS_INCLUDED_