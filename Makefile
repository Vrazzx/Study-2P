fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

run:
	find . -name "Makefile" -exec make -C \{\} \; && find . -type f -name "_test*" -executable -exec {} \;

clean:
	rm -rf *.o *.a *_test
