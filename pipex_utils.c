/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:41:18 by hharit            #+#    #+#             */
/*   Updated: 2022/02/01 23:23:29 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

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

int	check_file(char *file)
{
	if (!access(file, F_OK))
		return (1);
	else
		perror("ERROR!");
	return (0);
}

char	*get_cmd(char *path, char *cmd)
{
	char	**pth;
	int		i;
	char	*ret;

	i = 0;
	if (!*cmd)
		return (NULL);
	cmd = ft_strjoin("/", cmd);
	pth = ft_split(path, ':');
	while (pth[i])
	{
		ret = ft_strjoin(pth[i], cmd);
		if (!access(ret, X_OK))
		{
			free(cmd);
			free_2d(pth);
			return (ret);
		}
		i++;
		free(ret);
	}
	free(cmd);
	free(pth);
	return (NULL);
}

