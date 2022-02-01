/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:24:19 by hharit            #+#    #+#             */
/*   Updated: 2022/02/01 23:57:49 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(pipex *pr, char **path, char **argv, char **envp)
{
	pr->fd1 = open(argv[1], O_RDONLY);
	pr->fd2 = open(argv[4], O_CREAT | O_WRONLY, 07666);
	*path = get_path_envp(envp);
}

int	main(int argc, char **argv, char **envp)
{
	pipex	pr;
	char	*path;
	int		pid;
	int		p[2];
	char	*buf;

/*	if (argc != 5 || !check_file(argv[1]))
		exit(EXIT_FAILURE);*/
	//ft_init(&pr, &path, argv, envp);
	pipe(pr.p);
	pid = fork();
	if (pid > 0)
		write(pr.p[1], "hello", 5);
	else	
	{
		char buf[5];
		read(pr.p[0], buf, 5);
		printf("%s", buf);
	}
	
}
