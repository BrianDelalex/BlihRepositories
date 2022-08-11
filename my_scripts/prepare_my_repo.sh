#!/bin/bash

blih -u brian.delalex@epitech.eu repository create $1 
blih -u brian.delalex@epitech.eu repository setacl $1 ramassage-tek r
blih -u brian.delalex@epitech.eu repository getacl $1
git clone git@git.epitech.eu:/brian.delalex@epitech.eu/$1
cp -r /home/bdelalex/Delivery/new_repo/* $1
