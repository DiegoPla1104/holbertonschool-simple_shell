# Simple Shell
***

## Description:

This is a colaboration project of a Simple Shell from Unix works in similar ways compared to the bash shell but in a simpler way. It replicates the basic functionalities of the simple shell (sh), here we will apply the knowledge that we have acquired during the learning of the programming language C from Holberton.

## Synopsis

```
./hsh
Type_Bit$h: (a shell comand)
```

Depending on the command passed into it, looks for it in the environment variable "$PATH" and then uses the function stat to check in which folder is the command located then it gives said folder to execve and execve executes said command.

## Flowchart

Flowchart to explain how we aprroched the proyect.
![Screeshot](/docs/images/Flowchart_Simple_Shell.png)

## Installation / Compilation:

1. To use this command interpreter you need to download all the files in this repository or clone it.
```bash
https://github.com/DiegoPla1104/holbertonschool-simple_shell.git
```
2. The way of compiling this file and executing it in Linux unix sistem is like this:
```C
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
```
3. To execute the Shell:
```C
./hsh
```
4. Wait for the prompt `Type_Bit$h:`
5. Write the commands.

## How it works

After the file it's initialized it puts out the prompt expecting a user input, after the user fishies typing and presses enter the file splits the input into smaller portions and puts them in a list, then uses said list to look for a command that matches the user input which has 2 outcomes: 
1) The command the user wrote is executed to perfection or
2) The user input was not a command which the file would show an error message saying so. After that the prompt will show itself again and everything starts again.

## Functions

- `main` function: Consists of printing the prompt and getting the input of the user, aside from calling the other functions, it also takes into account if the first argument is exit in which case it exits the shell.
- `tokeninput` function: is the one that tokenizes the input in order to work with it, it splits the input by spaces, tabs or enter and returns an array of the tokenized input.
- `_getenv` function: takes a string, in this case PATH, and searches it in the variable of environment and returnes it.
- `free_grid` function: is used to save a considerable amount of lines so that Betty isn't annoyed, it takes an array and starts freeing all of its members and at the end it frees the array itself.
- `tokenpath` function: takes the return of the _getenv function and using almost the same code than the tokeninput function and splits the PATH using as delimitator : and returns it to the main function.
- `executioner` function takes the tokenized PATH and the tokenized input and concatenates the input to the PATH to check if that is a valid route to a command and if it is a valid route it executes said command and if it isn't it prints that the command was not found.

## Examples

Here is a example of the execution of the Shell:

```
Type_Bit$h: ls
AUTHORS README.md shell.c shell.h tokenpath.c
Type_Bit$h: echo "Hello World"
Hello World
Type_Bit$h: not a command
bash: 'not a command' command not found
```

## Exit Values

If everything goes perfect, the function returns "EXIT_SUCCESS", if something goes south it returns 0.

## Contributing:

Pull request are welcome. If you have any idea for improvement let us know!
You can open an issue and discuss it with us.

## Support:

For any issue, bug or assistance, you can find us on GitHub:
* [Marcos vigil](https://github.com/Mvigil6343/)
* [Diego Pla](https://github.com/DiegoPla1104)
