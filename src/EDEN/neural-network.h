#ifndef NEURAL_NETWORK_H_
#define NEURAL_NETWORK_H_

typedef long unsigned int size_t;

#define LAYER_IMPLEMENTATION
#include "layer.h"

// estrutura da rede neural
typedef struct {
  const size_t topologyLength;
  Layer *layers;
} NeuralNetwork;

#define NeuralNetworkPrint(neural) __NeuralNetworkPrint(neural, #neural)

NeuralNetwork NeuralNetworkCreate(size_t *topology, size_t topologyLength);
void __NeuralNetworkPrint(NeuralNetwork neural, char *label);
double* NeuralNetworkPredict(NeuralNetwork neural, double *inputs);
void NeuralNetworkDelete(NeuralNetwork neural);

#endif // NEURAL_NETWORK_H_

#ifdef NEURAL_NETWORK_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

// criando a rede neural
NeuralNetwork NeuralNetworkCreate(size_t *topology, size_t topologyLength) {
  NeuralNetwork neural = {
    .topologyLength = topologyLength - 1,
    .layers = malloc(sizeof(Layer) * (topologyLength - 1))
  };

  for(size_t i = 0; i < neural.topologyLength; i++)
    neural.layers[i] = LayerCreate(topology[i + 1], topology[i]);
  
  return neural;
}

// printando valores da rede neural
void __NeuralNetworkPrint(NeuralNetwork neural, char *label) {
  printf("========== %s ==========\n", label);

  for(size_t i = 0; i < neural.topologyLength; i++)
    LayerPrint(neural.layers[i]);
  
  puts("------------------------\n");
}

// prevendo resultado com base nas entradas
double* NeuralNetworkPredict(NeuralNetwork neural, double *inputs) {
  for(size_t i = 0; i < neural.layers[0].neuronsLength; i++)
    LayerNeuronPredict(neural.layers[0], i, inputs);
  
  if(neural.topologyLength > 1)
    for(size_t i = 1; i < neural.topologyLength; i++)
      for(size_t j = 0; j < neural.layers[i].neuronsLength; j++)
        LayerNeuronPredict(neural.layers[i], j, neural.layers[i - 1].values);
  
  return neural.layers[neural.topologyLength - 1].values;
}

// liberando a memória
void NeuralNetworkDelete(NeuralNetwork neural) {
  for(size_t i = 0; i < neural.topologyLength; i++)
    LayerDelete(neural.layers[i]);
  
  free(neural.layers);
}

#endif // NEURAL_NETWORK_IMPLEMENTATION