#!/bin/sh

name=httpd-$( whoami )

docker container stop $name
