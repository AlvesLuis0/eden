#define LAYER_IMPLEMENTATION
#include "EDEN/layer.h"

int main() {
  Layer layer = LayerCreate(1, 2);

  LayerPrint(layer);

  LayerDelete(layer);

  return 0;
}