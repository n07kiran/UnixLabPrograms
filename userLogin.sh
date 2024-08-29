#!/bin/bash

who | cut -d " " -f 1 | sort | uniq > uniqUsers.txt

echo "Enter the username : "
read userName

if grep -q "$userName" "uniqUsers.txt";
then
	echo "User Exists!"
else
	echo "User does not Exists!"
fi
