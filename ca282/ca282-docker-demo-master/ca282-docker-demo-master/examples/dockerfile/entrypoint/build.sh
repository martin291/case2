#!/bin/sh

image=hello-again-$( whoami )
docker build -t $image .
