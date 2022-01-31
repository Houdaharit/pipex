/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:41:18 by hharit            #+#    #+#             */
/*   Updated: 2022/01/31 21:18:50 by hharit           ###   ########.fr       */
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
	char	*cmd1;
	char	*ret;
	int		j;

	j = 0;
	if (cmd)
	{
		cmd1 = ft_strjoin("/", cmd);
		tab = ft_split(path, ':');
		while(tab[j])
		{
			ret = ft_strjoin(tab[j], cmd1);
			if (!access(ret, F_OK))
			{
				free(cmd1);
				free_2d(tab);
				return (ret);
			}
			free(ret);
			j++;
		}
		free(cmd1);
		free_2d(tab);
	}
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
		perror("Command can not be executed !");

}

char	*get_path(char *path, char *argv)
{
	char	**cmd;
	char	*p;

	cmd = ft_split(argv, 32);
	p = check_cmd(path, cmd[0]);
	free_2d(cmd);
	return (p);
}
