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
echo "or run the ANSWER code."
echo 
echo "Use the diagrams as a hint."
echo
options=("ANSWER-code" "list_ins_next_QUESTION" "list_rem_next_QUESTION" "Quit")
PS3="Select the option above you want to compile/run:  "

select opt in "${options[@]}"
do
    case $opt in
       "ANSWER-code")
            echo "RUN: list_ins_next_ANSWER (same as above, but includes diagrams)"
            $CC list.out list.c list_ins_next_ANSWER.c list_rem_next_ANSWER.c
            break
            ;;
       "list_ins_next_QUESTION")
            echo "RUN: your QUESTION code." 
            $CC list.out list.c list_ins_next_QUESTION.c list_rem_next_ANSWER.c
            break
            ;;
       "list_rem_next_QUESTION")
            echo "RUN: your QUESTION code." 
            $CC list.out list.c list_ins_next_ANSWER.c list_rem_next_QUESTION.c
            break
            ;;
        "Quit")
            break
            ;;
        *) echo invalid option;;
    esac
done
$OUT



