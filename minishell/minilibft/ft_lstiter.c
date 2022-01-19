/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:20:51 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:49 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clstiter(t_clist *lst, void (*f)(void *))
{
	int	finish;

	finish = 0;
	if (lst && f)
	{
		while (!finish)
		{
			(*f)(lst->content);
			finish = lst->last;
			lst = lst->next;
		}
	}
}
