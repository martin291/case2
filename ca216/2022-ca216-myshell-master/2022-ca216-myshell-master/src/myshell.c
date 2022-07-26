/*
Name: myshell
Author: Martin Derwin
Student ID: 20439162

Functions:
	- main, shell_help, shell_clear, shell_dir, shell_cd, shell_environ, shell_echo,
	  shell_external, io_redirection, sighandler, syserr

Description:
	- myshell is a command line interpreter.
	- External commands are forked and execed.
	- dir, environ, echo and help commands are also forked and execed.
	- IO redirection is supported by using freopen to open the files and send stdout to them or take stdin from them using fgets.
	- Input is tokenized.
	- Child process checks what command the User has input using if statements.
	- Child process sends the command along with its argument/s to a seperate function.
	- This function contains an exec command which will then replace the child process with the given command.
	- This ends the Child process.
	- The Parent process waits for the Child process to finish before continuing, unless background execution has been invoked using "&".
	- Batchfiles are also supported by checking if argv[1] exists.

Date: 4/3/22

Acknowledgments:
	- I understand that there is zero tolerance towards plagiarism for this assignment and module.
	- The basis code for this assignment is taken from the CA216 "Building a Shell" lab.
	- Code for implementing the functions 'sighandler' and 'syserr' is also taken from this lab.
*/

#include "myshell.h" 											// headers

int main (int argc, char ** argv)
{
	signal(SIGINT, sighandler);				   					// signal handler (for ^C)

    char buf[MAX_BUFFER];                      					// line buffer
    char * args[MAX_ARGS];                     					// pointers to arg strings
    char * prompt = "~~> " ;                    				// shell prompt

    pid_t pid;            										// process ID

	int bg = 0;			  										// flag for background execution

    pid = getpid();       										// get our own pid

	if(argc > 1) 												// batch file
	{
		// if argv[1] argument exists (command line argument)
		// argv[1] is assumed to be a file, input is taken from the file

		FILE *batchfile = freopen(argv[1], "r", stdin); 		//open batchfile
		if(batchfile == NULL) { 								// error check
			return 2;
		}
		printf("Success, opened file\n");
	}

	/* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin))
	{
		char cwd[256];
		if(argc == 1) 									// disables any unwanted shell prompt when User is using a batchfile
		{
			if (getcwd(cwd, sizeof(cwd)) != NULL)
			{
				printf("%s ", cwd); 					// if cwd is not NULL we print the current path
			}
			fputs (prompt, stdout); 					// write prompt
		}
		char* path = cwd;
		strcat(path, "/myshell"); 						// add /myshell to the path for the shell executable
		setenv("SHELL", path, 1); 						// change the string variable for SHELL
		setenv("PARENT", path, 1); 						// change the string variable for PARENT


        if (fgets (buf, MAX_BUFFER, stdin )) { 			// read a line
			/* tokenize input */
			char* token;
			token = strtok(buf, SEPARATORS);			// token is size of buf and the delimiter is SEPARATORS
			int token_count = 0; 						// Count tokens, we need this for batchfile
			for(; token != NULL ; token_count += 1)
			{
				args[token_count] = token;				// tokenize input
				token = strtok(NULL, SEPARATORS);
			}
			int last = token_count; 					// value at last index
			args[last] = NULL;

			if (!strcmp(args[0], "cd")) { 				// "cd" command
				if (args[1]) { 							// if a second argument (directory name) exists send this to the function shell_cd
					shell_cd(args[1]);
					continue;
				}
				else
				{
					printf("Please enter directory name!\n");
					shell_cd(NULL); 					// otherwise no second argument exists, so send NULL to shell_cd, current directory will be displayed
					continue;
				}
				continue;
			}
			else if (!strcmp(args[0],"clr")) { 			// "clear" command
				shell_clear();
				continue;
			}
			else if (!strcmp(args[0],"quit"))   		// "quit" command
			{
				break;                    				 // break out of 'while' loop
			}
			else if (!strcmp(args[0], "pause")) 		// "pause" command
			{
				printf("Press ENTER to continue...\n");
				getchar(); 								// waits for ENTER to be pressed
				continue;
			}

			if (!strcmp(args[token_count - 1], "&")) 	// background execution
			{
				// if the last argument is &
				args[token_count - 1] = NULL; 			// set it to NULL
				bg = 1; 								// change flag for background execution to 1
			}

			/*
				use fork to create a seperate duplicate child process
				exec command which will then replace the child process with the given command
				this will then end the child process
			*/

			switch (pid = fork())
			{
				case -1:			// error occured
					syserr("fork");
				case 0: 			//child

					io_redirection(args); // io redirection

					// last entry will be NULL

					if (args[0]) {                    						 // if there's anything there
					/* check for internal/external command */
						if (!strcmp(args[0], "help")) 						// operation manual, "help" command
						{
							shell_help();
						}
						else if (!strcmp(args[0], "dir")) { 				// "dir" command
							if(args[1]) {
								shell_dir(args[1]); 						// if second argument (directory name) exists, send that to shell_dir
								continue;
							}
							else {
								shell_dir(NULL); 							// else send NULL, current directory info will be displayed
								continue;
							}
							continue;
						}
						else if (!strcmp(args[0], "environ")) { 			// "environ" command
							shell_environ();
							continue;
						}
						else if (!strcmp(args[0], "echo")) { 				// "echo command"
							if(args[1]) {
								shell_echo(args); 		// send the comment to shell_echo
								continue;
							}
							exit(0); 						// if args[1], etc. do not exist we must exit the child process
						}
						else { 								// if none of the myshell commands are recognised
							shell_external(args); 			// command must be external
							exit(0); 						// or invalid, then exit to end the child process
						}
					}

				default: // parent

					/*
						if bg = 1, we dont want to use the wait command, the parent process will
						continue without waiting for the child process to finish
					*/

					if (bg) { 								// check for background execution
						bg = 0; 							// change flag to 0, unwanted bg execution will not occur for the following input from the User
						continue;
					}
					else
					{
						(void)waitpid(pid, 0, 0); 			// wait for the child process to finish
						continue;
					}
			}
		}
	}
	return 0;
}