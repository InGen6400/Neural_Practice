#pragma once

const int INPUT_NUM = 1;
const int HIDE_NUM = 5;
const int OUT_NUM = 1;
const double eps = 0.1;

struct _Neuron {
	double out;					//出力
	double *wheight;	//ウェイト　重み
}typedef Neuron;

Neuron *Neuron_New(int count, int prevCount);

void Neuron_Init(Neuron *neuron, int count, int prevCount);

double sigmoid(double input);
