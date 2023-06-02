#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

// redefinição do tipo "tamanho"
typedef long unsigned int size;

// estrutura do perceptron
typedef struct {
	const size weightsLength;
	double bias;
	double *weights;
} Perceptron;

Perceptron PerceptronCreate(size weightsLength);
double PerceptronFeedforward(Perceptron p, double *inputs);
static inline double PerceptronCost(Perceptron p, double *inputs, double expected);

#endif // PERCEPTRON_H_

#ifdef PERCEPTRON_IMPLEMENTATION

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando perceptron
Perceptron PerceptronCreate(size weightsLength) {
	double weights[weightsLength];

	Perceptron p = {
		.weights = weights,
		.bias = RAND(1.5),
		.weightsLength = weightsLength
	};

	for(size i = 0; i < weightsLength; i++)
		p.weights[i] = RAND(1.5);

	return p;
}

// calculando saída
double PerceptronFeedforward(Perceptron p, double *inputs) {
	double sum = 0;

	for(size i = 0; i < p.weightsLength; i++)
		sum += p.weights[i] * inputs[i];
	
	return SIGMOID(sum + p.bias);
}

// treinando o perceptron
static inline double PerceptronCost(Perceptron p, double *inputs, double expected) {
	return PerceptronFeedforward(p, inputs) - expected;
}

#endif // PERCEPTRON_IMPLEMENTATION