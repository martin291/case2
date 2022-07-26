#!/bin/sh

image=hello-again-$( whoami )
docker run --rm $image
