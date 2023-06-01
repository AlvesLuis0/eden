all:
	clear
	gcc src/main.c -o build.out -std=c17 -Wall -Wextra -lm

clear:
	clear
	rm *.out

run:
	clear
	./build.out