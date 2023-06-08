#ifndef LAYER_H_
#define LAYER_H_

typedef long unsigned int size_t;

// estrutura da camada
typedef struct {
	double bias;
	size_t neuronsLength;
	size_t inputsLength;
	double **weights;
	double *values;
} Layer;

#define LayerPrint(layer) __LayerPrint(layer, #layer)

Layer LayerCreate(size_t neuronsLength, size_t inputsLength);
void __LayerPrint(Layer layer, char *label);
void LayerDelete(Layer layer);

#endif // LAYER_H_

#ifdef LAYER_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando uma camada
Layer LayerCreate(size_t neuronsLength, size_t inputsLength) {
	Layer layer = {
		.bias = RAND(1.5),
		.neuronsLength = neuronsLength,
		.inputsLength = inputsLength,
		.weights = malloc(sizeof(double*) * neuronsLength),
		.values = malloc(sizeof(double) * neuronsLength)
	};

	for(size_t i = 0; i < neuronsLength; i++) {
		layer.weights[i] = malloc(sizeof(double) * inputsLength);

		for(size_t j = 0; j < inputsLength; j++)
			layer.weights[i][j] = RAND(1.5);
	}

	return layer;
}

// printando os valores da camda
void __LayerPrint(Layer layer, char *label) {
	printf("Layer %s = {\n", label);
	printf(
		"\tdouble bias = %lf;\n\tsize_t neuronsLength = %ld;\n\tsize_t inputsLength = %ld;\n\tdouble **weights = [",
		layer.bias, layer.neuronsLength, layer.inputsLength
	);

	for(size_t i = 0; i < layer.neuronsLength; i++) {
		fputs("\n\t\t", stdout);

		for(size_t j = 0; j < layer.inputsLength; j++)
			printf("%lf ", layer.weights[i][j]);
	}

	fputs("\n\t]\n\tdouble *values = [\n\t\t", stdout);
	for(size_t i = 0; i < layer.neuronsLength; i++)
		printf("%lf ", layer.values[i]);

	puts("\n\t];\n};");
}

// liberando memória alocada dentro da camada
void LayerDelete(Layer layer) {
	for(size_t i = 0; i < layer.neuronsLength; i++)
		free(layer.weights[i]);

	free(layer.weights);
	free(layer.values);
}

#endif // LAYER_IMPLEMENTATION