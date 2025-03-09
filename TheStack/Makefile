# правило для сборки объектного файла stack.o
stack.o: stack.c stack.h
	gcc -g -c stack.c -o stack.o

# правило для сборки объектного файла tests/stack_test.o
tests/stack_test.o: tests/stack_test.c stack.h
	gcc -g -c tests/stack_test.c -o tests/stack_test.o -I.

# исполняемый файл
stack.a: stack.o
	ar rc stack.a stack.o

# сборка и запуск
stack: stack.o tests/stack_test.o stack.a
	gcc -g -static -o stack tests/stack_test.o stack.o stack.a
	./stack

# очиска объектных файлов
clean:
	rm -rf *.o stack.a stack tests/stack_test.o

# чтобы запускался вообще всегда, даже когда не требуется обновление
.PHONY: stack clean
