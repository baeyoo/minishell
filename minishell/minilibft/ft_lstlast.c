/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:53:15 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:49 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_clist	*ft_clstlast(t_clist *lst)
{
	if (!lst)
		return (0);
	while (!lst->last)
		lst = lst->next;
	return (lst);
}
