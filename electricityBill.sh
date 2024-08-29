#!/bin/bash

echo "Enter the no of units consumed : "
read units

cost=0

if (( units <= 200 ))
then
	cost=$( echo " $units * 0.80 " | bc )
elif (( units <= 300 ))
then
	cost=$( echo " ($units-200) * 0.90 + 160 " | bc )
else
	cost=$( echo " ($units-300) + 160 + 90 " | bc )
fi


cost=$( echo "$cost + 100" | bc )

echo "$cost"

if (( $( echo "$cost > 400" | bc ) ))
then
	cost=$( echo " $cost * 1.15 " | bc )
fi

echo "Total Cost : $cost "
