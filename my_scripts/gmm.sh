#!/bin/sh

current=$(git branch --show-current)
read -p "Merge master into $current [Y/n]" ans
if [[ "$ans" == "y" || "$ans" == "Y" || "$ans" = "" ]]
then
    echo -e "exec git merge master\n"
    git merge master
else
    echo -e "Good idea !"
fi
