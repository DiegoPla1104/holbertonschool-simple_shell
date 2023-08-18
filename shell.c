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
	{	free(input);
		return (NULL);
	}
	tokensaver = strtok(input, delim);
	if (!tokensaver)
	{	free(tokens);
		return (NULL);
	}
	tokens[0] = strdup(tokensaver);
	if (!tokens[0])
	{	free(tokens);
		free(input);
		return (NULL); }
	for (cnt = 1; cnt <= tcnt; cnt++)
	{	tokensaver = NULL;
		tokensaver = strtok(NULL, delim);
		if (!tokensaver)
			break;
		tokens[cnt] = strdup(tokensaver); }
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
			ifoundit = strdup(environ[i]);
			if (!ifoundit)
				return (NULL);
			envivar = strtok(ifoundit, "=\n");
			envivar = strdup(strtok(NULL, "=\n"));
			free(ifoundit);
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
	int n = 0;
	char *valid = NULL;

	if (stat(arr[0], &full) == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(arr[0], arr, environ);
		else if (pid == -1)
			perror("Fork failed"), exit(EXIT_FAILURE);
		else
			wait(NULL);
		return (0); }
	for (; path[n] != NULL; n++)
	{
		valid = malloc(strlen(path[n]) + strlen(arr[0]) + 2);
		if (!valid)
			return (-1);
		strcpy(valid, path[n]), strcat(valid, "/"), strcat(valid, arr[0]);
		if (stat(valid, &full) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(valid, arr, environ), free(valid), exit(0); }
			else
			{
				wait(NULL), free(valid); }
			return (0); }
		free(valid);
	}
	if (path[n] == NULL)
			fprintf(stderr, "bash: %s: command not found\n", arr[0]);
	return (-1);
}
		/**
		 * if (isatty(STDIN_FILENO) == 0)
			printf("%s\n", *arr);
		*/
/**
 * main - function that emulates a simple shell
 * Return: EXIT_SUCCESS
*/
int main(void)
{
	int prompt = isatty(STDIN_FILENO);
	char *input = NULL, *pathenv = NULL, *pathdelim = ":", *inputdelim = " \t\n";
	char **arr = NULL, **path = NULL, **envi = NULL;
	size_t n = 0;
	ssize_t ret = 0;

	while (-2147483648)
	{
		if (prompt == 1)
			printf("Type_Bit$h: ");
		fflush(stdin);
		ret = getline(&input, &n, stdin);
		if (ret == EOF)
		{
			free(input);
			break;
		}
		arr = tokeninput(input, inputdelim);
		if (!arr)
			continue;
		if (strcmp(arr[0], "exit") == 0)
		{
			free(input), free_grid(arr);
			return (0);
		}
		if (strcmp(arr[0], "env") == 0)
			for (envi = environ; *envi != NULL; envi++)
				printf("%s\n", *envi);
		pathenv = _getenv("PATH"), path = tokenpath(pathenv, pathdelim);
		executioner(path, arr), free_grid(arr), free_grid(path);
		if (prompt == 0 && ret == -1)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
