#!/bin/sh

read -r -p "Are you really going to push into master ? [Y/n] " ans
if [[ "$ans" == "y" || "$ans" == "Y" || "$ans" = "" ]]
then
    echo -e "Pushing master\n"
    git push origin master
else
    echo -e "Good idea !"
fi
