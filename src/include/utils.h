#ifndef UTILS_H_
#define UTILS_H_

static inline double RAND(double x);
static inline double SIGMOID(double x);

#endif // UTILS_H_


#ifdef UTILS_IMPLEMENTATION

#include <stdlib.h>
#include <math.h>

// retorna número aleatório entre 0 e x
static inline double RAND(double x) {
  return ((double) rand() / (double) RAND_MAX) * x;
}

// função que retorna um número entre 0 e 1 baseado no x
static inline double SIGMOID(double x) {
  return 1 / (1 + exp(-x));
}

#endif // UTILS_IMPLEMENTATION