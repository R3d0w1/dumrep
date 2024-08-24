all: program
program: main.o func.o
	gcc main.o func.o -o program
main.o: main.c
	gcc -c main.c
temp_functions.o: func.c
	gcc -c func.c
clean:
	del *.o *.exe