/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:43:38 by hharit            #+#    #+#             */
/*   Updated: 2022/01/31 19:08:54 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
#include <fcntl.h>

char	**ft_split(char *str, char sep);
char	*get_path_envp(char **envp);
int	ft_strlen(char *str);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*get_path(char *path, char *argv);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*check_cmd(char *path, char *cmd);
int	check_file(char *file);
void	cmd_execve(char *path, char *argv2, char **envp);
void	ft_initialize(int **p, char **path, int *fd1, int *fd2, char **argv, char **envp);
char	*get_path(char *path, char *argv);
void	free_2d(char **ptr);
#endif
