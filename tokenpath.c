#include "shell.h"
/**
 * tokenpath - function that tokenizes the Path
 * @input: the full path
 * @delim: the delimiter to tokenize the Path
 * Return: an array of strings with all the tokenized Path
*/

char **tokenpath(char *input, char *delim)
{
	char **tokens = NULL, *tokensaver = NULL;
	int tcnt = 1;
	int iterator = 0, counter = 1;

	for (; input[iterator] != '\0'; iterator++)
	{
		if (input[iterator] == ':')
			if (input[iterator + 1] != ':')
				tcnt++;
	}
	tcnt++;
	tokens = malloc((sizeof(char *)) * tcnt);
	if (!tokens)
	{
		free(input);
		return (NULL);
	}
	tokensaver = strtok(input, delim);
	if (!tokensaver)
		return (NULL);
	tokens[0] = strdup(tokensaver);
	if (!tokens[0])
	{
		free(tokens);
		return (NULL);
	}
	for (counter = 1; counter <= tcnt; counter++)
	{
		tokensaver = NULL;
		tokensaver = strtok(NULL, delim);
		if (!tokensaver)
			break;
		tokens[counter] = strdup(tokensaver);
	}
	tokens[tcnt - 1] = NULL;
	free(input);
	return (tokens);
}
