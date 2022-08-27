/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:42:30 by hharit            #+#    #+#             */
/*   Updated: 2022/02/03 02:35:32 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	nbrwd(char *str, char sep)
{
	int	nbr;

	nbr = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str)
			nbr++;
		while (*str && *str != sep)
			str++;
	}
	return (nbr);
}

static char	*ft_word(char *str, char sep)
{
	char	*word;
	int		len;

	len = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != sep)
		len++;
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != sep)
	{
		word[len] = str[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (nbrwd(str, sep) + 1));
	if (!tab)
		return (NULL);
	if (str)
	{
		while (*str)
		{
			while (*str && *str == sep)
				str++;
			if (*str)
				tab[i++] = ft_word(str, sep);
			while (*str && *str != sep)
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
