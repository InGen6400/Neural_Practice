#include "stdafx.h"
#include <math.h>

//シグモイド関数
double sigmoid(double input) {
	return 1 / (1 + exp(-input));
}

//シグモイドの微分関数
double d_sigmoid(double input) {
	return (1 - sigmoid(input))*sigmoid(input);
}