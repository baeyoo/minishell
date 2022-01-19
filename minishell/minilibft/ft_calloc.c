/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:06:01 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/24 17:06:15 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*array;

	array = (void *)malloc(count * size);
	if (!array)
		return (0);
	ft_bzero(array, size * count);
	return (array);
}
