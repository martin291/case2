#!/bin/sh

for file in "$@"
do
    if test -d "$file"
    then
        echo "$file" "directory"
    elif test -f "$file"
    then
        echo "$file" "file"
    else
        echo "$file" "does not exist"
    fi
done
