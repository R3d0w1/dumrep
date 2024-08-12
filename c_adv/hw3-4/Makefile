all: program
program: main.o func.o
	gcc main.o func.o -o program -lncurses -DNCURSES_STATIC
main.o: main.c
	gcc -c main.c -lncurses -DNCURSES_STATIC
func.o: func.c
	gcc -c func.c -lncurses -DNCURSES_STATIC
clean:
	del *.o *.exe