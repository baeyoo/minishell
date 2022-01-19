/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:58:43 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/17 18:42:21 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') \
		 || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_stralpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i++]))
			return (0);
	}
	return (1);
}

int	ft_stralnum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalnum(s[i++]))
			return (0);
	}
	return (1);
}
