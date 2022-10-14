#!/bin/sh

# IMPORTANT!
#
# This script hasn't actually been tested properly.
# It may contain bugs.
#
# If you find a bug, then please let me know.
#
# Better still, submit an MR here:
#
#   https://gitlab.computing.dcu.ie/sblott/ca282-docker-demo).
#

# Merging changes...
#
# Should there be any additions to this repo, you can merge them as follows:
#
#   $ git remote add sblott https://gitlab.computing.dcu.ie/sblott/ca282-docker-demo.git
#   $ git fetch sblott
#   $ git merge sblott/master
#

# Stop/fail immediately if any of these commands fail.
# (We'll have to tidy up by hand.)
#
set -e

user=$( whoami )
server=server-$user
client=client-$user
network=$user

# Build the images.
#
docker build -t $server ./server
docker build -t $client ./client

# Create the network.
#
docker network create $user

# Start the server.
#
docker run --detach --rm --name $server --network $network $server

# Run the client.
#
docker run -it --rm --name $client --network $network --env SERVER=$server $client

# Stop the server
#
docker container stop $server

# Tidy up.
#
docker network rm $network
docker image rm $server
docker image rm $client
