#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

// redefinição do tipo "tamanho"
typedef long unsigned int size;

// estrutura do perceptron
typedef struct {
	const size weightsSize;
	double bias;
	double *weights;
} Perceptron;

Perceptron PerceptronCreate(size weightsSize);
double PerceptronFeedforward(Perceptron p, double *inputs);
double PerceptronTrain(Perceptron *p, double *inputs, double expects, double learningRate);
void PerceptronDelete(Perceptron p);

#endif // PERCEPTRON_H_

#ifdef PERCEPTRON_IMPLEMENTATION

#include <stdlib.h>

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando perceptron
Perceptron PerceptronCreate(size weightsSize) {
	Perceptron p = {
		.weights = malloc(sizeof(double) * weightsSize),
		.bias = RAND(1.5),
		.weightsSize = weightsSize
	};

	for(size i = 0; i < weightsSize; i++)
		p.weights[i] = RAND(1.5);

	return p;
}

// calculando saída
double PerceptronFeedforward(Perceptron p, double *inputs) {
	double sum = 0;

	for(size i = 0; i < p.weightsSize; i++)
		sum += p.weights[i] * inputs[i];
	
	return SIGMOID(sum + p.bias);
}

// treinando o perceptron
double PerceptronTrain(Perceptron *p, double *inputs, double expects, double learningRate) {
	double output = PerceptronFeedforward(*p, inputs);
	double error = expects - output;

	for(size i = 0; i < p->weightsSize; i++)
		p->weights[i] += learningRate * error * inputs[i];
	
	p->bias += learningRate * error;

	return error;
}

void PerceptronDelete(Perceptron p) {
	free(p.weights);
}

#endif // PERCEPTRON_IMPLEMENTATION