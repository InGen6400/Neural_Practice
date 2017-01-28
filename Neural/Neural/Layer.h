#pragma once
#include "Neuron.h"

struct _Layer
{
	int size;			//���C���[���̃j���[�����̐�(�o�C�A�X�_�~�[�܂�)
	Neuron *Element;	//�v�f:�j���[�����̔z��
}typedef Layer;

Layer *Layer_New(int size, int prevSize);

void Layer_Init(Layer *layer, int size, int prevSize);

void Layer_SetInput(Layer *layer, double input);

void Layer_Calc(Layer *layer, Layer *prevLayer);

void Layer_Update(Layer *layer, const Layer *nextLayer, const Layer *prevLayer);

void OutLayer_Update(Layer *layer, const Layer *prevLayer, double delta);