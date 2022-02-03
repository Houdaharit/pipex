/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:43:38 by hharit            #+#    #+#             */
/*   Updated: 2022/02/03 02:41:46 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*path_exc1;
	char	*path_exc2;
	char	**argv1;
	char	**argv2;
	char	*cmd1;
	char	*cmd2;
	int		fd1;
	int		fd2;
	int		p[2];
	int		pid;
}	t_pipex;

char	**ft_split(char *str, char sep);
char	*get_path_envp(char **envp);
int		ft_strlen(char *str);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*get_path(char *path, char *argv);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_file(char *file);
char	*get_cmd_path(char *path, char *cmd);
void	get_cmd1(t_pipex *pr, char *argv);
void	get_cmd2(t_pipex *pr, char *argv);
void	ft_init(t_pipex *pr, char **path, char **argv, char **envp);
void	free_2d(char **ptr);
void	parent_p(t_pipex *pr, char *path, char **argv, char **envp);
void	child_p(t_pipex *pr, char *path, char **argv, char **envp);
#endif
