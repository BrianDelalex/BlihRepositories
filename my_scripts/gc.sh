#!/bin/sh

if [ -z "$1" ]
then
	echo -e "Into which branch do you want to checkout:"
	git branch
	read ans
else
	ans=$1
fi
echo -e "exec git checkout $ans\n"
git checkout $ans
