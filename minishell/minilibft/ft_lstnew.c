/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:02:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/06/10 17:34:47 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_clist	*ft_clstnew(void *content)
{
	t_clist	*l;

	l = (t_clist *)malloc(sizeof(t_clist));
	if (!l)
		return (0);
	l->content = content;
	l->next = l;
	l->pre = l;
	l->last = 1;
	return (l);
}
