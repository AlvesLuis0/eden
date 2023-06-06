#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCEPTRON_IMPLEMENTATION
#include "EDEN/perceptron.h"

#define EPOCH 1000
#define LEARNING_RATE 1.5
#define ROWS 6
#define COLUMNS 1

/*
	este é o treino e o teste de um perceptron capaz de entender se um número
	é maior ou igual a zero (se for menor que zero, retorna 0, se não, 1)
*/
int main() {
	srand(time(NULL));

	// criando os inputs e expects para treino
	double inputs[ROWS][COLUMNS] = {
		{ -4 },
		{ -2 },
		{ -1 },
		{ 7 },
		{ 1 },
		{ 4 }
	};
	double expects[ROWS] = { 0, 0, 0, 1, 1, 1 };
	double test[ROWS][COLUMNS] = {
		{ -15 },
		{ 0 },
		{ -45 },
		{ 100 },
		{ -9 },
		{ 666 }
	};

	// declarando perceptron
	Perceptron model = PerceptronCreate(COLUMNS);

	// treinando o perceptron
	for(size_t i = 0; i < EPOCH; i++) {
		// a função PerceptronTrain retorna a taxa de erro (valor esperado - valor obtido)
		double error = PerceptronTrain(&model, inputs[i % ROWS], expects[i % ROWS], LEARNING_RATE);
		printf("%lf\n", error);
	}
	
	// testando se o perceptron está correto
	for(size_t i = 0; i < ROWS; i++) {
		for(size_t j = 0; j < COLUMNS; j++)
			printf("| %3.0lf ", test[i][j]);
		
		printf("| %3.0lf |\n", PerceptronPredict(model, test[i]));
	}

	// printando os valores do perceptron
	PerceptronPrint(model);

	// liberando a memória alocada do array de pesos
	PerceptronDelete(model);

	return 0;
}