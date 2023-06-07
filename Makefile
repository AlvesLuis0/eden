# variáveis de personalização
FILENAME=perceptron
INPUT_DIR=src
OUTPUT_DIR=build
LOG_DIR=log
PLOT_DIR=plot
PLOT_SCRIPT_NAME=error-rate

# variáveis de trabalho
INPUT_FILE=$(INPUT_DIR)/$(FILENAME).c
OUTPUT_FILE=$(OUTPUT_DIR)/$(FILENAME).out
LOG_FILE=$(LOG_DIR)/$(FILENAME).txt
PLOT_FILE=$(PLOT_DIR)/$(FILENAME).svg
PLOT_SCRIPT_FILE=$(INPUT_DIR)/$(PLOT_SCRIPT_NAME).plt

# variáveis técnicas
COMPILER=gcc
FLAGS=-std=c17 -Wall -Wextra -Werror -Wpedantic -lm
COMMAND=$(COMPILER) $(INPUT_FILE) -o $(OUTPUT_FILE) $(FLAGS)

# comando de compilar programa
all:
	clear
	$(COMMAND)

# comando de rodar programa
run: $(OUTPUT_FILE)
	clear
	$(OUTPUT_FILE)

# comando de rodar programa com a saída do código armazenada em um arquivo
log: $(OUTPUT_FILE)
	clear
	$(OUTPUT_FILE) > log/$(FILENAME).txt

plot: $(PLOT_SCRIPT_FILE) $(LOG_FILE)
	clear
	gnuplot -p -c $(PLOT_SCRIPT_FILE) $(LOG_FILE) $(PLOT_FILE)

clear:
	clear
	rm $(OUTPUT_FILE)
	rm $(LOG_FILE)
	rm $(PLOT_FILE)