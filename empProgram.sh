#!/bin/bash

File="emp.lst"

while read line
do
	empId=$(cut -d ',' -f 1 <<< $line)
	empName=$(cut -d ',' -f 2 <<< $line)
	base=$(cut -d ',' -f 3 <<< $line)

	da=0

	if (( $base > 6000 ))
	then
		da=$(echo "$base * 0.25" | bc )
	else
		da=$(echo "$base *0.30" | bc )
	fi

	hra=$(echo "$base * 0.10" | bc )

	gSal=$( echo "$base + $da + $hra" | bc )

	echo -e "$empId\t$empName\t$base\t$da\t$hra\t$gSal"

done < $File
