#include "shell.h"
/**
 * tokenizer - function that splits a string in tokens
 * @input: the string to split
 * @delim: the parameter to use to split the string
 * Return: an array of pointers with all the fragments if the string or NULL
*/
char **tokenizer(char *input, char *delim)
{
    char **tokens = NULL; 
	char *tokensaver = NULL;  
	int tcnt = input[0] == ' ' || input[0] == '\n' || input[0] == '\t' ? 0 : 1;
	int iterator = 0, counter = 1, l = 0;

	for (; input[iterator] != '\0'; iterator++)
	{
		if (input[iterator] == ' ' || input[iterator] ==
		'\t' || input[iterator] == '\n')
			if (input[iterator + 1] != ' ' && input[iterator + 1] != '\t' &&
			input[iterator + 1] != '\n')
				tcnt++;
	}
	tokens = malloc((sizeof(char *)) * tcnt);
	if (!tokens)
		return(NULL);
	tokensaver = strtok(input, delim);
	if (!tokensaver)
		return(NULL);
	tokens[0] = strdup(tokensaver);
	if (!tokens[0])
	{
		free(tokensaver);
		free(tokens);
		return(NULL);
	}
	for (; counter <= tcnt; counter++)
	{
			tokensaver = NULL;
			tokensaver = strtok(NULL, delim);
			if (!tokensaver)
				break;
			tokens[counter] = strdup(tokensaver);
	}
	tokens[tcnt - 1] = NULL;
	return(tokens);
}
/**
 * free_grid - free up 2 grid
 * @grid: Array of pointers.
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
/**
 * _getenv - function that looks for an environment variable from the environ
 * @str: the name of the variable to find
 * Return: the variable we are looking for or NULL
*/
char *_getenv(const char *str)
{

	char *ifoundit = NULL, *blah = NULL;
	int i = 0;
	
	for (; environ[i]; i++)
	{
		if (strncmp(environ[i], str, 4) == 0)
		{
			ifoundit = environ[i];
			blah = strtok(ifoundit, "=\n");
			blah = strtok(NULL, "=\n");
            return (blah);
        }
    }
    return(NULL);
}
/**
 * main - function that emulates a simple shell
*/
int main()
{
	char *prompt = "Type_Bit$h ";
	char *input = NULL, *pathenv = NULL, *pathdelim = NULL, *inputdelim = NULL;
	char **arr = NULL, **path = NULL;
	size_t n = 0;
	ssize_t ret = 0;

	while (-2147483648)
	{
		printf("%s", prompt);
		ret = getline(&input, &n, stdin);
		if (ret == EOF)
		{
			free(input);
			return (0);
		}
		inputdelim = " \t\n";
		arr = tokenizer(input, inputdelim);
		if (!arr)
			continue;
		if (strcmp(arr[0], "exit") == 0)
		{
			free(input);
			free_grid(arr);
			return (0);
		}
		pathdelim = ":";
		pathenv = _getenv("PATH");
		path = tokenizer(pathenv, pathdelim);
		free_grid(arr);
	}
	return (EXIT_SUCCESS);
}