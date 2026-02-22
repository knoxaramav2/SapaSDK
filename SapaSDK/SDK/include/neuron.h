#pragma once

#include "position.h"

/*
	Defines basic neural structures and interfaces
*/

namespace SAPA {

	class INeuron {
	protected:
		POINT Point;
	public:
		INeuron();
		~INeuron();
	};

	class Neuron : INeuron {

	protected:

	public:

		Neuron();
		~Neuron();

	};

}