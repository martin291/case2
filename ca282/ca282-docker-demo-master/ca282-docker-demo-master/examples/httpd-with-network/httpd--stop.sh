#!/bin/sh

name=httpd-$( whoami )
network=$( whoami )

docker container stop $name
docker network rm $network
