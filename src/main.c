#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCEPTRON_IMPLEMENTATION
#include "include/perceptron.h"

double inputs[][2] = {
	{ 0, 0 },
	{ 0, 1 },
	{ 1, 0 },
	{ 1, 1 }
};

double targets[] = {
	0, 1, 1, 1
};

int main() {
	srand(time(NULL));

	Perceptron p = PerceptronCreate(2);
	double output = PerceptronFeedforward(p, inputs[1]);
	double cost = PerceptronCost(p, inputs[1], 1);

	printf("output: %lf\nexpected: %d\ncost: %lf\n", output, 1, cost);

	return 0;
}