#!/bin/bash

FILE="desig.lst"

echo "Enter the designation code : "
read dCode

echo "Enter the description : "
read description


if [[ ! $dCode =~ ^[0-9]+$ ]]
then
	echo "InValid designation code "
	exit 1;
fi

if [[ ! $description =~ ^[a-z,A-Z]+$ ]]
then
	echo "InValid description "
	exit 1;
fi

echo $dCode $description >> $FILE
echo "Added successfully to $FILE"
echo $FILE
cat $FILE
