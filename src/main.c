#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCEPTRON_IMPLEMENTATION
#include "include/perceptron.h"

#define EPOCH 1000
#define LEARNING_RATE 1.5
#define ROWS 4
#define COLUMNS 2

void showOR(Perceptron p, double *inputs, double expects) {
	double output = PerceptronFeedforward(p, inputs);
	double error = output - expects;

	printf("%.2lf | %.2lf = %.2lf\n", inputs[0], inputs[1], PerceptronFeedforward(p, inputs));
	printf("expects: %.2lf\nerror: %.2lf\n", expects, error);
}

int main() {
	srand(time(NULL));

	Perceptron p = PerceptronCreate(COLUMNS);
	double **inputs = malloc(sizeof(double*) * ROWS);
	double expects[ROWS] = { 0, 1, 1, 1 };

	// criando tabela OR
	for(size i = 0; i < ROWS; i++)
		inputs[i] = malloc(sizeof(double) * COLUMNS);

	// showOR(p, inputs[1], expects[1]);

	PerceptronTrain(&p, inputs, expects, ROWS, EPOCH, LEARNING_RATE);

	return 0;
}