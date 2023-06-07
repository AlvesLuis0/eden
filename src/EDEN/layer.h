#ifndef LAYER_H_
#define LAYER_H_

// redefinição do tipo "tamanho"
typedef long unsigned int size_t;

// estrutura da camada
typedef struct {
  const size_t neuronsLength;
  double bias;
  double **weights;
} Layer;

#define LayerPrint(layer, previowsNeuronsLength) __LayerPrint(layer, previowsNeuronsLength, #layer) 

Layer LayerCreate(size_t neuronsLength, size_t previousNeuronsLength);
void __LayerPrint(Layer layer, size_t previowsNeuronsLength, char *label);
void LayerDelete(Layer layer);

#endif // LAYER_H_

#ifdef LAYER_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando camada
Layer LayerCreate(size_t neuronsLength, size_t previousNeuronsLength) {
  Layer model = {
    .neuronsLength = neuronsLength,
    .bias = RAND(1.5),
    .weights = malloc(sizeof(double*) * neuronsLength)
  };

  for(size_t i = 0; i < neuronsLength; i++) {
    model.weights[i] = malloc(sizeof(double) * previousNeuronsLength);

    for(size_t j = 0; j < previousNeuronsLength; j++)
      model.weights[i][j] = RAND(1.5);
  }
  
  return model;
}

// printando os valores da camada
void __LayerPrint(Layer layer, size_t previowsNeuronsLength, char *label) {
	printf("Layer %s = {\n", label);
	printf("\tdouble bias = %lf;\n\tsize_t neuronsLength = %ld;", layer.bias, layer.neuronsLength);
  printf("\n\tdouble **weights = [");

	for(size_t i = 0; i < layer.neuronsLength; i++) {
    fputs("\n\t\t", stdout);

    for(size_t j = 0; j < previowsNeuronsLength; j++)
      printf("%lf ", layer.weights[i][j]);
  }

	puts("\n\t];\n};");
}

// liberando memória alocada para a matriz de pesos da camada
void LayerDelete(Layer layer) {
  for(size_t i = 0; i < layer.neuronsLength; i++)
    free(layer.weights[i]);
  
  free(layer.weights);
}

#endif // LAYER_IMPLEMENTATION