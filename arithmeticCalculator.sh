#!/bin/bash

echo "Enter a : "
read a

echo "Enter b : "
read b

echo "Operation Choice : "
echo "1.Add"
echo "2.Sub"
echo "3.Multiply"
echo "4.Divide"
echo "5.Modulo"
echo "6.Exit"


while [ true ]
do
	echo "Enter your choice : "
	read ch

	case $ch in
		1 )
			x=$(( a + b ))
			echo "$a + $b = $x" ;;
		2 )
			x=$(( a - b ))
			echo "$a - $b = $x" ;;
		3 )
			x=$(( a * b ))
			echo "$a * $b = $x" ;;
		4 )
			x=$(( a / b ))
			echo "$a / $b = $x" ;;
		5 )
			x=$(( a % b ))
			echo "$a % $b = $x" ;;
		6 )
			echo "Thank You"
			exit ;;
		* )
			echo "InValid Choice" ;;
	esac
done
