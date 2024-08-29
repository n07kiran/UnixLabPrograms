#!/bin/bash

echo "Menu : "
echo "1. pwd"
echo "2. ls"
echo "3. whoami"
echo "4. Date"
echo "5. ps"
echo "6. Shell"
echo "7. Exit"


while [ true ];
do
	echo -n "Please enter your choice : "
	read choice

	case $choice in 
		1 )
			pwd ;;
		2 )
			ls ;;
		3 )
			whoami ;;
		4 )
			date ;;
		5 )
			ps ;;
		6 )
			echo $SHELL ;;
		7 )
			echo "Thank You"
			exit;;
		* )
			echo "InValid Choice"

	esac
done
