#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEURAL_NETWORK_IMPLEMENTATION
#include "EDEN/neural-network.h"

#define TOPOLOGY_LENGTH 3

int main() {
  srand(time(NULL));
  
  size_t topology[TOPOLOGY_LENGTH] = { 2, 2, 1 };
  NeuralNetwork neural = NeuralNetworkCreate(topology, TOPOLOGY_LENGTH);

  NeuralNetworkPredict(neural, (double[]) { 1, 0 });

  NeuralNetworkPrint(neural);

  NeuralNetworkDelete(neural);

  return 0;
}