#include "stdafx.h"
#include <stdlib.h>
#include "Neuron.h"
#include <math.h>
#include <random>

//ニューロンの動的生成
Neuron *Neuron_New(int size, int prevSize) {
	Neuron *neuron;
	int i;
	
	neuron = (Neuron*)calloc(size, sizeof(Neuron));
	//バイアス[0]以外のニューロンのすべての入力に対するウェイトを設定
	for (i = 1; i < size; i++) {
		neuron[i].w = Weight_New(prevSize);
	}
	Neuron_Init(neuron);
	return neuron;
}

//ニューロンの初期化
void Neuron_Init(Neuron *neuron) {
	
	neuron[0].out = 1;//バイアス

}

//重さの生成(0で初期化)
double *Weight_New(int weightSize) {
	double *d;

	d = (double*)calloc(weightSize, sizeof(double));//メモリ確保　すべて0で初期化
	return d;
}

double sigmoid(double in) {
	return 1 / (1 + exp(-in));
}

double d_sigmoid(double in) {
	return exp(-in)*(1 - exp(-in));
}