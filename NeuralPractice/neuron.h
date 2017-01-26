#pragma once

const int INPUT_NUM = 10;
const int HIDE_NUM = 5;
const int OUT_NUM = 1;
const double eps = 0.1;

struct _Neuron {
	double out;
	double bias[INPUT_NUM];
	double wheight[INPUT_NUM];
}typedef Neuron;

double sigmoid(double input);

void Neuron_Calc();