#!/bin/bash

echo "Enter first Number: "
read num_1

echo "Enter second Number: "
read num_2

if [ $num_1 -gt $num_2 ]; then
    echo "$num_1 is bigger."
elif [ $num_1 -lt $num_2 ]; then
    echo "$num_2 is bigger."
else
    echo "Both numbers are equal."
fi