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

## Exit Values

If everything goes perfect, the function returns "EXIT_SUCCESS", if something goes south it returns 0.

## Bugs

Currently we haven't found any bugs, if you find one please notify us

## Authors

The authors of this proyect are @Mvigil6343 and @DiegoPla1104.
