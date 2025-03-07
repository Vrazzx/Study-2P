# Цель по умолчанию
all: Task2_test

# Форматирование кода
fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM -i {} +

# Проверка стиля кода
check_fmt:
	find . -regex '.*\.[ch]' -exec clang-format -style=LLVM --dry-run --Werror {} +

# Создание статической библиотеки
libmath.a:  integral_test.o
	ar rc libmath.a  integral_test.o

# Сборка тестового исполняемого файла для интеграла
Task2_test: integral_test.o libmath.a
	gcc integral_test.o -L. -lmath -o Task2_test -lm

# Компиляция объектного файла для теста интеграла
integral_test.o: integral_test.c
	gcc -c integral_test.c -o integral_test.o

# Компиляция объектного файла для функции интеграла
integral.o: integral.c
	gcc -c integral.c -o integral.o

# Очистка
clean:
	rm -rf *.o libmath.a Task1_test Task2_test
ispolt:
	make Task2_test && ./Task2_test