#!/bin/sh

user=$( whoami )
server=server-$user
client=client-$user
network=$user

# Tidy up.
#
docker network rm $network
docker image rm $server
docker image rm $client
