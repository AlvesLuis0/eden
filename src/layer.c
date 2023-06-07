#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LAYER_IMPLEMENTATION
#include "EDEN/layer.h"

int main() {
  srand(time(NULL));

  // criação da camada
  Layer layer = LayerCreate(2, 2);

  // printando camada
  LayerPrint(layer, 2);

  // liberando memória alocada
  LayerDelete(layer);

  return 0;
}