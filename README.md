# EDEN
## Visão Geral
A biblioteca de Machine Learning Eden é um conjunto de funções e algoritmos implementados em linguagem C,
desenvolvidos para auxiliar na criação e aplicação de modelos ML. Essa biblioteca oferece uma
implementações básicas desses algoritmos, permitindo que os usuários criem, treinem e façam predições
utilizando esses modelos.

## Modelos
### Perceptron
Modelo mais simples de machine learning, que tem quantas entradas você desejar, porém, só tem como saída
um único número entre 0 e 1. O cálculo da predição pode ser demonstrado da seguinte forma:\
$y = g \left( \left(\sum_{i=1}^{n} w_i x_i \right) + b \right)$\
Onde $g(x) = \frac{i}{1 + e^{-x}}$

#### Simbologia
* $y$ - Saída do Perceptron
* $g$ - Função de Ativação - Sigmoide
* $w_i$ - Pesos das Conexões
* $x_i$ - Valores de Entrada
* $b$ - Viés (bias)

## Requisitos de Sistema
* Compilador C: um compilador C compatível instalado no sistema.
* Bibliotecas padrão do C: as bibliotecas padrão do C devem estar disponíveis no sistema.

## Instalação
Clone o repositório do projeto:
```bash
git clone https://github.com/alvesluis0/eden.git
```
Dentro da pasta do projeto, compile código fonte da biblioteca (lembre-se de incluir a flag `-lm`)
```bash
gcc seu-codigo.c -o seu-programa -lm
```

## Uso
Há várias formas de utilizar esta biblioteca. Existem alguns exemplos na pasta [src](/src) do projeto.

## Contribuição
Contribuições são bem-vindas! Se você deseja contribuir para a biblioteca Eden, sinta-se à vontade para
abrir um problema ou enviar uma solicitação de pull request no repositório.