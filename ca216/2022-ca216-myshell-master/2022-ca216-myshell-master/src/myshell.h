#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token separators

extern char **environ;
extern int errno;                               // system error number
void syserr(char*);                             // error report and abort routine
void sighandler(int signum);                    // handle ^C

void shell_clear();                             // clear the shell
void shell_dir(char* dir);                      // show target directory contents
void shell_environ();                           // print environmental strings
void shell_echo(char** comment);                 // echo comment
void shell_cd(char* path);                      // chance directory
void shell_external(char **args);               // any external command
void shell_help();                              // open the help manual

void io_redirection(char ** args);              // i/o redirection

