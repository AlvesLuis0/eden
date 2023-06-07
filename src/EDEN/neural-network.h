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

#endif // NEURAL_NETWORK_H_

#ifdef NEURAL_NETWORK_IMPLEMENTATION

#define UTILS_IMPLEMENTATION
#include "utils.h"

// criando camada
Layer LayerCreate(size_t layerLength, size_t previousLayerLength) {
  Layer model = {
    .layerLength = layerLength,
    .bias = RAND(1.5),
    .weights = malloc(sizeof(double*) * layerLength)
  };

  for(size_t i = 0; i < layerLength; i++)
    model.weights[i] = malloc(sizeof(double) * previousLayerLength);
  
  return model;
}

#endif // NEURAL_NETWORK_IMPLEMENTATION