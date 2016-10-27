#!/bin/bash

#CSE 374 HW2
#Yijia Liu 1238339

if [ $# -lt 2 ]
then
	>&2 echo "Error: need at least two arguments"
	exit 1
fi

f1="$1"

date >> "f1"

shift
wc -l "$@" >> "f1"

#include a total line even if only a single file appears in the list
if [ $# -eq 1 ]
then
    temp=$(wc -l "$1" | grep -Eo "^\s*[0-9]+" )
    echo $temp" total" >> "f1"
fi

exit