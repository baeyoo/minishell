/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:46:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:34 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_clstsize(t_clist *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (!lst->last || !i)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
