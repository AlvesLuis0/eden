#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NEURAL_NETWORK_IMPLEMENTATION
#include "EDEN/neural-network.h"

int main() {
  srand(time(NULL));

  Layer layer = LayerCreate(2, 2);
  LayerPrint(layer, 2);

  return 0;
}