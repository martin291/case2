# myshell Operation Manual

## Name
- myshell

## Description
- ***myshell*** is a command line interpreter. It supports a list of simple internal shell commands. External commands are also supported.

## Commands

***cd***

### Name
- cd - change current directory

### SYNTAX
- cd [DIRECTORY]

### DESCRIPTION
- Changes User's current directory to DIRECTORY. Display's DIRECTORY's path. If no argument is given, the current directory's path will be displayed.

### EXAMPLE
- cd ../
Outputs path of the previous directory in the User's path.

***clr***

### NAME
- clr - clear the screen

### SYNTAX
- clr

### DESCRIPTION
- Erase the current screen content of ***myshell***. Takes no arguments

***dir***

### NAME
- dir - list directory contents

### SYNTAX
- dir [DIRECTORY]

### DESCRIPTION
- List information about the DIRECTORY (default is current directory). Sort entries alphabetically. Equivalent to ls -al [DIRECTORY].

### EXAMPLE
- dir ../
Outputs list of contents of previous directory in the User's path.

***environ***

### NAME
-  environ - list all the environment strings

### SYNTAX
- environ

### DESCRIPTION
- Outputs all the environment strings. Takes no arguments.

***echo***

### NAME
- echo - display a line of given text

### SYNTAX
- echo [STRING]

### DESCRIPTION
- Outputs STRING

### EXAMPLE
- echo foo
Outputs foo followed by a new line.

***help***

### NAME
- help - display user operation manual

### SYNTAX
- help

### DESCRIPTION
- Outputs user manual (readme.md file contents). Takes no arguments.

***pause***

### NAME
- pause - pause operation of the shell until ENTER is pressed

### SYNTAX
- pause

### DESCRIPTION
- Pauses operation of the shell. ***myshell*** waits  until the User presses ENTER to continue operation. Takes no arguments.

***quit***

### NAME
- quit - Exit the shell

### SYNTAX
- quit

### DESCRIPTION
- Quits the shell. User exits ***myshell***. Takes no arguments.

## Enviroment Concept
***myshell*** is a C program. Start the program by using the command ./myshell. The files for ***myshell*** in the makefile can be compiled using the make command. Once ***myshell*** starts, a shell prompt "~~>" shall appear. The User can then input a command. The output will then be displayed on the User's screen unless output redirection has been invoked. Another shell prompt will appear, meaning the User can input their next command. Use the quit command or ^C to exit.

## Process Concept
***myshell*** handles the following commands using fork and exec system calls: *dir*, *environ*, *echo* and *help*. It also uses fork and exec for external commands. ***myshell*** uses fork to create a seperate duplicate process. This child process then checks what command the User has input and sends that command along with its argument/s to a seperate function. This function contains an exec command which will then replace the child process with the given command. This will then end the child process. The parent process waits for the child process to finish before continuing. Examples of using fork and exec can be found in [3]. See the shared characteristics and differences between the Parent and Child process in [4].

## Background Execution
***myshell*** supports background execution. Background execution is invoked by ending the command input with &. After background execution is invoked, the shell prompt will appear instantly, waiting for the next command. The command in the background will continue to run until it has finished.

#### Example
- dir ../ &
Runs dir ../ in the background, outputs to User's display.

### Difference between Background execution and Foreground execution
Background execution can handle several commands at once. Foreground execution can only handle one command at a time. Background execution works by creating a child process to handle the command given by the User. The parent does not wait for this child to finish before displaying the prompt for the next User input. "A Ctrl-C from the keyboard does not terminate a background process" [3]. "A daemon is a background process that normally runs indefinitely" [3]. Examples of Background execution can be found in [3].

## I/O Redirection
***myshell*** supports Input/Output redirection. Send *Output* to a file using the > and >> operator. User can also take command line *Input* from a file, see **Batchfiles** for more information.

Every program initially has at least the standard input and standard output I/O data streams available to it [1]. These streams are numbered 0 (stdin) and 1 (stdout). Standard error (stderr) may also exist, numbered 2. "A stream is a full-duplex connection between a user's process and a device or pseudo-device" according to Ritchie [2]. "A user's write and I/O control requests are turned into messages sent to the stream, and read requests take data from the stream and pass it to the user" [2]. Normally the stdin stream is connected to the User's keyboard and the stdout stream is connected to the User's display. However, Unix shells universally support redirection operations [1]. These operations connect standard input and output streams to files.

#### Examples
- ls > Output.txt
Sends the output of the command ls (list directory conents) to the file Output.txt. If Output.txt does not already exist the file will be created.

- cd < Input.txt
Causes the command cd (change directory) to take its input from the from the file Input.txt

- ls >> Output.txt
Appends the output of the command ls to the file Output.txt. If Output.txt does not already exist the file will be created.

## Batchfiles
***myshell*** can take command line input from a file. The file is assumed to contain a set of command lines for the shell to process.

#### Example
- ./myshell foo.txt
Displays the command output/s for the contents of foo.txt.

## Enviroment Strings
Enviroment strings are part of the environment in which a process runs. Thus, they are accessible
only when the environment is active. ***myshell*** features the enviroment strings SHELL and PARENT. SHELL is "undefined by default" [5]. Both these variables are the full path for the shell executable. The enviroment strings can be displayed using the *environ* command in ***myshell***. See [5] for a list of UNIX shell enviroment strings.

## Signal Handling
If the User wants to exit ***myshell*** using ^C (Ctrl + C) the signal is caught by a function which will ask the User to press ENTER to confirm.

## Error Handling
If an error occurs when ***myshell*** is forking or execing, the error signal is caught by a function which will notify the User and display the error message.

## Citations

- [1] E. S. Raymond, "Multiprogramming: Separating Processes to Seperate Function," in *The Art of UNIX Programming*, Addison-Wesley Professional, 2003, ch. 7, sec. 7.2.1, p. 162. [Online]. Available: https://books.google.ie/books?hl=en&lr=&id=H4q1t-jAcBIC&oi=fnd&pg=PR9&ots=-g2zGtwg9t&sig=Q_wECDW4lh7idZB5uaEnXSifSZA&redir_esc=y#v=onepage&q&f=false

- [2] D. M. Ritchie, "Streams," in *The UNIX system: A stream input-output system*, Nokia Bell Labs, 1984, sec. 2.1, p. 2. [Online]. Available: https://ieeexplore-ieee-org.dcu.idm.oclc.org/document/6771925

- [3]  K. A. Robbins & S. Robbins, "Processes in UNIX," in *Unix™ Systems Programming: Communication, Concurrency, and Threads*, Pearson, 2003, ch. 3. sec 3. [Online]. Available: https://learning-oreilly-com.dcu.idm.oclc.org/library/view/unix-systems-programming/0130424110/ch03.html#ch03lev1sec3

- [4] W. W. Gay, "Overview of the UNIX Fork Process," in *Advanced Unix Programming*, Sams, 2000, ch. 19, sec. 1. [Online]. Available: https://learning-oreilly-com.dcu.idm.oclc.org/library/view/advanced-unix-programming/067231990X/067231990X_ch19lev1sec1.html

- [5] A. Robbins, "Environment Variables," in *Unix in a Nutshell, 4th Edition*, O'Reilly Media, 2005, ch. 5, sec. 4.6. [Online] Available: https://learning-oreilly-com.dcu.idm.oclc.org/library/view/unix-in-a/0596100299/ch05s04s06.html