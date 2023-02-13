#!/bin/bash

num_1=$1
num_2=$2

if [ $num_1 -gt $num_2 ]; then
    echo "$num_1 is bigger."
elif [ $num_1 -lt $num_2 ]; then
    echo "$num_2 is bigger."
else
    echo "Both numbers are equal."
fi