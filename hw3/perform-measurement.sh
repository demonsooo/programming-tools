#!/bin/bash

#CSE 374 HW3
#Yijia Liu 1238339

if [ $# -lt 1 ]
then
	>&2 echo "Error: need at least one arguments"
	exit 1
fi

wget -O page "$1" -q

temp=$(wc -c < "page")

rm page

echo $temp

exit