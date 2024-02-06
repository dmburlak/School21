CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
CHECKFL=-lcheck -lpthread
GCFLAGS=-fprofile-arcs -ftest-coverage
SRC=$(wildcard *.c)
TESTS=$(wildcard tests/*.c)
OBJECTS=$(SRC:.c=.o)

ifeq ($(shell uname -s), Linux)
  CHECKFL += -lsubunit -lm -lrt
endif

all: s21_math.a

s21_math.a: $(OBJECTS)
	ar rcs $@ $?

%.o: %.c
	$(CC) $(FLAGS) -c $?

test: s21_math.a
	$(CC) $(FLAGS) $(TESTS) $(SRC) -o test_cases $(CHECKFL) $(GCFLAGS)
	./test_cases
	mkdir -p coverage_data
	mv *.gcda *.gcno coverage_data/

gcov_report: test
	lcov --capture --directory coverage_data/ --output-file coverage.info --rc lcov_branch_coverage=1
	genhtml coverage.info --output-directory html_report --title "Coverage Report" --num-spaces 4 --legend

clang:
	clang-format -style=Google -n *.c *.h tests/*.c tests/*.h

clean:
	rm -f s21_test *.o */*.o *.a coverage.info *.gcda */*.gcda *.gcno */*.gcno
	rm -rf html_report coverage_data test_cases* leaks_output