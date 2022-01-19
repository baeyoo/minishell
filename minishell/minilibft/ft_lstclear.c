/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:15:45 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:52 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clstclear(t_clist **lst, void (*del)(void*))
{
	t_clist	*current;

	if (lst && del)
	{
		while (*lst)
		{
			if (!(*lst)->last)
				current = (*lst)->next;
			else
				current = 0;
			ft_clstdelone(*lst, del);
			*lst = current;
		}
	}
}
