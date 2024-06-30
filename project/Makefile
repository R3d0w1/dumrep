all: program
program: main.o temp_functions.o
	gcc main.o temp_functions.o -o program
main.o: main.c
	gcc -c main.c
temp_functions.o: temp_functions.c
	gcc -c temp_functions.c
clean:
	del *.o *.exe