
all: integral_test

fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +

check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

libmath.a: tests/integral_test.o integral.o
	ar rc libmath.a tests/integral_test.o integral.o

integral_test: tests/integral_test.o libmath.a
	gcc tests/integral_test.o -L. -lmath -o integral_test -lm

tests/integral_test.o: tests/integral_test.c
	gcc -c tests/integral_test.c -o tests/integral_test.o -I.

integral.o: integral.c
	gcc -c integral.c -o integral.o -I.

clean:
	rm -rf *.o libmath.a integral_test tests/integral_test.o

run:
	./integral_test
