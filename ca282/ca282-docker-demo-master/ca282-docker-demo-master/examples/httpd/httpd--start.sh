#!/bin/sh

# You may need to change this port.
#
port=8011

name=httpd-$( whoami )

docker run --rm --detach --name $name --publish $port:80 httpd
