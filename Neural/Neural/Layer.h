#pragma once
#include "Neuron.h"

struct _Layer
{
	int size;			//レイヤー内のニューロンの数(バイアスダミー含む)
	Neuron *Element;	//要素:ニューロンの配列
}typedef Layer;

Layer *Layer_New(int size, int prevSize);

void Layer_Init(Layer *layer, int size, int prevSize);

void Layer_SetInput(Layer *layer, double input);

void Layer_Calc(Layer *layer, Layer *prevLayer);

void Layer_Update(Layer *layer, const Layer *nextLayer, const Layer *prevLayer);

void OutLayer_Update(Layer *layer, const Layer *prevLayer, double delta);