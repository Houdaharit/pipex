/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:39:30 by hharit            #+#    #+#             */
/*   Updated: 2022/02/03 02:34:53 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(char *str)
{
	char	*dup;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * len + 1);
	len = 0;
	while (str[len])
	{
		dup[len] = str[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	if (s2)
	{
		while (*s2)
		{
			str[len++] = *s2;
			s2++;
		}
	}
	str[len] = '\0';
	return (str);
}
