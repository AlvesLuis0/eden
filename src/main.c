#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCEPTRON_IMPLEMENTATION
#include "include/perceptron.h"

int main() {
	srand(time(NULL));

	Perceptron p = PerceptronCreate(2);
	double inputs[] = { 1, 0 };
	double output = PerceptronFeedforward(p, inputs);

	printf("input 1: %d\ninput 2: %d\noutput: %lf\nexpected: %d\nerror: %lf\n", 1, 0, output, 1, 1 - output);

	return 0;
}