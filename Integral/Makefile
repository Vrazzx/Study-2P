# Цель по умолчанию
all: Integral_test

# Форматирование кода
fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +

# Проверка стиля кода
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

# Создание статической библиотеки
libmath.a: tests/integral_test.o
	ar rc libmath.a tests/integral_test.o

# Сборка тестового исполняемого файла для интеграла
Integral_test: tests/integral_test.o libmath.a
	gcc tests/integral_test.o -L. -lmath -o Integral_test -lm

# Компиляция объектного файла для теста интеграла
tests/integral_test.o: tests/integral_test.c
	gcc -c tests/integral_test.c -o tests/integral_test.o -I.

# Очистка
clean:
	rm -rf *.o libmath.a Integral_test

# Запуск программы
run:
	./Integral_test