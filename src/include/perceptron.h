#ifndef PERCEPTRON_H
#define PERCEPTRON_H

typedef struct Perceptron_s {
	double *weights;
	double bias;
	const size_t weightsLength;
} Perceptron;

Perceptron PerceptronNew(size_t weightsLength);
void PerceptronPrint(Perceptron nn);
double PerceptronFeedforward(Perceptron nn, double *inputs);
void PerceptronFree(Perceptron nn);

#endif