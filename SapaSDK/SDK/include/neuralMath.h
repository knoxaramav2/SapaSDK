#pragma once

#include "hh_const.h"

#include <cmath>

namespace SAPA::SDK {

	enum ION_TYPE {
		CALCIUM, CHLORIDE, POTASSIUM, SODIUM
	};

	// Boltzmann equations for ion channel dynamics

	float calc_An(float voltage) {
		return (float)(0.01 * (voltage + 50.0f)) / (1.0f - exp((-(voltage + 50.0f) / 10.0f)));
	}

	float calc_Bn(float voltage) {
		return 0.125f * exp(-(voltage + 60.0f) / 80.0f);
	}

	float calc_Am(float voltage) {
		return (0.1 * (voltage + 35.0f)) / (1.0f - exp((-(voltage + 35.0f) / 10.0f)));
	}

	float calc_Bm(float voltage) {
		return 4.0f * exp(-0.0556f*(voltage + 60.0f));
	}

	float calc_Ah(float voltage) {
		return 0.07f * exp(-0.05f * (voltage + 60.0f));
	}

	float calc_Bh(float voltage) {
		return 1.0f / (1.0f + exp(-0.1f * (voltage + 30.0f)));
	}

	//delta helpers
	float calc_dndt(float voltage, float kActivation) {
		return ((calc_An(voltage) * (1.0f - kActivation)) - (calc_Bn(voltage) * kActivation)) * TIME_INTERVAL;
	}

	float calc_dmdt(float voltage, float naActivation) {
		return ((calc_Am(voltage) * (1.0f - naActivation)) - (calc_Bm(voltage) * naActivation)) * TIME_INTERVAL;
	}

	float calc_dhdt(float voltage, float naDeactivation) {
		return ((calc_Ah(voltage) * (1.0f - naDeactivation)) - (calc_Bh(voltage) * naDeactivation)) * TIME_INTERVAL;
	}

	float calc_dvdt(float i0, float i1, float iExt) {
		return (0.001 / HH_CM) * (i0-i1+iExt);
	}


	//calculations
	float calc_current(float voltage, float kActivation, float naActivation, float naDeactivation) {
		return (
			(HH_GNa*powf(naActivation, 3) * naDeactivation * (voltage-HH_ENa)) -
			(HH_GK*powf(kActivation, 4) * (voltage-HH_EK)) -
			(HH_GL*(voltage-HH_EL))
			);
	}

	float nerst(ION_TYPE type, float inflow_concentration, float outflow_concentration) {
		float ionCharge = type == CALCIUM ? 30.75f : 61.50f;
		float charge = ionCharge * log10(inflow_concentration / outflow_concentration);
		return type == CHLORIDE ? -charge : charge;
	}

}

