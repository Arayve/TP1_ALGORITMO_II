CC = gcc
CFLAGS = -std=c99 -g -Wall -Wconversion -Wtype-limits -pedantic -Werror


all_syntax:syntax_val.c  pila.c pila.h 
	$(CC) $(CFLAGS) syntax_val.c pila.c -o pruebas
all_tail:tail.c  cola.c cola.h 
	$(CC) $(CFLAGS) tail.c cola.c -o pruebas
valgrind: all
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas archivo3.txt 
	

