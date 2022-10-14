#!/bin/sh

# You may need to change this port.
#
port=8011

echo "wget http://localhost:$port/$1" >&2
wget -O - -q http://localhost:$port/$1
