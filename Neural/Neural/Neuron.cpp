#include "stdafx.h"
#include <stdlib.h>
#include "Neuron.h"
#include <math.h>
#include <random>

//�j���[�����̓��I����
Neuron *Neuron_New(int size, int prevSize) {
	Neuron *neuron;
	int i;
	
	neuron = (Neuron*)calloc(size, sizeof(Neuron));
	//�o�C�A�X[0]�ȊO�̃j���[�����̂��ׂĂ̓��͂ɑ΂���E�F�C�g��ݒ�
	for (i = 1; i < size; i++) {
		neuron[i].w = Weight_New(prevSize);
	}
	Neuron_Init(neuron);
	return neuron;
}

//�j���[�����̏�����
void Neuron_Init(Neuron *neuron) {
	
	neuron[0].out = 1;//�o�C�A�X

}

//�d���̐���(0�ŏ�����)
double *Weight_New(int weightSize) {
	double *d;

	d = (double*)calloc(weightSize, sizeof(double));//�������m�ہ@���ׂ�0�ŏ�����
	return d;
}

double sigmoid(double in) {
	return 1 / (1 + exp(-in));
}

double d_sigmoid(double in) {
	return exp(-in)*(1 - exp(-in));
}