/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:23:01 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:55 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clstadd_front(t_clist **lst, t_clist *new)
{
	if (lst)
	{
		if (lst[0])
		{
			new->next = lst[0];
			new->pre = lst[0]->pre;
			new->last = 0;
			lst[0]->pre = new;
			new->pre->next = new;
			lst[0] = new;
		}
		else
		{
			lst[0] = new;
			new->last = 1;
		}
	}
}
