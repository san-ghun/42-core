/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:28:06 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/15 13:18:09 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
static void	print_envp(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_printf("envp %d = %s\n", i, envp[i]);
		i++;
	}
}
*/

int	open_file(char *argv, int option)
{
	int	file;

	file = 0;
	if (option == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (option == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (option == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error();
	return (file);
}

/* mandatory part */
/*
/// @brief child process that run inside a fork, take the filein, put the output
/// inside a pipe and close with the exec function
/// @param argv argument vector from the command line
/// @param envp pointer to the environment variables
/// @param fd file descriptor
void	child_process(char *argv[], char *envp[], int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	ft_exec(argv[2], envp);
}

/// @brief parent process that take the data from the pipe, change the output 
/// for the fileout and close with the exec function
/// @param argv argument vector from the command line
/// @param envp pointer to the environment variables
/// @param fd file descriptor
void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	ft_exec(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: invalid arguments\n", 2);
		ft_putstr_fd("eg: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
*/

// ----------------------------------------------------------------

/* bonus part */
// /*
void	waiting_child(int fd[2], int pid)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	if (pid == 0)
		wait(NULL);
	else
		waitpid(pid, NULL, 0);
}

void	child_process(char *argv, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(argv, envp);
	}
	else
		waiting_child(fd, pid);
}

void	heredoc(char *limiter, int argc)
{
	int		fd[2];
	char	*line;
	pid_t	reader;

	if (argc < 6)
		instruction();
	if (pipe(fd) == -1)
		ft_error();
	line = "";
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
		waiting_child(fd, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			fileout = open_file(argv[argc - 1], 0);
			heredoc(argv[2], argc);
			i = 3;
		}
		else
		{
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
			i = 2;
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		ft_exec(argv[argc - 2], envp);
	}
	instruction();
}
// */
