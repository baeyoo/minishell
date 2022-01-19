/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:57:36 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/15 16:12:45 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_history(t_clist *cls)
{
	int	ex;

	ex = 1;
	printf("\n");
	while (ex)
	{
		printf("ACTUAL %p L:%d   %p [%10s,%10s] %p   %p <--> %p\n", cls, \
			cls->last, ((t_str2 *)cls->content)->s1, \
			((t_str2 *)cls->content)->s1, ((t_str2 *)cls->content)->s2, \
			((t_str2 *)cls->content)->s2, cls->pre, cls->next);
		ex = !cls->last;
		cls = cls->next;
	}
}

t_str2	*get_str2(t_clist *cls)
{
	return ((t_str2 *)cls->content);
}

void	free_str2(void *content)
{
	t_str2	*str2;

	str2 = (t_str2 *)content;
	if (str2->s1)
	{
		free(str2->s1);
		str2->s1 = 0;
	}
	if (str2->s2)
	{
		free(str2->s2);
		str2->s2 = 0;
	}
	free(str2);
}

void	open_history(t_term *term)
{
	t_str2	*line;
	int		rd;

	line = ft_calloc(1, sizeof(t_str2));
	term->history.fd = open(HISTORY, O_RDWR | O_APPEND | O_CREAT, 0755);
	if (term->history.fd < 0)
		exit(1);
	rd = get_next_line_basic(term->history.fd, &line->s1);
	line->s2 = ft_strdup(line->s1);
	term->history.history = 0;
	if (rd > 0 && line->s1)
		ft_clstadd_front(&term->history.history, ft_clstnew(line));
	while (rd > 0)
	{
		line = ft_calloc(1, sizeof(t_str2));
		rd = get_next_line_basic(term->history.fd, &line->s1);
		line->s2 = ft_strdup(line->s1);
		if (rd)
			ft_clstadd_front(&term->history.history, ft_clstnew(line));
	}
	if (rd < 0)
		ft_clstclear(&term->history.history, free_str2);
	ft_clstadd_front(&term->history.history, ft_clstnew(line));
	term->history.count_new = 0;
}

void	history_change(t_history *history, char *line)
{
	t_str2	*str2;

	str2 = get_str2(history->history);
	free(str2->s2);
	if (line)
		str2->s2 = line;
	else
		str2->s2 = ft_strdup("");
}
