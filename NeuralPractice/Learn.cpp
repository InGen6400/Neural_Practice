#include "stdafx.h"
#include "neuron.h"
#include "Layer.h"

void Learn() {

	Layer *inputLayer;
	Layer *hiddenLayer;
	Layer *outLayer;
	double input = 1;

	inputLayer = Layer_New(INPUT_NUM, 0);
	hiddenLayer = Layer_New(HIDE_NUM, INPUT_NUM);
	outLayer = Layer_New(OUT_NUM, HIDE_NUM);

	Layer_InitAsInput(inputLayer, &input);

	Layer_CalcNeuron(hiddenLayer, inputLayer);
	Layer_CalcNeuron(outLayer, hiddenLayer);



}