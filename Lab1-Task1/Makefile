all: Task1_test

fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

libfunc.a: roots_function.o
	ar rc libfunc.a roots_function.o

Task1_test: tests/roots_test.o libfunc.a
	gcc tests/roots_test.o -L. -lfunc -o Task1_test -lm

tests/roots_test.o: tests/roots_test.c
	gcc -c tests/roots_test.c -o tests/roots_test.o -I.  

roots_function.o: roots_function.c
	gcc -c roots_function.c -o roots_function.o -I.

run:
	./Task1_test

clean:
	rm -rf *.o *.a *_test
