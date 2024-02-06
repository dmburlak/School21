GCC= gcc -Wall -Werror -Wextra

all: s21_cat

s21_cat: s21_cat.c
	$(GCC) s21_cat.c -o s21_cat

tests: clean s21_cat	
	bash tests.sh > testresult.txt

rebuild: clean all

clang:
	cp ../../materials/linters/.clang-format .
	clang-format -n *.c *.h 
	rm .clang-format

clean:
	rm -rf s21_cat testresult.txt