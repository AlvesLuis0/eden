#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

// redefinição do tipo "tamanho"
typedef long unsigned int size_t;

// estrutura do perceptron
typedef struct {
	const size_t weightsLength;
	double bias;
	double *weights;
} Perceptron;

#define PerceptronPrint(model) __PerceptronPrint(model, #model)

Perceptron PerceptronCreate(size_t weightsLength);
void __PerceptronPrint(Perceptron model, char *label);
double PerceptronPredict(Perceptron model, double *inputs);
double PerceptronTrain(Perceptron *model, double *inputs, double expects, double learningRate);
static inline void PerceptronDelete(Perceptron model);

#endif // PERCEPTRON_H_

#ifdef PERCEPTRON_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando perceptron
Perceptron PerceptronCreate(size_t weightsLength) {
	Perceptron model = {
		.weights = malloc(sizeof(double) * weightsLength), // alocando memória necessária para armazenas os pesos
		.bias = RAND(1.5),
		.weightsLength = weightsLength
	};

	for(size_t i = 0; i < weightsLength; i++)
		model.weights[i] = RAND(1.5);

	return model;
}

void __PerceptronPrint(Perceptron model, char *label) {
	printf("Perceptron %s = {\n", label);
	printf("\tdouble bias = %lf;\n\tsize_t weightsLength = %ld;\n\tdouble *weights = [\n\t\t", model.bias, model.weightsLength);

	for(size_t i = 0; i < model.weightsLength; i++)
		printf("%lf ", model.weights[i]);
	puts("\n\t];\n};");
}

// calculando saída
double PerceptronPredict(Perceptron model, double *inputs) {
	double sum = 0;

	for(size_t i = 0; i < model.weightsLength; i++)
		sum += model.weights[i] * inputs[i];
	
	return SIGMOID(sum + model.bias);
}

// treinando o perceptron
double PerceptronTrain(Perceptron *model, double *inputs, double expects, double learningRate) {
	double output = PerceptronPredict(*model, inputs);
	double error = expects - output;
	double rate = learningRate * error;

	for(size_t i = 0; i < model->weightsLength; i++)
		model->weights[i] += rate * inputs[i];
	
	model->bias += rate;

	return error;
}

static inline void PerceptronDelete(Perceptron model) {
	free(model.weights);
}

#endif // PERCEPTRON_IMPLEMENTATION