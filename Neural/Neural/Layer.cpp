#include "stdafx.h"
#include "Layer.h"
#include "Learn.h"
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
void Layer_SetInput(Layer *layer, double input) {
	int i;
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].out = input;
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
		layer->Element[i].sum = sum;
		layer->Element[i].out = ReLU(sum);
	}

}

//layer, prevL, w, prevout, Learn_c, delta
//DELTA = SUM(next_delta * next_w * d_sigmoid(sum)) (layer != output_layer)
void Layer_Update(Layer *layer, const Layer *nextLayer, const Layer *prevLayer) {

	int i, j, k;

	//((�o�C�A�X�ȊO)����Ȃ��đS���H)�Ǝv�������ǃo�C�A�X�ȊO�̃j���[�����ɂ��čX�V
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].DELTA = 0;
		//�o�C�A�X�ȊO
		//��DELTA[next] * w[i->next] * d_ReLU(sum)
		for (k = 1; k < nextLayer->size; k++) {
			layer->Element[i].DELTA += nextLayer->Element[k].DELTA * nextLayer->Element[k].w[i] * d_ReLU(layer->Element[i].sum);
		}
		//�o�C�A�X�ȊO�̓��͂̃E�F�C�g���X�V
		for (j = 1; j < prevLayer->size; j++) {
			layer->Element[i].w[j] -= LEARN_C * layer->Element[i].DELTA * prevLayer->Element[j].out;
			//printf("%d,%d : %f", i, j, layer->Element[i].w[j]);
		}
	}

}

//DELTA = (delta)*d_ReLU(sum) (layer == output_layer)
void OutLayer_Update(Layer *layer, const Layer *prevLayer , double delta) {

	int i, j;

	//�o�C�A�X�ȊO�̃j���[�����ɂ���
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].DELTA = delta * d_ReLU(layer->Element[i].sum);
		//���ׂĂ̓��͂̃E�F�C�g���X�V
		for (j = 0; j < prevLayer->size; j++) {
			layer->Element[i].w[j] -= LEARN_C * layer->Element[i].DELTA * prevLayer->Element[j].out;
		}
	}
}