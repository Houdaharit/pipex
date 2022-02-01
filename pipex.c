/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:41:18 by hharit            #+#    #+#             */
/*   Updated: 2022/02/01 20:58:07 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_initialize(int **p, char  **path, int *fd1, int *fd2, char **argv, char **envp)
{
	*fd1 = open(argv[1], O_RDONLY);
	*fd2 = open(argv[4], O_CREAT | O_WRONLY, 07666);
	*path = get_path_envp(envp);
	*p = (int *)malloc(sizeof(int) * 2);

}

void	parent_p(int p0, int p1, int fd1, char *path, char *argv2, char **envp)
{
	char	*p;

	close(p0);
	dup2(fd1, 0);
	dup2(p1, 1);
	wait(NULL);
	p = get_path(path, argv2);
	cmd_execve(p, argv2, envp);
}

void	child_p(int p0, int p1, int fd1, int fd2, char *path, char *argv3, char **envp)
{
	char	*p;

	close(p1);
	close(fd1);
	dup2(p0, 0);
	dup2(fd2, 1);
	p = get_path(path, argv3);
	cmd_execve(p, argv3, envp);
}

int main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	*p;
	char	*path;
	int pid;

	if (argc != 5 || !check_file(argv[1]))
		exit(EXIT_FAILURE);
	pid = fork();
	fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[4], O_CREAT | O_WRONLY, 07666);
    path = get_path_envp(envp);
    p = (int *)malloc(sizeof(int) * 2);
	pipe(p);
	if (pid == 0)
	{
		close(p[1]);
		close(fd1);
		dup2(p[0], 0);
		dup2(fd2, 1);
		cmd_execve(get_path(path, argv[3]), argv[3],envp);
	}
	else
	{
		close(p[0]);
		dup2(fd1, 0);
		dup2(p[1], 1);
		wait(NULL);
		cmd_execve(get_path(path, argv[2]), argv[2], envp);
	}
}
