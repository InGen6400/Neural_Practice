#include "stdafx.h"
#include <math.h>

//�V�O���C�h�֐�
double sigmoid(double input) {
	return 1 / (1 + exp(-input));
}

//�V�O���C�h�̔����֐�
double d_sigmoid(double input) {
	return (1 - sigmoid(input))*sigmoid(input);
}