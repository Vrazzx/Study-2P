all: TheStackProgram

TheStackProgram: main.o func.o
	gcc main.o func.o -o TheStackProgram

main.o: main.c
    gcc -c main.c -o main.o

func.o: func.c
    gcc -c func.c -o func.o

clean:
    rm -rf *.o TheStackProgram