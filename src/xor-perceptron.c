#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCEPTRON_IMPLEMENTATION
#include "EDEN/perceptron.h"

#define EPOCH 1000
#define LEARNING_RATE 1.5
#define ROWS 4
#define COLUMNS 2

int main() {
	srand(time(NULL));

	double inputs[ROWS][COLUMNS] = {
		{ 0, 0 },
		{ 0, 1 },
		{ 1, 0 },
		{ 1, 1 }
	};

	Perceptron or = PerceptronCreate(COLUMNS);
	Perceptron nand = PerceptronCreate(COLUMNS);
	Perceptron and = PerceptronCreate(COLUMNS);

	for(size_t i = 0; i < EPOCH; i++) {
		size_t index = i % ROWS;
		double a = inputs[index][0];
		double b = inputs[index][1];

		PerceptronTrain(&or, inputs[index], a || b, LEARNING_RATE);
		PerceptronTrain(&nand, inputs[index], !(a && b), LEARNING_RATE);
		PerceptronTrain(&and, inputs[index], a && b, LEARNING_RATE);
	}

	PerceptronPrint(or);
	PerceptronPrint(nand);
	PerceptronPrint(and);

	for(size_t i = 0; i < ROWS; i++) {
		double orOut = PerceptronPredict(or, inputs[i]);
		double nandOut = PerceptronPredict(nand, inputs[i]);
		double andOut = PerceptronPredict(and, (double[]) { orOut, nandOut });

		printf("%.0lf ^ %.0lf = %.0lf\n", inputs[i][0], inputs[i][1], andOut);
	}

	PerceptronDelete(and);
	PerceptronDelete(or);
	PerceptronDelete(nand);

	return 0;
}