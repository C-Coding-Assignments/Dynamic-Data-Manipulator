main: main.o pokemon.o
	gcc -o main main.o pokemon.o

main.o: main.c pokemon.h
	gcc -c main.c

student.o: pokemon.c pokemon.h
	gcc -c pokemon.c