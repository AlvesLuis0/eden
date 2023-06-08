#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEURAL_NETWORK_IMPLEMENTATION
#include "EDEN/neural-network.h"

#define TOPOLOGY_LENGTH 3
#define ROWS 4
#define COLUMNS 2

int main() {
  double inputs[ROWS][COLUMNS] = {
    { 0, 0 },
    { 0, 1 },
    { 1, 0 },
    { 1, 1 }
  };

  // declarando a topologia (arquitetura) da rede neural
  size_t topology[TOPOLOGY_LENGTH] = { 2, 2, 1 };

  // criando a prória
  NeuralNetwork model = NeuralNetworkCreate(topology, TOPOLOGY_LENGTH);

  NeuralNetworkPredict(model, inputs[0]);
  NeuralNetworkPrint(model);

  // liberando a memória alocada
  NeuralNetworkDelete(model);
}