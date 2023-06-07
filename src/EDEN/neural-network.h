#ifndef NEURAL_NETWORK_H_
#define NEURAL_NETWORK_H_

// redefinição do tipo "tamanho"
typedef long unsigned int size_t;

#include "layer.h"

// estrutura da rede neural
typedef struct {
  const size_t layersLength;
  const size_t *topology;
  Layer *layers;
} NeuralNetwork;

NeuralNetwork NeuralNetworkCreate(size_t *topology, size_t layersLength);

#endif // NEURAL_NETWORK_H_

#ifdef NEURAL_NETWORK_IMPLEMENTATION

#include <stdlib.h>

#define LAYER_IMPLEMENTATION
#include "layer.h"

NeuralNetwork NeuralNetworkCreate(size_t *topology, size_t layersLength) {
  NeuralNetwork model = {
    .layersLength = layersLength,
    .topology = topology,
    .layers = malloc(sizeof(Layer) * (layersLength - 1))
  };

  for(size_t i = 0, j = 1; i < layersLength - 1; i++, j++)
    model.layers[i] = LayerCreate(topology[j], topology[i]);

  return model;
}

#endif