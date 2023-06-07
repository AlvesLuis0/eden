#ifndef NEURAL_NETWORK_H_
#define NEURAL_NETWORK_H_

// redefinição do tipo "tamanho"
typedef long unsigned int size_t;

// estrutura da camada
typedef struct {
  const size_t layerLength;
  double bias;
  double **weights;
} Layer;

Layer LayerCreate(size_t layerLength, size_t previousLayerLength);
void LayerPrint(Layer layer, size_t previowsLayerLength);

#endif // NEURAL_NETWORK_H_

#ifdef NEURAL_NETWORK_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando camada
Layer LayerCreate(size_t layerLength, size_t previousLayerLength) {
  Layer model = {
    .layerLength = layerLength,
    .bias = RAND(1.5),
    .weights = malloc(sizeof(double*) * layerLength)
  };

  for(size_t i = 0; i < layerLength; i++) {
    model.weights[i] = malloc(sizeof(double) * previousLayerLength);

    for(size_t j = 0; j < previousLayerLength; j++)
      model.weights[i][j] = RAND(1.5);
  }
  
  return model;
}

void LayerPrint(Layer layer, size_t previowsLayerLength) {
	printf("bias: %lf\namount of neurons: %ld\n", layer.bias, layer.layerLength);

  for(size_t i = 0; i < layer.layerLength; i++)
    for(size_t j = 0; j < previowsLayerLength; j++)
      printf("weight[%ld][%ld]: %lf\n", i, j, layer.weights[i][j]);
}

#endif // NEURAL_NETWORK_IMPLEMENTATION