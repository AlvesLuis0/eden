#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEURAL_NETWORK_IMPLEMENTATION
#include "EDEN/neural-network.h"

#define TOPOLOGY_LENGTH 3

int main() {
  size_t topology[TOPOLOGY_LENGTH] = { 2, 2, 1 };

  NeuralNetwork model = NeuralNetworkCreate(topology, TOPOLOGY_LENGTH);
  printf("%ld\n", model.layersLength);
}