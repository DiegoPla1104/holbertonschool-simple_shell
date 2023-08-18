# Simple Shell
***
This is a colaboration project of a Simple Shell from Unix works in similar ways compared to the bash shell but in a simpler way. It replicates the basic functionalities of the simple shell (sh), here we will apply the knowledge that we have acquired during the learning of the programming language C from Holberton

## Synopsis
```C
./hsh
Type_Bit$h: (a shell comand)
```

Depending on the command passed into it, looks for it in the environment variable "$PATH" and then uses the function stat to check in which folder is the command located then it gives said folder to execve and execve executes said command.a

## Flowchart

Flowchart to explain how we aprroched the proyect
![Screeshot](/docs/images/Flowchart_Simple_Shell.png)

## Compilation

The way of compiling this file and executing it is like this:
```C
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
```

## How it works

After the file it's initialized it puts out the prompt expecting a user input, after the user fishies typing and presses enter the file splits the input into smaller portions and puts them in a list, then uses said list to look for a command that matches the user input which has 2 outcomes: 1) The command the user wrote is executed to perfection or 2) The user input was not a command which the file would show an error message saying so. After that the prompt will show itself again and everything starts again.

## Exit Values

If everything goes perfect, the function returns "EXIT_SUCCESS", if something goes south it returns 0.

## Bugs

Currently we haven't found any bugs, if you find one please notify us

## Authors

The authors of this proyect are @Mvigil6343 and @DiegoPla1104.
