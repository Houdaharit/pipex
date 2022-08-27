/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:07:23 by hharit            #+#    #+#             */
/*   Updated: 2022/02/05 23:07:24 by hharit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(0, str, 1);
		str++;
	}
}