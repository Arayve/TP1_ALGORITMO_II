CC = gcc
CFLAGS = -std=c99 -g -Wall -Wconversion -Wtype-limits -pedantic -Werror


all:strutil.c strutil.h pruebas_alumno.c
	$(CC) $(CFLAGS) strutil.c pruebas_alumno.c -o pruebas

run:all
	./pruebas

valgrind: all
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
gdb:all
	gdbgui pruebas

	

