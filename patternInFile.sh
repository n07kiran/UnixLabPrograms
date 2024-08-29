#!/bin/bash

echo "Enter the fileName : "
read fileName

echo "Enter the pattern : "
read pattern

if [ -f $fileName ]
then
	grep "$pattern" "$fileName"

	if (( $? == 0 ))
	then
		echo "Pattern Matched"
	else
		echo "Pattern didn't match"
	fi
else
	echo "File : $fileName does not exist"
fi
