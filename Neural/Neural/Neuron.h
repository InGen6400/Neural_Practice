#pragma once

struct _Neuron
{
	double out;
	double sum;
	double DELTA;
	double *w;
}typedef Neuron;

Neuron *Neuron_New(int size, int prevSize);

void Neuron_Init(Neuron *neuron);

double *Weight_New(int weightSize);

double sigmoid(double in);

double ReLU(double in);

double d_ReLU(double in);