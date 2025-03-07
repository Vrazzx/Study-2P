all: MyLab-1

MyLab-1: main.o my_math_lib.o
	gcc main.o my_math_lib.o -o MyLab-1 -lm

main.o: main.c
	gcc -c main.c -o main.o

my_math_lib.o: my_math_lib.c
	gcc -c my_math_lib.c -o my_math_lib.o

clean:
	rm -rf *.o MyLab-1


