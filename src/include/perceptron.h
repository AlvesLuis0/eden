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
void PerceptronTrain(Perceptron *p, double **inputs, double *expects, size samplesSize, size epoch, double learningRate);

#endif // PERCEPTRON_H_

#ifdef PERCEPTRON_IMPLEMENTATION

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando perceptron
Perceptron PerceptronCreate(size weightsSize) {
	double weights[weightsSize];

	Perceptron p = {
		.weights = weights,
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
void PerceptronTrain(Perceptron *p, double **inputs, double *expects, size samplesSize, size epoch, double learningRate) {
	// double output;
	// double error;

	// for(; epoch > 0; epoch--) {
	// 	for(size i = 0; i < samplesSize; i++) {
	// 		output = PerceptronFeedforward(*p, inputs[i]);
	// 		error = output - expects[i];

	// 		for(size j = 0; j < p->weightsSize; j++)
	// 			p->weights[j] += learningRate * error * inputs[i][j];
			
	// 		p->bias += learningRate * error;
	// 	}
	// }

	for(size i = 0; i < samplesSize; i++) {
		for (size j = 0; j < p->weightsSize; j++)
			printf("%lf ", inputs[i][j]);
		puts("");
	}
}

#endif // PERCEPTRON_IMPLEMENTATION