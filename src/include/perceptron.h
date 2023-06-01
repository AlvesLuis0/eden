#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

// estrutura do perceptron
typedef struct {
	double *weights;
	double bias;
	const size_t weightsLength;
} Perceptron;

Perceptron PerceptronCreate(size_t weightsLength);
double PerceptronFeedforward(Perceptron nn, double *inputs);

#endif // PERCEPTRON_H_


#ifdef PERCEPTRON_IMPLEMENTATION

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando perceptron
Perceptron PerceptronCreate(size_t weightsLength) {
	double weights[weightsLength];

	Perceptron p = {
		.weights = weights,
		.bias = RAND(1.5),
		.weightsLength = weightsLength
	};

	for(size_t i = 0; i < weightsLength; i++)
		p.weights[i] = RAND(1.5);

	return p;
}

// calculando saída
double PerceptronFeedforward(Perceptron p, double *inputs) {
	double sum = 0;

	for(size_t i = 0; i < p.weightsLength; i++)
		sum += p.weights[i] * inputs[i];
	
	return SIGMOID(sum + p.bias);
}

#endif // PERCEPTRON_IMPLEMENTATION