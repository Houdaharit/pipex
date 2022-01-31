/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:41:18 by hharit            #+#    #+#             */
/*   Updated: 2022/01/31 13:50:25 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_envp(char	**envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	if (envp)
	{
		while (envp[i] && !path)
		{
			path = ft_strnstr(envp[i], "PATH=", 5);
			i++;
		}
	}
	return (path);
}

char	*check_cmd(char *path, char *cmd)
{
	char	**tab;

	if (cmd)
	{
		cmd = ft_strjoin("/", cmd);
		tab = ft_split(path, ':');
		while(*tab)
		{
			if (!access(ft_strjoin(*tab,cmd), F_OK))
				return (ft_strjoin(*tab, cmd));
			tab++;
		}
	}
	free(path);
	return (NULL);
}

int	check_file(char *file)
{
	if (!access(file, F_OK))
		return (1);
	else
		perror("ERROR!");
	return (0);
}

void	cmd_execve(char *path, char *argv2, char **envp)
{
	char	**argv;

	argv = ft_split(argv2, 32);
	if(execve(path, argv, envp) == -1)
	{
		perror("Command can not be executed !");
		free(argv);
		free(path);
	}
}

char	*get_path(char *path, char *argv)
{
	return (check_cmd(path, ft_split(argv, 32)[0]));
}
