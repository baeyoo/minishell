/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:40:42 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:51 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clstdelone(t_clist *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->content);
		lst->next->pre = lst->pre;
		lst->pre->next = lst->next;
		if (lst->last)
			lst->pre->last = 1;
		free(lst);
	}
}

t_clist	*ft_clst_export(t_clist *lst)
{
	if (lst)
	{
		lst->next->pre = lst->pre;
		lst->pre->next = lst->next;
		if (lst->last)
			lst->pre->last = 1;
	}
	lst->next = lst;
	lst->pre = lst;
	return (lst);
}
