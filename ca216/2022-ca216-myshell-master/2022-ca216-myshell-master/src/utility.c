#include "myshell.h" 									// headers

void shell_help()	// open the help manual
{
    execlp("more", "more", "-df", "../manual/readme.md", NULL); 	// -d displays command to quit, -f stops text from wrapping
	syserr("execl"); 									// check execlp worked
}

void shell_clear()	// clear the shell
{
	system("clear"); 									// use system to fork and exec command to clear the screen
}

void shell_dir(char* dir) 	// show target directory contents
{	if(dir == NULL)
	{
		execlp("ls", "ls", "-al", NULL);
	}
	else
	{
		char argument[256] = "";
		strcpy(argument, dir);
		execlp("ls", "ls", "-al", argument, NULL);
	}
	syserr("execl"); 									// check execlp worked
}

void shell_environ() 	// print environmental strings
{
	execlp("env", "env", NULL);
	syserr("execl"); 									// check execlp worked
}

void shell_echo(char** comment) 	// echo comment
{
	execvp("echo", comment);
	syserr("execv"); 									// check execvp worked
}

void shell_cd(char* path) 	// change directory
{
	char cwd[256];
	if(path != NULL)
	{
		chdir(path); 									// change directory/path to the new directory/path
	}
	setenv("PWD", getcwd(cwd, sizeof(cwd)), 1); 		// use setenv to change the enviromental string PWD
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current Directory: %s\n", cwd); 		// if cwd is not NULL we print the current path
	}
}

void shell_external(char **args) // external commands
{
	execvp(args[0], args);
	syserr("execv"); 									// check execvp worked
}

void io_redirection(char **args) // io redirection
{
	for(int i = 1; args[i] != NULL; i++)
	{
		if(!strcmp(args[i], "<")) 						// input
		{
			char argument[256];
			FILE *in_file = freopen(args[i + 1], "r", stdin);
			if(!in_file)
			{
				exit(1);
			}
			else {

				fgets(argument, 256, stdin);

				char* check_output_file = ""; 			// checks if we want to send the standard output to an output file
				char* output_file = ""; 				// the output file

				if(args[i + 2] != NULL) 				// if ">" or ">>" is in command line
				{
					check_output_file = args[i + 2];
					output_file = args[i + 3];
				}

				char* token;
				token = strtok(argument, SEPARATORS);	// token is size of argument and the delimiter is SEPARATORS
				int j = 1;

				for(; token != NULL ; j += 1)
				{
					args[j] = token;					// tokenize input as argument
					token = strtok(NULL, SEPARATORS);
				}

				args[j] = NULL;

				if(!strcmp(check_output_file, ">"))
				{
					FILE *out_file = freopen(output_file, "w", stdout);
					if(!out_file)
					{
						exit(1);
					}
					break;
				}
				else if(!strcmp(check_output_file, ">>"))
				{
					FILE *out_file = freopen(output_file, "a+", stdout);
					if(!out_file)
					{
						exit(1);
					}
					break;
				}
				else{
					break; 						// if User is not sending the input to another file break from the loop and display output on the User's screen
				}
				break;
			}
		}
		if(!strcmp(args[i], ">")) // output
		{
			FILE *out_file = freopen(args[i + 1], "w", stdout); 		//open file, write standard output to file
			if(!out_file) 												// error check
			{
				exit(1);
			}
			args[i] = NULL;
			break;

		}
		if(!strcmp(args[i], ">>")) // append output
		{
			FILE *out_file = freopen(args[i + 1], "a+", stdout); 		//open file, append standard output to file
			if(!out_file) 												// error check
			{
				exit(1);
			}
			args[i] = NULL;
			break;
		}
	}
}

void sighandler(int signum) // catch and handle ^C
{
	printf("\nReceived a signal %d.\n", signum);
	printf("Press ENTER to confirm!\n");
	getchar();
	printf("Exiting...\n");
	exit(0);
}

void syserr(char * msg)   // report error code and abort
{
	fprintf(stderr,"ERROR OCCURED, %s: %s\n", strerror(errno), msg); 					// display error message
	abort();
}