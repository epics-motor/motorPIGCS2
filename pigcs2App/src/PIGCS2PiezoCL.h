/*
FILENAME...     PIGCS2PiezoCL.h
 
*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************
 

Augusto Horita
August 03, 2022

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

#define KP_String           std::string("PI_SUP_KP_")
#define KI_String		    std::string("PI_SUP_KI_")         // I-term Gain
#define KFF_String		    std::string("PI_SUP_KFF_")        // Feed Foward Gain
#define NTCHFR1_String      std::string("PI_SUP_NTCHFR1_")    // Notch frequncy 1
#define NTCHFR2_String      std::string("PI_SUP_NTCHFR2_")    // Notch frequncy 2
#define NTCHRJT1_String     std::string("PI_SUP_NTCHRJT1_")   // Notch reject 1
#define NTCHRJT2_String     std::string("PI_SUP_NTCHRJT2_")   // Notch reject 2
#define NTCHBDWDT1_String   std::string("PI_SUP_NTCHBDWDT1_") // Notch bandwidth 1
#define NTCHBDWDT2_String   std::string("PI_SUP_NTCHBDWDT2_") // Notch bandwidth 2
#define RBKP_String		    std::string("PI_SUP_RBKP_")
#define RBKI_String		    std::string("PI_SUP_RBKI_")
#define RBKFF_String		std::string("PI_SUP_RBKFF_")
#define RBNTCHFR1_String    std::string("PI_SUP_RBNTCHFR1_")
#define RBNTCHFR2_String    std::string("PI_SUP_RBNTCHFR2_")
#define RBNTCHRJT1_String   std::string("PI_SUP_RBNTCHRJT1_")
#define RBNTCHRJT2_String   std::string("PI_SUP_RBNTCHRJT2_")
#define RBNTCHBDWDT1_String std::string("PI_SUP_RBNTCHBDWDT1_")
#define RBNTCHBDWDT2_String std::string("PI_SUP_RBNTCHBDWDT2_")

#define PI_SUP_KP_X_String  		  "PI_SUP_KP_X"         // P-term Gain
#define PI_SUP_KI_X_String		      "PI_SUP_KI_X"         // I-term Gain
#define PI_SUP_KFF_X_String		      "PI_SUP_KFF_X"        // Feed Foward Gain

#define PI_SUP_NTCHFR1_X_String       "PI_SUP_NTCHFR1_X"    // Notch frequncy 1
#define PI_SUP_NTCHFR2_X_String       "PI_SUP_NTCHFR2_X"    // Notch frequncy 2
#define PI_SUP_NTCHRJT1_X_String      "PI_SUP_NTCHRJT1_X"   // Notch reject 1
#define PI_SUP_NTCHRJT2_X_String      "PI_SUP_NTCHRJT2_X"   // Notch reject 2
#define PI_SUP_NTCHBDWDT1_X_String    "PI_SUP_NTCHBDWDT1_X" // Notch bandwidth 1
#define PI_SUP_NTCHBDWDT2_X_String    "PI_SUP_NTCHBDWDT2_X" // Notch bandwidth 2

// Readback variables
#define PI_SUP_RBKP_X_String		  "PI_SUP_RBKP_X"
#define PI_SUP_RBKI_X_String		  "PI_SUP_RBKI_X"
#define PI_SUP_RBKFF_X_String		  "PI_SUP_RBKFF_X"

#define PI_SUP_RBNTCHFR1_X_String     "PI_SUP_RBNTCHFR1_X"
#define PI_SUP_RBNTCHFR2_X_String     "PI_SUP_RBNTCHFR2_X"
#define PI_SUP_RBNTCHRJT1_X_String    "PI_SUP_RBNTCHRJT1_X"
#define PI_SUP_RBNTCHRJT2_X_String    "PI_SUP_RBNTCHRJT2_X"
#define PI_SUP_RBNTCHBDWDT1_X_String  "PI_SUP_RBNTCHBDWDT1_X"
#define PI_SUP_RBNTCHBDWDT2_X_String  "PI_SUP_RBNTCHBDWDT2_X"

// ------------- Y Axis Closed loop Parameters -------------
#define PI_SUP_KP_Y_String  		  "PI_SUP_KP_Y"
#define PI_SUP_KI_Y_String		      "PI_SUP_KI_Y"
#define PI_SUP_KFF_Y_String		      "PI_SUP_KFF_Y"

#define PI_SUP_NTCHFR1_Y_String       "PI_SUP_NTCHFR1_Y"
#define PI_SUP_NTCHFR2_Y_String       "PI_SUP_NTCHFR2_Y"
#define PI_SUP_NTCHRJT1_Y_String      "PI_SUP_NTCHRJT1_Y"
#define PI_SUP_NTCHRJT2_Y_String      "PI_SUP_NTCHRJT2_Y"
#define PI_SUP_NTCHBDWDT1_Y_String    "PI_SUP_NTCHBDWDT1_Y"
#define PI_SUP_NTCHBDWDT2_Y_String    "PI_SUP_NTCHBDWDT2_Y"

#define PI_SUP_RBKP_Y_String		  "PI_SUP_RBKP_Y"
#define PI_SUP_RBKI_Y_String		  "PI_SUP_RBKI_Y"
#define PI_SUP_RBKFF_Y_String		  "PI_SUP_RBKFF_Y"

#define PI_SUP_RBNTCHFR1_Y_String     "PI_SUP_RBNTCHFR1_Y"
#define PI_SUP_RBNTCHFR2_Y_String     "PI_SUP_RBNTCHFR2_Y"
#define PI_SUP_RBNTCHRJT1_Y_String    "PI_SUP_RBNTCHRJT1_Y"
#define PI_SUP_RBNTCHRJT2_Y_String    "PI_SUP_RBNTCHRJT2_Y"
#define PI_SUP_RBNTCHBDWDT1_Y_String  "PI_SUP_RBNTCHBDWDT1_Y"
#define PI_SUP_RBNTCHBDWDT2_Y_String  "PI_SUP_RBNTCHBDWDT2_Y"


// ------------- Z Axis Closed loop Parameters -------------
#define PI_SUP_KP_Z_String  		  "PI_SUP_KP_Z"
#define PI_SUP_KI_Z_String		      "PI_SUP_KI_Z"
#define PI_SUP_KFF_Z_String		      "PI_SUP_KFF_Z"

#define PI_SUP_NTCHFR1_Z_String       "PI_SUP_NTCHFR1_Z"
#define PI_SUP_NTCHFR2_Z_String       "PI_SUP_NTCHFR2_Z"
#define PI_SUP_NTCHRJT1_Z_String      "PI_SUP_NTCHRJT1_Z"
#define PI_SUP_NTCHRJT2_Z_String      "PI_SUP_NTCHRJT2_Z"
#define PI_SUP_NTCHBDWDT1_Z_String    "PI_SUP_NTCHBDWDT1_Z"
#define PI_SUP_NTCHBDWDT2_Z_String    "PI_SUP_NTCHBDWDT2_Z"

#define PI_SUP_RBKP_Z_String		  "PI_SUP_RBKP_Z"
#define PI_SUP_RBKI_Z_String		  "PI_SUP_RBKI_Z"
#define PI_SUP_RBKFF_Z_String		  "PI_SUP_RBKFF_Z"

#define PI_SUP_RBNTCHFR1_Z_String     "PI_SUP_RBNTCHFR1_Z"
#define PI_SUP_RBNTCHFR2_Z_String     "PI_SUP_RBNTCHFR2_Z"
#define PI_SUP_RBNTCHRJT1_Z_String    "PI_SUP_RBNTCHRJT1_Z"
#define PI_SUP_RBNTCHRJT2_Z_String    "PI_SUP_RBNTCHRJT2_Z"
#define PI_SUP_RBNTCHBDWDT1_Z_String  "PI_SUP_RBNTCHBDWDT1_Z"
#define PI_SUP_RBNTCHBDWDT2_Z_String  "PI_SUP_RBNTCHBDWDT2_Z"


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
    int PI_SUP_RBKP;
    int PI_SUP_RBKI;
    int PI_SUP_RBKFF;
    int PI_SUP_RBNTCHFR1;
    int PI_SUP_RBNTCHFR2;
    int PI_SUP_RBNTCHRJT1;
    int PI_SUP_RBNTCHRJT2;
    int PI_SUP_RBNTCHBDWDT1;
    int PI_SUP_RBNTCHBDWDT2;
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
    };

    static const CL_PARAM All[] = { KP , KI , KFF , NOTCHFREQ1 , NOTCHFREQ2 , \
                                    NOTCHREJEC1 , NOTCHREJEC2 , NOTCHBDWDT1 , NOTCHBDWDT2 };
}


#endif // PI_GCS2CLPARAMS_INCLUDED_