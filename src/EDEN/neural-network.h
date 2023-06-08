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

#define NeuralNetworkPrint(model) __NeuralNetworkPrint(model, #model)

NeuralNetwork NeuralNetworkCreate(size_t *topology, size_t layersLength);
void __NeuralNetworkPrint(NeuralNetwork model, char *label);

#endif // NEURAL_NETWORK_H_

#ifdef NEURAL_NETWORK_IMPLEMENTATION

#include <stdlib.h>

#define LAYER_IMPLEMENTATION
#include "layer.h"

// criando a rede neural
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

// printando seus valores
void __NeuralNetworkPrint(NeuralNetwork model, char *label) {
  printf("========== %s ==========\n", label);

  for(size_t i = 0; i < model.layersLength - 1; i++)
    LayerPrint(model.layers[i], model.topology[i]);
  
  puts("----------------");
}

// prevendo um valor com base nas entradas
double NeuralNetworkPredict(NeuralNetwork model, double *inputs) {
  (void) model;
  (void) inputs;

  return 0;
}

// liberando memória
void NeuralNetworkDelete(NeuralNetwork model) {
  for(size_t i = 0; i < model.layersLength - 1; i++)
    LayerDelete(model.layers[i]);

  free(model.layers);
}

#endif