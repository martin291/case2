#!/bin/sh

# You may need to change this port.
#
port=8011

name=httpd-$( whoami )
network=$( whoami )

docker network create $network
docker run --rm --detach --name $name --network $network httpd
