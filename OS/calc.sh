#!/bin/bash
a=$1
b=$3
op=$2
case "$op" in
		"+") echo "The ans is $((a + b))"
		;;
		"-") echo "The ans is $((a - b))"
		;;
		"x") echo "The ans is $((a * b))"
		;;
		"/") echo "The ans is $((a / b))"
		;;
		*) echo "wrong"
		exit 1
		;;
esac
