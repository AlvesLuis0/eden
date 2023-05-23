#!/usr/bin/sh

COMPILER="gcc"
INPUT_FILES="src/main.c src/include/@perceptron.c"
OUTPUT_FILE="nn.out"
FLAGS="-std=c17 -Wall -Wextra -lm"

clear
set -xe

$COMPILER $INPUT_FILES -o $OUTPUT_FILE $FLAGS