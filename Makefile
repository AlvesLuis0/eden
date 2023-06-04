all:
	clear
	gcc src/main.c -o build.out -std=c17 -Wall -Wextra -Werror -Wpedantic -lm

clear:
	clear
	rm *.out

run:
	clear
	./build.out