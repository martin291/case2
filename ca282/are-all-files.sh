#!/bin/sh

set -e

for arg in "$@"
do
    test -f "$arg"
done
