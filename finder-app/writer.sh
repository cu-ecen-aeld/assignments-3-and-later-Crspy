#!/bin/sh

set -e
set -u

if [ $# -ne 2 ]
then
	echo "Expected 2 arguments: finder.sh <writefile> <writestr>"
    exit 1
fi
writefile=$1
writestr=$2

mkdir -p "$(dirname "${writefile}")" && touch "${writefile}"

echo ${writestr} > ${writefile}