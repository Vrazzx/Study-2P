# Цель по умолчанию
all: integral_test

# Форматирование кода
fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +

# Проверка стиля кода
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

# Создание статической библиотеки
libmath.a: tests/integral_test.o integral.o
	ar rc libmath.a tests/integral_test.o integral.o

# Сборка тестового исполняемого файла для интеграла
integral_test: tests/integral_test.o libmath.a
	gcc tests/integral_test.o -L. -lmath -o integral_test -lm

# Компиляция объектного файла для теста интеграла
tests/integral_test.o: tests/integral_test.c
	gcc -c tests/integral_test.c -o tests/integral_test.o -I.

# Компиляция объектного файла для integral.c
integral.o: integral.c
	gcc -c integral.c -o integral.o -I.

# Очистка
clean:
	rm -rf *.o libmath.a integral_test tests/integral_test.o

# Запуск программы
run:
	./integral_test
