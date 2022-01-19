/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:49:37 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/16 16:44:23 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**mat_init(int dim, int h)
{
	void	**mat;

	mat = ft_calloc(1, dim * (h + 1));
	if (!mat)
		return (0);
	return (mat);
}

char	**table_dup(char **mat)
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
	new[i] = 0;
	return (new);
}
