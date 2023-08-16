# Simple Shell
***
This simple shell works in similar ways compared to the bash shell but in a simpler  way.

## Synopsis
```C
./hsh
Type_Bit$h: (a shell comand)
```

Depending on the command passed into it, looks for it in the environment variable "$PATH" and then uses the function stat to check in which folder is the command located then it gives said folder to execve and execve executes said command.a

## Tested Commands

| Command | Description|
|:---------:|:----------:|   
|ls          |Lists all the files on the current directory(to list other directories you must specify)             |
|pwd         |Prints the path to the current directory                    |
|clear       |Clears the Terminal|

## Exit Values

If everything goes perfect, the function returns "EXIT_SUCCESS", if something goes south it returns 0.

## Bugs

Currently it has a memory leak, and if you free the malloc it gives segmentation fault.

## Authors

The authors of this proyect are @Mvigil6343 and @DiegoPla1104.