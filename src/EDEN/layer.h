#ifndef LAYER_H_
#define LAYER_H_

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
void LayerDelete(Layer layer);

#endif // LAYER_H_

#ifdef LAYER_IMPLEMENTATION

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

// printando os valores da camada
void LayerPrint(Layer layer, size_t previowsLayerLength) {
	printf("bias: %lf\namount of neurons: %ld\n", layer.bias, layer.layerLength);

  for(size_t i = 0; i < layer.layerLength; i++)
    for(size_t j = 0; j < previowsLayerLength; j++)
      printf("weight[%ld][%ld]: %lf\n", i, j, layer.weights[i][j]);
}

// liberando memória alocada para a matriz de pesos da camada
void LayerDelete(Layer layer) {
  for(size_t i = 0; i < layer.layerLength; i++)
    free(layer.weights[i]);
  
  free(layer.weights);
}

#endif // LAYER_IMPLEMENTATION