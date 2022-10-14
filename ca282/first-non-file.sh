#!/bin/sh

while read filename
do
   test -f "$filename" || echo "$filename"
done
