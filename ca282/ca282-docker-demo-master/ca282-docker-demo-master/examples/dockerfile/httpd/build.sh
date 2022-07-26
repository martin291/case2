#!/bin/sh

image=httpd-again-$( whoami )
docker build -t $image .
