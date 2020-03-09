#!/bin/sh
file=$1
if test -d $file
then 
	echo $file is a directory
	x=`expr $(find $file -type f | wc -l) + $(find $file -type d | wc -l) - 1`
	if test $x -eq 0
	then 
		rmdir $file 
		echo $file is empty and deleted
	else
		echo $file isnt empty
	fi
else
	echo $file isnt a directory
fi 