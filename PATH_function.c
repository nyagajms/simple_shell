#include "mjsh_main.h"

/**
 * findCommandInPath - search for and execute
 * a command in the system's PATH.
 * @trimmed_text: This function checks whether the given
 * 'command_line' represents an absolute or relative
 * checkCommandInPath - path to an executable file.
 * If not, it searches for the command
 * @envp: in the listed directories in the PATH environment variables.
 * If a matching executable is found, it is executed as a child process.
 */

void checkCommandInPath(char *trimmed_text, char *envp[])
{
	pid_t child_pid;

	char *args[10];
	int arg_count;

	char *command_name;
	char *command_path;
	int i;

	tokenizeInput(trimmed_text, args, &arg_count);

	if (arg_count == 0)
	{
		fprintf(stderr, "Error: Empty command.\n");
		return;
	}

	for (i = 0; i < arg_count; i++)
	{
		if (args[i][0] == '/')
		{
			break;
		}
	}

	if (i < arg_count)
	{
		char *directory_path = args[i];
		struct stat st;

		if (stat(directory_path, &st) == 0 && S_ISDIR(st.st_mode))
		{
			args[arg_count] = NULL;
			chdir(directory_path);
		}
		else
		{
			fprintf(stderr, "Error: Not a directory: %s\n", directory_path);
			return;
		}
	}

	command_name = args[0];
	command_path = findCommandInPath(command_name);

	if (command_path != NULL)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Child process failed to be created");
			exit(1);
		}

		if (child_pid == 0)
		{
			if (execve(command_path, args, envp) == -1)
			{
				perror("execve");
				exit(1);
			}

			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		fprintf(stderr, "Command not found: %s\n", command_name);
	}
}
char *findCommandInPath(char *command_name)
{
	char *path = getenv("PATH");
	char *dir;
	char path_copy[1024];
	static char full_path[1024];

	if (path == NULL)
	{
		return (NULL);
	}

	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command_name);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	return (NULL);
}
