#pragma once

#include "hh_const.h"

#include <cmath>

namespace SAPA::HH {

	enum ION_TYPE {
		CALCIUM, CHLORIDE, POTASSIUM, SODIUM
	};

	//(De)Activation channel dynamics
	float calc_An(float voltage) {
		return (0.01 * (voltage + 50.0)) / (1.0 - exp((-(voltage + 50.0) / 10.0)));
	}

	float calc_Bn(float voltage) {
		return 0.125 * exp(-(voltage + 60.0) / 80.0);
	}

	float calc_Am(float voltage) {
		return (0.1 * (voltage + 35.0)) / (1.0 - exp((-(voltage + 35.0) / 10.0)));
	}

	float calc_Bm(float voltage) {
		return 4.0f * exp(-0.0556*(voltage + 60));
	}

	float calc_Ah(float voltage) {
		return 0.07f * exp(-0.05f * (voltage + 60.0));
	}

	float calc_Bh(float voltage) {
		return 1.0f / (1.0f + exp(-0.1f * (voltage + 30.0)));
	}

	//deltas 
	float calc_dndt(float voltage, float n) {
		return ((calc_An(voltage) * (1.0f - n)) - (calc_Bn(voltage) * n)) * TIME_INTERVAL;
	}

	float calc_dmdt(float voltage, float m) {
		return ((calc_Am(voltage) * (1.0f - m)) - (calc_Bm(voltage) * m)) * TIME_INTERVAL;
	}

	float calc_dhdt(float voltage, float h) {
		return ((calc_Ah(voltage) * (1.0f - h)) - (calc_Bh(voltage) * h)) * TIME_INTERVAL;
	}

	float calc_dvdt(float i0, float i1, float iExt) {
		return (0.001 / HH_CM) * (i0-i1+iExt);
	}


	//calculations
	float calc_current(float voltage, float n, float m, float h) {
		return (
			(HH_GNa*powf(m, 3) * h * (voltage-HH_ENa)) -
			(HH_GK*powf(n, 4) * (voltage-HH_EK)) -
			(HH_GL*(voltage-HH_EL))
			);
	}

	float nerst(ION_TYPE type, float inflow_concentration, float outflow_concentration) {
		float ionCharge = type == CALCIUM ? 30.75f : 61.50f;
		float charge = ionCharge * log10(inflow_concentration / outflow_concentration);
		return type == CHLORIDE ? -charge : charge;
	}

}

