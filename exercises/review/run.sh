#!/bin/bash

clear
rm -f pointers.out
CC="gcc -o"
OUT="./pointers.out"

echo
echo "--------------------------------------"
echo "LIST EXERCISE"
echo "--------------------------------------"
echo
echo "Choose file to compile and run."
echo
options=(
"pointers.c" 
"Quit")
PS3="Select the option above you want to compile/run:  "

select opt in "${options[@]}"
do
    case $opt in
       "pointers.c")
            echo "RUN: pointers.c "
            $CC pointers.out pointers.c utils.c -I utils.h
            break
            ;;
        "Quit")
            break
            ;;
        *) echo invalid option;;
    esac
done
clear
$OUT



