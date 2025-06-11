linear_allocator.o: linear_allocator.c linear_allocator.h
	gcc -g -c linear_allocator.c -o linear_allocator.o

fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +

check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

tests/linear_allocator_tests.o: linear_allocator_tests.c linear_allocator.h
	gcc -g -c tests/linear_allocator_tests.c -o tests/linear_allocator.o -I.

linear_allocator.a: linear_allocator.o
	ar rcs linear_allocator.a linear_allocator.o

allocator: linear_allocator.o tests/linear_allocator.o linear_allocator.a
	gcc -g -o allocator linear_allocator.o tests/linear_allocator_tests.o linear_allocator.a
	./allocator

clean:
	rm -f *.o linear_allocator.a allocator tests/linear_allocator_tests.o

.PHONY: allocator clean fmt check_fmt
