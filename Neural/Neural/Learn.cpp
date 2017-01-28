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
	int OutCount = 0;

	//”ä—áŠÖ”‚ÅÅ‰‚Í‚·
	double input[DATA_AMOUNT][INPUT_SIZE] = { {1},{2},{3},{4} };
	double correct[DATA_AMOUNT][OUTPUT_SIZE] = { {1},{2},{3},{4} };

	Input_Layer = Layer_New(INPUT_SIZE, 0);
	Hidden_Layer = Layer_New(HIDDEN_SIZE, INPUT_SIZE);
	Output_Layer = Layer_New(OUTPUT_SIZE, HIDDEN_SIZE);
	for (Lcount = 0; Lcount < loop; Lcount++) {
		for (Dcount = 0; Dcount < DATA_AMOUNT; Dcount++) {

			Layer_SetInput(Input_Layer, input[Dcount][0]);

			Layer_Calc(Hidden_Layer, Input_Layer);
			Layer_Calc(Output_Layer, Hidden_Layer);

			OutLayer_Update(Output_Layer, Hidden_Layer, Output_Layer->Element[1].out - correct[Dcount][0]);

			Layer_Update(Hidden_Layer, Output_Layer, Input_Layer);

			printf("DATA%d : %lf -> %lf\n", Dcount, input[Dcount][0], Output_Layer->Element[1].out);
		}
		putchar('\n');
	}
	printf("Complete\n\n");
	double test[DATA_AMOUNT][1] = {{1.5}, {2.5}, {7.5}, {2.2}};
	for (Dcount = 0; Dcount < DATA_AMOUNT; Dcount++) {
		Layer_SetInput(Input_Layer, test[Dcount][0]);

		Layer_Calc(Hidden_Layer, Input_Layer);
		Layer_Calc(Output_Layer, Hidden_Layer);

		printf("DATA%d : %lf -> %lf\n", Dcount, test[Dcount][0], Output_Layer->Element[1].out);
	}
}