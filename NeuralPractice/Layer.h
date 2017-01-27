#pragma once
#include "neuron.h"

struct _Layer {
	int count;
	Neuron *unit;
}typedef Layer;

Layer *Layer_New(int neuronCount);

void Layer_Init(Layer *layer);

void Layer_Delete(Layer *layer);

void Layer_CalcNeuron(const Layer *prevLayer, Layer *layer);