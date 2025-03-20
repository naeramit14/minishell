#include "minishell.h"

int	run_cmd2(int f, char *env[])
{
	int	code;
	int	pid;
	char *cmd[] = {"sleep", "1", NULL};

	code = 0;
	if (f == 0)
	{
		code = 42;
		return(code);
	}
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/sleep", cmd , env);
		exit(1);
	}
	wait(&code);
	return(code >> 8);
}

int	run_cmd1(int f, char *env[])
{
	int	code;
	int	pid;
	char *cmd[] = {"sleep-","5" , NULL};

	code = 0;
	if (f == 0)
	{
		code = 42;
		return(code);
	}
	pid = fork();
	if (pid == 0)
	{
		execve("/bin/sleep-", cmd, env);
		exit(1);
	}
	wait(&code);
	return(code >> 8);
}

int	main(int argc, char *argv[], char *env[])
{
	int		code;
	int		temp;
	int		pid;
	int		pid1;
	int		pid2;
	int		i;

	code = 0;
	pid1 = fork();
	if (pid1 == 0)
	{
		code = run_cmd1(1, env);
		printf("fork1: %d\n", code);
		exit(code);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		code = run_cmd2(1, env);
		printf("fork2: %d\n", code);
		exit(code);
	}
	if (wait(&temp) == pid2)
		code = temp;
	if (wait(&temp) == pid2)
		code = temp;
	printf("%d\n", code >> 8);
	return (code >> 8);
}