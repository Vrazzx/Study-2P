all: arraylist_test

clean:
	rm -rf *.o *.a *_test

fmt:
	find . -regex ".*\.[ch]" -exec clang-format -style=LLVM -i {} \;

check_fmt:
	find . -regex ".*\.[ch]" -exec clang-format -style=LLVM --dry-run --Werror {} \;

#----- Pool Allocator
pool_allocator.o: pool_allocator.c 
	gcc -g -c pool_allocator.c -o pool_allocator.o

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o

#----- ArrayList
arraylist.o: arraylist.c arraylist.h 
	gcc -g -c arraylist.c -o arraylist.o

arraylist.a: arraylist.o
	ar rc arraylist.a arraylist.o

arraylist_test.o: arraylist_test.c 
	gcc -g -c arraylist_test.c -o arraylist_test.o

arraylist_test: arraylist_test.o arraylist.a pool_allocator.a
	gcc -g -static arraylist_test.o arraylist.a pool_allocator.a -o arraylist_test

#------ Tests
test: arraylist_test
	@for test in $(shell find . -maxdepth 1 -type f -name '*_test'); do \
		echo "$$test is running"; \
		./$$test || exit 1; \
	done