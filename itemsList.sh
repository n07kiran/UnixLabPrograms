#!/bin/bash

echo "Write Item list : "

ch="y"

while [ $ch == "y" ]
do
	read item iCode
	echo $item $iCode >> items.txt

	echo "Press 'y' to continue : "
	read ch
done

echo "Added List of Items"

echo "items.txt"
cat items.txt
