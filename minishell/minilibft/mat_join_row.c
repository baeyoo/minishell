/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_join_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexmarcelli <alexmarcelli@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:34:32 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/19 02:02:23 by alexmarcell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	**mat_join_row(void **mat, void *row)
{
	int		i;
	void	**new;
	int		dim;

	i = 0;
	dim = mat_row(mat) + 1;
	new = ft_calloc(dim + 1, sizeof(void *));
	if (!new)
		return (0);
	while (i < dim - 1)
	{
		new[i] = (mat)[i];
		i++;
	}
	free(mat);
	new[i] = row;
	return (new);
}
