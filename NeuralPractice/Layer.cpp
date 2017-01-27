#include "stdafx.h"
#include "Layer.h"

Layer *Layer_New(int neuronCount) {
	Layer *layer;
	layer = (Layer*)malloc(sizeof(Layer));
	layer->unit = (Neuron*)calloc(neuronCount+1, sizeof(Neuron));
	layer->count = neuronCount+1;
	
	return layer;
}

void Layer_Init(Layer *layer) {
	layer->unit[0].out = 1;
}

void Layer_Delete(Layer *layer) {
	free(layer->unit);
	free(layer);
}

void Layer_CalcNeuron(const Layer *prevLayer, Layer *layer) {
	int i, j;
	double sum;
	Neuron *nowNeuron;

	//layer層のすべてのニューロンに対して
	for (i = 0; i < layer->count; i++) {

		sum = 0;
		nowNeuron = &layer->unit[i];
		//すべての入力ユニットに対して重みづけ　-> 総和
		for (j = 0; j < prevLayer->count; j++) {
			sum += *nowNeuron->wheight * prevLayer->unit[j].out;
		}
		//シグモイド関数で出力数値を得る
		nowNeuron->out = sigmoid(sum);

	}
}