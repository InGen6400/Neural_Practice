#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "Layer.h"

Layer *Layer_New(int neuronCount, int prevCount) {
	Layer *layer;
	layer = (Layer*)malloc(sizeof(Layer));
	layer->unit = Neuron_New(neuronCount, prevCount);

	//ニューロンの数+バイアス
	layer->count = neuronCount+1;
	Layer_Init(layer);
	return layer;
}

void Layer_Init(Layer *layer) {
}

void Layer_InitAsInput(Layer *inputlayer, double *input) {
	memcpy(&inputlayer->unit[1], input, sizeof(double) * INPUT_NUM);
}

void Layer_Delete(Layer *layer) {
	free(layer->unit);
	free(layer);
}

void Layer_CalcNeuron(Layer *layer, const Layer *prevLayer) {
	int i, j;
	double sum;
	Neuron *nowNeuron;

	printf("neu count:%d\n", layer->unit[0].out);
	//layer層のすべてのニューロンに対して(バイアスは除く)
	for (i = 1; i < layer->count; i++) {

		sum = 0;
		nowNeuron = &layer->unit[i];
		//すべての入力ユニットに対して重みづけ　-> 総和
		for (j = 0; j < prevLayer->count; j++) {
			
			sum += nowNeuron->wheight[j] * prevLayer->unit[j].out;
		}
		printf("sum:%f\n", sum);
		//シグモイド関数で出力数値を得る
		nowNeuron->out = sigmoid(sum);

	}
}