#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEURAL_NETWORK_IMPLEMENTATION
#include "EDEN/neural-network.h"

#define TOPOLOGY_LENGTH 3

int main() {
  // declarando a topologia (arquitetura) da rede neural
  size_t topology[TOPOLOGY_LENGTH] = { 2, 2, 1 };

  // criando a prória
  NeuralNetwork model = NeuralNetworkCreate(topology, TOPOLOGY_LENGTH);
  NeuralNetworkPrint(model);

  // liberando a memória alocada
  NeuralNetworkDelete(model);
}