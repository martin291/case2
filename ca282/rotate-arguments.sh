#!/bin/sh

arg_1="$1"
shift
for arg in "$@"
    do
        echo -n "$arg "
    done
echo "$arg_1"
