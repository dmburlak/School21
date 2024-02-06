CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
CHECKFL=-lcheck -lpthread
GCFLAGS=-fprofile-arcs -ftest-coverage
SRC=$(wildcard functions/*/*.c)
TESTS=$(wildcard tests/*/*.c tests/*.c)
OBJ=$(SRC:.c=.o)
TEST_OBJ=$(TESTS:.c=.o)

ifeq ($(shell uname -s), Linux)
  CHECKFL += -lrt -lsubunit -lm
endif

all: clean s21_decimal.a

s21_decimal.a: $(OBJ)
	ar cr $@ $?

%.o: %.c
	$(CC) $(FLAGS) -c $? -o $@

clang:
	clang-format -style=Google -n $(SRC) $(TESTS)

test: clean
	$(CC) $(FLAGS) $(SRC) $(TESTS) -o test_cases $(CHECKFL) $(GCFLAGS)
	./test_cases
	mkdir -p coverage_data
	mv *.gcda *.gcno coverage_data

gcov_report: test
	lcov --capture --directory coverage_data/ --output-file coverage.info --rc lcov_branch_coverage=1
	genhtml coverage.info --output-directory html_report --title "Coverage Report" --num-spaces 4 --legend

clean:
	rm -rf *.a test_cases coverage* html* functions/*/*.o