#include "structure.h"

#include <algorithm>

namespace SAPA
{
	IDendrite::IDendrite(INeuron* source, INeuron* target) 
		: _source(source), _target(target)
	{
		
	}

	IDendrite::~IDendrite()
	{

	}

	void IDendrite::Update()
	{

	}

	bool IDendrite::IsIdentical(INeuron* source, INeuron* target)
	{
		return _source == source && _target == target;
	}


	bool INeuroStruct::AddSynapse(INeuron* source, INeuron* target)
	{
		if (std::any_of(_synapses.begin(), _synapses.end(),
			[source, target](IDendrite& d) {
				return d.IsIdentical(source, target);
			})) {
			return false;
		}

		_synapses.emplace_back(source, target);
		return true;
	}

	bool INeuroStruct::RemoveSynapse(INeuron* source, INeuron* target)
	{
		auto itr = std::find_if(_synapses.begin(), _synapses.end(), [source, target](IDendrite& dendrite) {
			return dendrite.IsIdentical(source, target);
			});

		if (itr == _synapses.end())
		{
			return false;
		}

		_synapses.erase(itr);
		return true;
	}

	INeuroStruct::INeuroStruct(unsigned numInputs, unsigned numOutputs, bool synapticPlasticityEnabled)
		: _numInputs(numInputs), _numOutputs(numOutputs)
	{
		this->_synapticPlasticityEnabled = synapticPlasticityEnabled;

		_inputs = new INeuron[numInputs];
		_outputs = new INeuron[numOutputs];
	}

	INeuroStruct::~INeuroStruct()
	{
		delete[] _inputs;
		delete[] _outputs;
	}

	short INeuroStruct::MapInput(unsigned index, INeuron* source)
	{
		if (index >= _numInputs) {
			return -1;
		}

		return AddSynapse(source, &_inputs[index]);
	}

	short INeuroStruct::MapOutput(unsigned index, INeuron* target)
	{
		if (index >= _numOutputs) {
			return -1;
		}

		return AddSynapse(target, &_outputs[index]);
	}

	short INeuroStruct::DisconnectInput(unsigned index, INeuron* source)
	{
		if (index >= _numInputs) {
			return -1;
		}

		return RemoveSynapse(source, &_inputs[index]);
	}

	short INeuroStruct::DisconnectOutput(unsigned index, INeuron* target)
	{
		if (index >= _numOutputs) {
			return -1;
		}

		return RemoveSynapse(target, &_outputs[index]);
	}
}

