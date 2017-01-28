#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "Layer.h"

Layer *Layer_New(int neuronCount, int prevCount) {
	Layer *layer;
	layer = (Layer*)malloc(sizeof(Layer));
	layer->unit = Neuron_New(neuronCount, prevCount);

	//�j���[�����̐�+�o�C�A�X
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
	//layer�w�̂��ׂẴj���[�����ɑ΂���(�o�C�A�X�͏���)
	for (i = 1; i < layer->count; i++) {

		sum = 0;
		nowNeuron = &layer->unit[i];
		//���ׂĂ̓��̓��j�b�g�ɑ΂��ďd�݂Â��@-> ���a
		for (j = 0; j < prevLayer->count; j++) {
			
			sum += nowNeuron->wheight[j] * prevLayer->unit[j].out;
		}
		printf("sum:%f\n", sum);
		//�V�O���C�h�֐��ŏo�͐��l�𓾂�
		nowNeuron->out = sigmoid(sum);

	}
}