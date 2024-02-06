CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
LDFLAGS=-lcheck -lpthread
GCFLAGS= -fprofile-arcs -ftest-coverage

SRC=correct_length.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_sprintf.c s21_strchr.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strstr.c s21_strrchr.c s21_strpbrk.c s21_strncpy.c s21_strtok.c
PART5=$(wildcard part5/*.c)
TEST_SRC=$(wildcard tests/*.c)
OBJ=$(SRC:.c=.o) 
OBJPART5=$(PART5:.c=.o)
TEST_OBJ=$(TEST_SRC:.c=.o)
LIB=s21_string.a

ifeq ($(shell uname -s), Linux)
  LDFLAGS += -lsubunit -lm
endif

all: clean $(LIB)

$(LIB): $(OBJ) $(OBJPART5)
	ar cr $@ $^ $^ 

%.o: %.c 
	$(CC) $(CFLAGS)  -c $< -o $@

clang: 
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n tests/*.c tests/*.h
	clang-format -style=Google -n part5/*.c

test: $(TEST_OBJ) $(OBJ) $(OBJPART5)
	$(CC) $(CFLAGS) $(TEST_SRC) $(PART5) $(SRC) -o s21_test $(LDFLAGS) $(GCFLAGS)
	./s21_test
	mkdir -p coverage_data
	mv *.gcda coverage_data/
	mv *.gcno coverage_data/

gcov_report: clean test
	rm -f *.o tests/*.o
	lcov --capture --directory coverage_data/ --output-file coverage.info --rc lcov_branch_coverage=1
	genhtml coverage.info --output-directory html_report --title "Coverage Report" --num-spaces 4 --legend

clean:
	rm -f *.o part5/*.o tests/*.o *.a s21_test *.gcda tests/*.gcda *.gcno tests/*.gcno coverage.info
	rm -rf html_report s21_test.dSYM coverage_data