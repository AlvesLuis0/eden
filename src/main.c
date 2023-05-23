#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/perceptron.h"

int main() {
	srand(time(NULL));

	Perceptron nn = PerceptronNew(2);
	double inputs[] = { 1, 0 };
	double output = PerceptronFeedforward(nn, inputs);

	PerceptronPrint(nn);
	printf("input 1: %d\ninput 2: %d\noutput: %lf\nexpected: %d\nerror: %lf\n", 1, 0, output, 1, 1 - output);

	PerceptronFree(nn);

	return 0;
}