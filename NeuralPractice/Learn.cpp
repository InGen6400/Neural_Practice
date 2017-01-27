#include "stdafx.h"
#include "neuron.h"
#include "Layer.h"

void Learn() {

	Layer *inputLayer;
	Layer *hiddenLayer;
	Layer *outLayer;

	inputLayer = Layer_New(INPUT_NUM, 0);
	hiddenLayer = Layer_New(HIDE_NUM, INPUT_NUM);
	outLayer = Layer_New(OUT_NUM, HIDE_NUM);

	Layer_InitAsInput(inputLayer, );

	Layer_CalcNeuron(hiddenLayer, inputLayer);
	Layer_CalcNeuron(outLayer, hiddenLayer);

}