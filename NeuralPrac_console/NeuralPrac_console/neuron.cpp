#include "stdafx.h"
#include "neuron.h"
#include <math.h>
#include <random>

Neuron *Neuron_New(int count, int prevCount) {
	Neuron *neuron;
	int i;

	//�j���[�����������m��
	if ((neuron = (Neuron*)calloc(count + 1,sizeof(Neuron))) == NULL) {
		printf("neuron�������m�ێ��s\n");
	}

	//�d�ݔz��m��
	for (i = 1; i <= count; i++) {
		if ((neuron[i].wheight = (double*)calloc(prevCount + 1, sizeof(double))) == NULL) {
			printf("wheitht�������m�ێ��s\n");
			return NULL;
		}
	}


	Neuron_Init(neuron, count, prevCount);
	
	return neuron;
}

void Neuron_Init(Neuron *neuron, int count, int prevCount) {
	int i,j;	

	//��������
	std::random_device rnd1;
	std::mt19937 rnd(rnd1());
	std::uniform_real_distribution<> rand01(0, 1);

	for (i = 1; i <= count; i++) {
		for (j = 0; j < prevCount + 1; j++) {
			neuron[i].wheight[j] = rand01(rnd);//0~1�̃����Z���k�c�C�X�^����
			printf("neuron[%d].wheight[%d] :%f\n", i, j, neuron[i].wheight[j]);
		}
	}
	neuron[0].out = 1;
	putchar('\n');
}

//�V�O���C�h�֐�
double sigmoid(double input) {
	return 1 / (1 + exp(-input));
}

//�V�O���C�h�̔����֐�
double d_sigmoid(double input) {
	return (1 - sigmoid(input))*sigmoid(input);
}