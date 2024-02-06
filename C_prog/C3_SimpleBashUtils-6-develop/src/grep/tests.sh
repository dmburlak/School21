#!/bin/bash
SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""

s21_command=(
    "./s21_grep"
    )

sys_command=(
    "grep"
    )

check=(
"-n for test_files/test_1_grep.txt test_files/test_2_grep.txt"
"-sin -e fOr no_file.txt test_files/test_1_grep.txt"
"-n -e ^\} test_files/test_1_grep.txt"
"-c -f test_files/pattern1.txt -f test_files/pattern2.txt test_files/test_1_grep.txt"
"-ce ^int test_files/test_1_grep.txt test_files/test_2_grep.txt"
"-e ^int test_files/test_1_grep.txt"
"-nivh = test_files/test_1_grep.txt test_files/test_2_grep.txt"
"-livsonch -e char -f no_file.txt "
"-ie INT test_files/test_5_grep.txt"
"-e char test_files/test_1_grep.txt test_files/test_2_grep.txt"
"-ne = -e out test_files/test_5_grep.txt"
"-iv int test_files/test_5_grep.txt"
"-in int test_files/test_5_grep.txt"
"-c -l aboba test_files/test_1_grep.txt test_files/test_5_grep.txt"
"-v -e ank test_files/test_1_grep.txt"
"-l for test_files/test_1_grep.txt test_files/test_2_grep.txt"
"-o -e int test_files/test_4_grep.txt"
"-e = -e out test_files/test_5_grep.txt"
"-e ing -e as -e the -e not -e is test_files/test_6_grep.txt"
"-c -e . -e '.' test_files/test_1_grep.txt"
"-l for no_file.txt test_files/test_2_grep.txt"
"-e int -i s21_grep.c grep_struct.h"
"-tw test_files/test_3_grep.txt test_files/test_5_grep.txt"
)

run_test() {
    param=$(echo "$@" | sed "s/FLAGS/$var/")
    "${s21_command[@]}" $param > "${s21_command[@]}".log
    "${sys_command[@]}" $param > "${sys_command[@]}".log
    DIFF="$(diff -s "${s21_command[@]}".log "${sys_command[@]}".log)"
    let "COUNTER++"
    if [ "$DIFF" == "Files "${s21_command[@]}".log and "${sys_command[@]}".log are identical" ]
    then
        let "SUCCESS++"
        echo "$COUNTER - Success $param"
    else
        let "FAIL++"
        echo "$COUNTER - Fail $param"
    fi
    rm -f "${s21_command[@]}".log "${sys_command[@]}".log
}

for i in "${check[@]}"
do
    var="-"
    run_test "$i"
done

printf "\n"
echo "FAILED: $FAIL"
echo "SUCCESSFUL: $SUCCESS"
echo "ALL: $COUNTER"
