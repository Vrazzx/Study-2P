all: Task1_test

fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

libfunc.a: roots_function.o
	ar rc libfunc.a roots_function.o

Task1_test: roots_test.o libfunc.a
	gcc roots_test.o -L. -lfunc -o Task1_test -lm

roots_test.o: roots_test.c
	gcc -c roots_test.c -o roots_test.o  

roots_function.o: roots_function.c
	gcc -c roots_function.c -o roots_function.o   

clean:
	rm -rf *.o *.a *_test
