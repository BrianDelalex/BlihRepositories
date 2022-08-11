#!/bin/sh

current=$(git branch --show-current)
if [ -z "$1" ]
then
	echo -e "Branch to merge into $current:"
	git branch
	read ans
else
	ans=$1
fi
echo -e "Merging $ans --> $current"
git merge $ans
