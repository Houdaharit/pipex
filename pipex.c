/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:24:19 by hharit            #+#    #+#             */
/*   Updated: 2022/02/05 23:11:12 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(char *file)
{
	if (!access(file, F_OK))
		return (1);
	else
		perror(file);
	return (0);
}

void	ft_init(t_pipex *pr, char **path, char **argv, char **envp)
{
	pr->fd1 = open(argv[1], O_RDONLY);
	pr->fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 07666);
	*path = get_path_envp(envp);
}

void	parent_p(t_pipex *pr, char *path, char **argv, char **envp)
{
	get_cmd2(pr, argv[3]);
	pr->path_exc2 = get_cmd_path(path, pr->cmd2);
	if (!pr->path_exc2)
	{
		ft_putstr(pr->cmd2);
		ft_putstr(": command not found!");
		exit(1);
	}
	close(pr->p[1]);
	dup2(pr->p[0], 0);
	dup2(pr->fd2, 1);
	wait(NULL);
	if (execve(pr->path_exc2, pr->argv2, envp) == -1)
		perror("ERROR!");
}

void	child_p(t_pipex *pr, char *path, char **argv, char **envp)
{
	get_cmd1(pr, argv[2]);
	pr->path_exc1 = get_cmd_path(path, pr->cmd1);
	if (!pr->path_exc1)
	{
		ft_putstr(pr->cmd1);
		ft_putstr(": command not found!");
		exit(1);
	}
	close(pr->p[0]);
	dup2(pr->fd1, 0);
	dup2(pr->p[1], 1);
	if (execve(pr->path_exc1, pr->argv1, envp) == -1)
		perror("ERROR!");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pr;
	char	*path;

	if (argc != 5 || !check_file(argv[1]))
		exit(EXIT_FAILURE);
	ft_init(&pr, &path, argv, envp);
	pipe(pr.p);
	pr.pid = fork();
	if (pr.pid == -1)
		perror("ERROR");
	if (pr.pid == 0)
		child_p(&pr, path, argv, envp);
	else
		parent_p(&pr, path, argv, envp);
}
