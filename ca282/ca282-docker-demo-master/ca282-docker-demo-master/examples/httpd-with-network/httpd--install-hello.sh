#!/bin/sh

name=httpd-$( whoami )

docker cp ./hello.txt $name:/usr/local/apache2/htdocs/
