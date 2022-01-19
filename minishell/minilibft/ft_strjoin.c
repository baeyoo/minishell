/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:58 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/12 15:20:20 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len[2];
	char	*str;

	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	i = 0;
	str = (char *)malloc(len[0] + len[1] + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len[0] + len[1])
	{
		if (i < len[0])
			str[i] = s1[i];
		else
			str[i] = s2[i - len[0]];
		i++;
	}
	str[i] = '\0';
	return (str);
}
