#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCEPTRON_IMPLEMENTATION
#include "include/perceptron.h"
// 0.136948
#define EPOCH 1000
#define LEARNING_RATE 1.5
#define ROWS 4
#define COLUMNS 2

int main() {
	srand(time(NULL));

	// criando os inputs e expects para treino
	double inputs[ROWS][COLUMNS] = {
		{ 0, 0 },
		{ 0, 1 },
		{ 1, 0 },
		{ 1, 1 },
	};
	double expects[ROWS] = { 0, 1, 1, 1 };

	// declarando perceptron
	Perceptron p = PerceptronCreate(COLUMNS);

	for(size i = 0; i < EPOCH; i++) {
		PerceptronTrain(&p, inputs[i % ROWS], expects[i % ROWS], LEARNING_RATE);
		// printf("%lf\n", PerceptronTrain(&p, inputs[i % ROWS], expects[i % ROWS], LEARNING_RATE));
	}
	
	// puts("\n==============\n");

	for(size i = 0; i < ROWS; i++) {
		for(size j = 0; j < COLUMNS; j++)
			printf("%.0lf", inputs[i][j]);
		
		printf(" | %.0lf\n", PerceptronFeedforward(p, inputs[i]));
	}

	PerceptronDelete(p);

	return 0;
}