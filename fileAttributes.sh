#!/bin/bash
echo "Enter the File Name : "
read fileName

#for fileName in *
#do
if [ -f $fileName ]
then
	echo "========================================"
	permission=$( stat -c "%A" $fileName )
	size=$( stat -c "%s" $fileName )

	linkCount=$( stat -c "%h" $fileName )
	linkExist="False"

	if (( linkCount > 0 ))
	then
		linkExist="True"
	fi

	echo "FileName : $fileName"
	echo "Permissions : $permission"
	echo "Size : $size bytes"
	echo "Existence of link : $linkExist"
	echo "No of hard links  : $linkCount"
	echo "========================================="

else
	echo "File does not exist"
fi
#done
