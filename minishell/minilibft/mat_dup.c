/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:07:38 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/07/15 15:56:17 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**mat_dup(char **mat)
{
	int		i;
	char	**new;

	new = ft_calloc(mat_row((void **)mat) + 1, sizeof(char *));
	i = 0;
	while (mat[i])
	{
		new[i] = ft_strdup(mat[i]);
		i++;
	}
	return (new);
}
