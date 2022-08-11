#!/bin/sh

if [ -z "$1" ]
then
	echo -e "Into which branch do you want to push:"
	git branch
	read ans
else
	ans=$1
fi
echo -e "Pushing in origin $ans\n"
git push origin $ans
