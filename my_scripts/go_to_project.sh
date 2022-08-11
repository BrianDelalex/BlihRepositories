#!/usr/bin/bash

VAR2=$(ls | grep *$1*)
echo $VAR2
echo $(find /home -name $VAR2)
$OLDPWD=$PWD
$PWD $(find /home -name $VAR2)
