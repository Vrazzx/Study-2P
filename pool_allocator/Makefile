all: pool_test

fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

liballoc.a: pool_allocator_func.o
	ar rc liballoc.a pool_allocator_func.o

pool_test: tests.o liballoc.a
	gcc tests.o -L. -lalloc -o pool_test -lm

tests.o: tests.c
	gcc -c tests.c -o tests.o -I.  

pool_allocator_func.o: pool_allocator_func.c
	gcc -c pool_allocator_func.c -o pool_allocator_func.o -I.

run:
	./pool_test

clean:
	rm -rf *.o *.a *_test
