Instructions
============

First, fork this repo.

When you are done, push your solution back to the master branch in your own
repo.

If you are able to run docker locally, then that's fine.

If not, you can use the docker server here:

  https://ca282.computing.dcu.ie/termcast/docker/

You should be able to "git clone" your fork of this repo on that server.

Complete the Dockerfile in the server directory to define a new server
image.

Complete the Dockerfile in the client directory to define a new client
image.

Your server and client images will be built using the script "run.sh" in
this directory.

When the client is run, it must output the message:

  "Nobody expects the Spanish Inquisition!"

The details of the format of the output do not matter (nor do trivial
spelling or punctuation errors).  Your output could be a textual message
as above, or the words could be the rows or the columns of a database
table written to standard output.

What matters is that the words are fetched by the client from the server.

So, these words *must not* be embedded within the client at all.

One obvious and relatively straightforward way of achieving this is by
having the server run httpd, and having the client use "wget" to fetch
the message from the server.

The marks for this approach (or similar) will be capped at 60%.

I am imagining that some alternative approaches might be more ambitious than
others.  For example, an approach involving a redis server might be only
slightly more ambitious than the HTTP approach, whereas one in which the
client uses SSH to access the server might be substantially more ambitious.

Higher marks will be awarded for more ambitious solutions.

There are no attempt marks.

For the client, you should use the ENTRYPOINT directive to set the command
which executes when the client is launched:

  https://docs.docker.com/engine/reference/builder/#entrypoint

The client container will then usually exit immediately (because the
entrypoint command likely fetches the message and exits, like wget).
