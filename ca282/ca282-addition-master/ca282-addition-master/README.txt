CA282 Addition repo
-------------------

src/         - various implementations of a program to add together
               their command-line arguments.

src/Makefile - contains a target "build" which should build any
               executables (for languages like C or Java).

Makefile     - contains a target "test" which "tests" the various
               implementations.  Poor man's tests, but you should
	       be able to work out what's going on.

Example:

    zsh src/add-arguments.zsh 1 -2 3
    # Writes "6" to standard output.

Report on your progress
----------------------

- python2 would not pass 'make test' as it does not seem to be installed on termcast student server.
- Had to comment it out to pass 'make test' command and other tests, or replace 'python2' with 'python3'.

- Needed to use vim for indentation in Makefile and src/Makefile, otherwise an error could occur.

- The lab was a bit laborious and puzzling, but it was good practice and some useful skills were gained.
