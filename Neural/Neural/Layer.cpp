#include "stdafx.h"
#include "Layer.h"
#include "Learn.h"
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
void Layer_SetInput(Layer *layer, double input) {
	int i;
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].out = input;
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
		layer->Element[i].sum = sum;
		layer->Element[i].out = ReLU(sum);
	}

}

//layer, prevL, w, prevout, Learn_c, delta
//DELTA = SUM(next_delta * next_w * d_sigmoid(sum)) (layer != output_layer)
void Layer_Update(Layer *layer, const Layer *nextLayer, const Layer *prevLayer) {

	int i, j, k;

	//((バイアス以外)じゃなくて全部？)と思ったけどバイアス以外のニューロンについて更新
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].DELTA = 0;
		//バイアス以外
		//ΣDELTA[next] * w[i->next] * d_ReLU(sum)
		for (k = 1; k < nextLayer->size; k++) {
			layer->Element[i].DELTA += nextLayer->Element[k].DELTA * nextLayer->Element[k].w[i] * d_ReLU(layer->Element[i].sum);
		}
		//バイアス以外の入力のウェイトを更新
		for (j = 1; j < prevLayer->size; j++) {
			layer->Element[i].w[j] -= LEARN_C * layer->Element[i].DELTA * prevLayer->Element[j].out;
			//printf("%d,%d : %f", i, j, layer->Element[i].w[j]);
		}
	}

}

//DELTA = (delta)*d_ReLU(sum) (layer == output_layer)
void OutLayer_Update(Layer *layer, const Layer *prevLayer , double delta) {

	int i, j;

	//バイアス以外のニューロンについて
	for (i = 1; i < layer->size; i++) {
		layer->Element[i].DELTA = delta * d_ReLU(layer->Element[i].sum);
		//すべての入力のウェイトを更新
		for (j = 0; j < prevLayer->size; j++) {
			layer->Element[i].w[j] -= LEARN_C * layer->Element[i].DELTA * prevLayer->Element[j].out;
		}
	}
}