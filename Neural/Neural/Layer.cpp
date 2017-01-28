#include "stdafx.h"
#include "Layer.h"
#include <stdlib.h>

//���C���[�̓��I����
Layer *Layer_New(int size, int prevSize) {
	Layer *layer;

	layer = (Layer*)malloc(sizeof(Layer));
	Layer_Init(layer, size, prevSize);

	return layer;
}

//���C���[�̏�����
void Layer_Init(Layer *layer, int size, int prevSize) {

	layer->size = size + 1;							//�j���[����(size) + �o�C�A�X�_�~�[(1)
	layer->Element = Neuron_New(size+1, prevSize);

}

//���͑w�̐ݒ�
void Layer_SetInput(Layer *layer, double *input) {
	int i;
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].out = input[i];
	}
}

//�w�̃j���[�����̏o�͂��v�Z����
void Layer_Calc(Layer *layer, Layer *prevLayer) {
	int i, j;
	double sum;
	//�j���[�����̌������[�v(�o�C�A�X�͏���)
	for (i = 1; i < layer->size; i++) {
		sum = 0;
		//�O�̑w�̃j���[�����̐��������[�v(�o�C�A�X���܂�)
		for (j = 0; j < prevLayer->size; j++) {
			sum += layer->Element[i].w[j] * prevLayer->Element[j].out;
		}
		layer->Element[i].out = sigmoid(sum);
	}

}

void Layer_Update() {

}