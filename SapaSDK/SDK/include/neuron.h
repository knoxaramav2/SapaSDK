#pragma once

#include "position.h"
#include "neuralMath.h"

/*
	Defines basic neural structures and interfaces
*/

namespace SAPA::SDK {

	//Base definitions
	class INeuron {
	protected:
		POINT _point;
		float _kActivation;
		float _naActivation;
		float _naDeactivation;
		float _charge;
	public:
		INeuron();
		INeuron(POINT point);
		~INeuron();
	};

	class Neuron : INeuron {

	protected:

	public:

		Neuron();
		~Neuron();

	};

	/// <summary>
	/// Used f
	/// </summary>
	class NeuronTemplate {



	};

	//Runtime provider / registration
	class NeuralRegistry {


	};

}