GCC= gcc -Wall -Werror -Wextra

all: s21_grep

s21_cat: s21_grep.c
	$(GCC) s21_grep.c -o s21_grep

tests: clean s21_grep
	bash tests.sh > testresult.txt

clang:
	cp ../../materials/linters/.clang-format .
	clang-format -n *.c *.h 
	rm .clang-format

rebuild: clean all

clean:
	rm -rf s21_grep testresult.txt