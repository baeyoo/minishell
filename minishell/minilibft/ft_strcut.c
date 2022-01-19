/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:03:41 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/28 16:06:48 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_strcut(char *s, int pos)
{
	char	**new;
	int		size1;

	new = ft_calloc(3, sizeof(char *));
	size1 = ft_strlen(s) - pos + 1;
	new[1] = ft_calloc(size1, 1);
	new[0] = ft_calloc(pos + 1, 1);
	ft_strlcpy(new[1], &s[pos], size1);
	ft_strlcpy(new[0], s, pos + 1);
	return (new);
}
