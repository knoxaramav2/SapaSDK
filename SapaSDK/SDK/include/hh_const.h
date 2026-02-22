#pragma once

//Precaculated potential reversal potential constants for Hodgkin-Huxley model
#ifdef HH_DEF_Cm
const float HH_CM = HH_DEF_Cm;
#else
const float HH_CM = 0.01f;
#endif

#ifdef HH_DEF_ENa
const float HH_ENa = HH_DEF_ENa;
#else
const float HH_Ena = 55.17f;
#endif

#ifdef HH_DEF_EK
const float HH_EK = HH_DEF_EK;
#else
const float HH_EK = -72.14f;
#endif

#ifdef HH_DEF_EL
const float HH_EL = HH_DEF_EL;
#else
const float HH_EL = -49.42f;
#endif

//Ion conductivity constants
#ifdef HH_DEF_GNa
const float HH_GNa = HH_DEF_GNa;
#else
const float HH_GNa = 1.20f;
#endif

#ifdef HH_DEF_GK
const float HH_GK = HH_DEF_GK;
#else
const float HH_GK = 0.36f;
#endif

#ifdef HH_DEF_GL
const float HH_GL = HH_DEF_GL;
#else
const float HH_GL = 0.003f;
#endif