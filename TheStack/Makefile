stack.o: stack.c stack.h
	gcc -g -c stack.c -o stack.o

fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +

check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

tests/stack_test.o: tests/stack_test.c stack.h
	gcc -g -c tests/stack_test.c -o tests/stack_test.o -I.

stack.a: stack.o
	ar rc stack.a stack.o

stack: stack.o tests/stack_test.o stack.a
	gcc -g -static -o stack tests/stack_test.o stack.o stack.a
	./stack

clean:
	rm -rf *.o stack.a stack tests/stack_test.o

.PHONY: stack clean
