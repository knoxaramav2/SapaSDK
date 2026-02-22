#pragma once

/*
	Defines neural structures
*/

#include "neuron.h"
#include "position.h"

#include <vector>

namespace SAPA
{

	class IDendrite {
		
	protected:
		INeuron* _source;
		INeuron* _target;
	public:
		IDendrite(INeuron* source, INeuron* target);
		~IDendrite();
		void Update();
		bool IsIdentical(INeuron* source, INeuron* target);
	};

	class Dendrite: IDendrite {

	};


	/// <summary>
	/// Base structure of neural network groups
	/// </summary>
	class INeuroStruct {

		bool AddSynapse(INeuron* source, INeuron* target);
		bool RemoveSynapse(INeuron* source, INeuron* target);

	protected:
		INeuron* _inputs;
		INeuron* _outputs;
		unsigned _numInputs;
		unsigned _numOutputs;
		std::vector<IDendrite> _synapses;

		bool _synapticPlasticityEnabled;

		/// <summary>
		/// Construct Neural Structure base class
		/// </summary>
		/// <param name="numInputs">Number of input neurons</param>
		/// <param name="numOutputs">Number of output neurons</param>
		/// <param name="synapticPlasticityEnabled">If true, allow new synapses to generate and prune over time</param>
		INeuroStruct(unsigned numInputs, unsigned numOutputs, bool synapticPlasticityEnabled);
		~INeuroStruct();

	public:
		virtual void UpdateInputs() = 0;
		virtual void UpdateOutputs() = 0;
		virtual void UpdateNodes() = 0;
		virtual void Maintain() = 0;

		virtual short MapInput(unsigned index, INeuron* source);
		virtual short MapOutput(unsigned index, INeuron* target);
		virtual short DisconnectInput(unsigned index, INeuron* source);
		virtual short DisconnectOutput(unsigned index, INeuron* target);
	};

	/// <summary>
	/// Basic neural group
	/// </summary>
	class Ganglion : INeuroStruct {
	
	public:
	
	};

}

