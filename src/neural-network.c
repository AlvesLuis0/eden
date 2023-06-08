#define LAYER_IMPLEMENTATION
#include "EDEN/layer.h"

int main() {
  Layer layer = LayerCreate(2, 2);

  LayerPrint(layer);

  LayerDelete(layer);

  return 0;
}