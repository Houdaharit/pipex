/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:40:09 by hharit            #+#    #+#             */
/*   Updated: 2022/02/03 02:34:41 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack && needle)
	{
		if (!ft_strlen(needle))
			return (haystack);
		while (haystack[i])
		{
			if (haystack[i] == needle[0])
			{
				j = 0;
				while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
					j++;
				if (!needle[j])
					return (&haystack[len]);
			}
			i++;
		}
	}
	return (NULL);
}
