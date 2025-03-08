stack.o: stack.c stack.h
	gcc -g -c stack.c -o stack.o

stack.a: stack.o
	ar rc stack.a stack.o

stack: stack.o stack.a
	gcc -g -static -o stack stack.o stack.a
	./stack
clean:
	rm -rf *.o