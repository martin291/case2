#!/bin/sh

# Any image with wget will do here; we'll use alpine.

name=httpd-$( whoami )
network=$( whoami )

docker run -it --rm --network $network alpine wget -q -O - http://$name/
