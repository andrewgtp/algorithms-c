#!/bin/bash

clear
rm -f list.out
CC="gcc -o"
OUT="./list.out"

echo
echo "--------------------------------------"
echo "LIST EXERCISE"
echo "--------------------------------------"
echo
echo "Enter your code into the appropriate QUESTION file."
echo "Use the diagrams as a hint."
echo
options=("list_ins_next" "list_ins_next_ANSWER" "list_ins_next_QUESTION" "Quit")
PS3="Select the option above you want to compile/run."

select opt in "${options[@]}"
do
    case $opt in
        "list_ins_next")
            echo "RUN: list_ins_next"
            $CC list.out list.c list_ins_next.c
            break
            ;;
        "list_ins_next_ANSWER")
            echo "RUN: list_ins_next_ANSWER (same as above, but includes diagrams)"
            $CC list.out list.c list_ins_next_ANSWER.c
            break
            ;;
        "list_ins_next_QUESTION")
            echo "RUN: list_ins_next_QUESTION"
            $CC list.out list.c list_ins_next_QUESTION.c
            break
            ;;
        "Quit")
            break
            ;;
        *) echo invalid option;;
    esac
done
$OUT



