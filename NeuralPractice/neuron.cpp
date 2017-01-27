#include "stdafx.h"
#include "neuron.h"
#include <math.h>
#include <random>

void Neuron_New(Neuron *neuron, int count, int prevCount) {

	neuron = (Neuron*)calloc(count + 1, sizeof(Neuron));
	neuron->wheight = (double*)calloc(prevCount, sizeof(double));
	
}

void Neuron_Init(Neuron *neuron, int count, int prevCount) {
	int i;	

	//乱数生成
	std::random_device rnd1;
	std::mt19937 rnd(rnd1());
	std::uniform_real_distribution<> rand01(0, 1);

	for (i = 0; i < prevCount; i++) {
		neuron->wheight[i] = rand01(rnd);//0~1のメルセンヌツイスタ乱数
	}
}

//シグモイド関数
double sigmoid(double input) {
	return 1 / (1 + exp(-input));
}

//シグモイドの微分関数
double d_sigmoid(double input) {
	return (1 - sigmoid(input))*sigmoid(input);
}