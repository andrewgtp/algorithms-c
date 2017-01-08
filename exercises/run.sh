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

options=("ANSWER-code-list" "list_ins_next_QUESTION" "list_rem_next_QUESTION" "ANSWER-code-dlist" "dlist_ins_next_QUESTION" "dlist_rem_next_QUESTION" "Quit")
PS3="Select the option above you want to compile/run.  Make sure you create your own QUESTION file first:"

select opt in "${options[@]}"
do
    case $opt in
       "ANSWER-code-list")
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
       "ANSWER-code-dlist")
            echo "RUN: dlist_ins_next_ANSWER (same as above, but includes diagrams)"
            $CC dlist.out dlist.c dlist_ins_next_ANSWER.c dlist_rem_next_ANSWER.c
            break
            ;;
       "dlist_ins_next_QUESTION")
            echo "RUN: your QUESTION code." 
            $CC dlist.out dlist.c dlist_ins_next_QUESTION.c dlist_rem_next_ANSWER.c
            break
            ;;
       "dlist_rem_next_QUESTION")
            echo "RUN: your QUESTION code." 
            $CC dlist.out dlist.c dlist_ins_next_ANSWER.c dlist_rem_next_QUESTION.c
            break
            ;;
        "Quit")
            break
            ;;
        *) echo invalid option;;
    esac
done
$OUT



