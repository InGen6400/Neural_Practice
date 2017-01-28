#include "stdafx.h"
#include "Layer.h"
#include "Neuron.h"
#include "Learn.h"
#include <stdlib.h>

//loop‰ñŠwK‚µ‚Äo—Í
void Learn(int loop) {

	Layer *Input_Layer;
	Layer *Hidden_Layer;
	Layer *Output_Layer;

	int Lcount = 0;
	int Dcount = 0;

	//”ä—áŠÖ”‚ÅÅ‰‚Í‚·
	double input[DATA_AMOUNT][INPUT_SIZE] = { {1},{2},{3},{4} };
	double correct[DATA_AMOUNT][OUTPUT_SIZE] = { {1},{2},{3},{4} };

	Input_Layer = Layer_New(INPUT_SIZE, 0);
	Hidden_Layer = Layer_New(HIDDEN_SIZE, INPUT_SIZE);
	Output_Layer = Layer_New(OUTPUT_SIZE, HIDDEN_SIZE);
	for (Lcount = 0; Lcount < loop; Lcount++) {
		for (Dcount = 0; Dcount < DATA_AMOUNT; Dcount++) {

			Layer_SetInput(Input_Layer, input[Dcount]);

			Layer_Calc(Hidden_Layer, Input_Layer);
			Layer_Calc(Output_Layer, Hidden_Layer);

			printf("DATA%d : %lf -> %lf\n", Dcount, input[Dcount], Output_Layer->Element[1].out);
		}
	}
}