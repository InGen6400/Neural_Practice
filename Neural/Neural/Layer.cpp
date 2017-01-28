#include "stdafx.h"
#include "Layer.h"
#include <stdlib.h>

//レイヤーの動的生成
Layer *Layer_New(int size, int prevSize) {
	Layer *layer;

	layer = (Layer*)malloc(sizeof(Layer));
	Layer_Init(layer, size, prevSize);

	return layer;
}

//レイヤーの初期化
void Layer_Init(Layer *layer, int size, int prevSize) {

	layer->size = size + 1;							//ニューロン(size) + バイアスダミー(1)
	layer->Element = Neuron_New(size+1, prevSize);

}

//入力層の設定
void Layer_SetInput(Layer *layer, double *input) {
	int i;
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].out = input[i];
	}
}

//層のニューロンの出力を計算する
void Layer_Calc(Layer *layer, Layer *prevLayer) {
	int i, j;
	double sum;
	//ニューロンの個数分ループ(バイアスは除く)
	for (i = 1; i < layer->size; i++) {
		sum = 0;
		//前の層のニューロンの数だけループ(バイアスも含む)
		for (j = 0; j < prevLayer->size; j++) {
			sum += layer->Element[i].w[j] * prevLayer->Element[j].out;
		}
		layer->Element[i].out = sigmoid(sum);
	}

}

void Layer_Update() {

}