#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "perceptron.h"

#define RAND(x) ((double) rand() / (double) RAND_MAX) * x
#define ACTIVATION_FUNCTION(x) (1 / (1 + exp(-x)))

// criando o perceptron
Perceptron PerceptronNew(size_t weightsLength) {
	Perceptron nn = { .weightsLength = weightsLength };
	nn.bias = RAND(1.5);
	nn.weights = (double*) malloc(weightsLength * sizeof(double));

	for(size_t i = 0; i < weightsLength; i++)
		nn.weights[i] = RAND(1.5);

	return nn;
}

// printando
void PerceptronPrint(Perceptron nn) {
	printf("parameters: %ld\n", nn.weightsLength + 1);
	printf("bias: %lf\n", nn.bias);
	
	for(size_t i = 0; i < nn.weightsLength; i++)
		printf("weight %ld: %lf\n", i+1, nn.weights[i]);
}

// calculando saída
double PerceptronFeedforward(Perceptron nn, double *inputs) {
	double sum = 0;

	for(size_t i = 0; i < nn.weightsLength; i++)
		sum += nn.weights[i] * inputs[i];
	
	return ACTIVATION_FUNCTION(sum + nn.bias);
}

// liberando espaço alocado dos pesos
void PerceptronFree(Perceptron nn) {
	free(nn.weights);
}