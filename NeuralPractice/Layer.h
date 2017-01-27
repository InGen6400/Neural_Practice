#pragma once
#include "neuron.h"

struct _Layer {
	int count;
	Neuron *unit;
}typedef Layer;

Layer *Layer_New(int neuronCount, int prevCount);

void Layer_Init(Layer *layer);

void Layer_InitAsInput(Layer *layer, double *input);

void Layer_Delete(Layer *layer);

void Layer_CalcNeuron(Layer *layer, const Layer *prevLayer);