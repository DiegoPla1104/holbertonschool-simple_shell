#include "shell.h"
/**
 * tokeninput - function that splits a string in tokens
 * @input: the string to split
 * @delim: the parameter to use to split the string
 * Return: an array of pointers with all the fragments if the string or NULL
*/
char **tokeninput(char *input, char *delim)
{
	char **tokens = NULL, *tokensaver = NULL;
	int i = 0, cnt = 1;
	int tcnt = input[0] == ' ' || input[0] == '\n' || input[0] == '\t' ? 0 : 1;

	for (; input[i] != '\0'; i++)
	{
		if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
			if (input[i + 1] != ' ' && input[i + 1] != '\t' &&
			input[i + 1] != '\n')
				tcnt++;
	}
	tokens = malloc((sizeof(char *)) * tcnt);
	if (!tokens)
	{
		free(input);
		return (NULL);
	}
	tokensaver = strtok(input, delim);
	if (!tokensaver)
	{
		free(tokens);
		return (NULL);
	}
	tokens[0] = strdup(tokensaver);
	if (!tokens[0])
	{
		free(tokens);
		free(input);
		return (NULL);
	}
	for (cnt = 1; cnt <= tcnt; cnt++)
	{
		tokensaver = NULL;
		tokensaver = strtok(NULL, delim);
		if (!tokensaver)
			break;
		tokens[cnt] = strdup(tokensaver);
	}
	tokens[tcnt - 1] = NULL;
	return (tokens);
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

	char *ifoundit = NULL, *envivar = NULL;
	int i = 0;

	for (; environ[i]; i++)
	{
		if (strncmp(environ[i], str, strlen(str)) == 0)
		{
			ifoundit = strdup(environ[i]); /*LEAK*/
			if (!ifoundit)
				return (NULL);
			envivar = strtok(ifoundit, "=\n");
			envivar = strtok(NULL, "=\n");
			return (envivar);
		}
	}
	return (NULL);
}
/**
 *executioner - Execd holcutes a comand.
 *@path: The array with allcd hol routes.
 *@arr: An array with the command as the first string.
 *
 *Return: 0 if success, -1 if fail.
 */
int executioner(char **path, char **arr)
{
	pid_t pid;
	struct stat full;
	int f = 1, n = 0;
	char *valid_path = NULL;

	f = stat(arr[0], &full);
	if (f == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(arr[0], arr, NULL);
		else
			wait(NULL);
		return (0);
	}
	for (; path[n] != NULL; n++)
	{
		valid_path = malloc(strlen(path[n]) + strlen(arr[0]) + 2); /*LEAK*/
		if (!valid_path)
		{
			return (-1);
		}
		else
		{
			valid_path = strcpy(valid_path, path[n]);
			valid_path = strcat(valid_path, "/");
			valid_path = strcat(valid_path, arr[0]);
			f = stat(valid_path, &full);
			if (f == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					execve(valid_path, arr, NULL);
					free(valid_path);
				}
				else
					wait(NULL);
				return (0);
			}
			free(valid_path);
		}
	}
	if (path[n] == NULL && f != 0)
		printf("bash: %s: command not found\n", arr[0]);
	return (-1);
}
/**
 * main - function that emulates a simple shell
 * Return: EXIT_SUCCESS
*/
int main(void)
{
	int prompt = isatty(STDIN_FILENO);
	char *input = NULL, *pathenv = NULL, *pathdelim = ":", *inputdelim = " \t\n";
	char **arr = NULL, **path = NULL;
	size_t n = 0;
	ssize_t ret = 0;

	while (-2147483648)
	{
		if (prompt == 1)
			printf("Type_Bit$h: ");
		ret = getline(&input, &n, stdin);
		if (ret == EOF)
		{
			free(input);
			break;
		}
		arr = tokeninput(input, inputdelim);
		if (!arr)
		{
			continue;
		}
		if (strcmp(arr[0], "exit") == 0)
		{
			free(input);
			free_grid(arr);
			return (0);
		}
		pathenv = _getenv("PATH");
		path = tokenpath(pathenv, pathdelim);
		executioner(path, arr);
		free_grid(arr);
		free_grid(path);
	}
	return (EXIT_SUCCESS);
}
