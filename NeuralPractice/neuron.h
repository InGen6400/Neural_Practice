#pragma once

const int INPUT_NUM = 10;
const int HIDE_NUM = 5;
const int OUT_NUM = 1;
const double eps = 0.1;

struct _Neuron {
	double out;					//�o��
	double *wheight;	//�E�F�C�g�@�d��
}typedef Neuron;

void Neuron_Init(Neuron *neuron, int count);

double sigmoid(double input);
