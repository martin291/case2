#!/bin/sh

# Any image with wget will do here; we'll use alpine.

network=$( whoami )

docker run -it --rm --network $network alpine
