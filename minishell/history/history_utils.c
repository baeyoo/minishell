/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:37:09 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/15 15:52:34 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	append_empty(t_history *history)
{
	t_str2	*str2;
	t_clist	*new;

	str2 = ft_calloc(1, sizeof(t_str2));
	str2->s1 = ft_strdup("");
	str2->s2 = ft_strdup("");
	new = ft_clstnew(str2);
	ft_clstadd_front(&history->history, new);
	history->count_new++;
	return (1);
}

static int	append_util(t_history *history, t_str2 *str2, t_str2 *line)
{
	if (history->history->pre->last)
	{
		str2 = get_str2(history->history);
		free(str2->s1);
		str2->s1 = ft_strdup(line->s2);
		return (0);
	}
	return (1);
}

int	append_history(t_history *history)
{
	t_str2	*str2;
	t_str2	*line;

	str2 = NULL;
	line = NULL;
	line = get_str2(history->history);
	if (append_util(history, str2, line))
	{
		history->history = ft_clstlast(history->history)->next;
		str2 = get_str2(history->history);
		free(str2->s1);
		free(str2->s2);
		str2->s1 = ft_strdup(line->s2);
		str2->s2 = ft_strdup(line->s2);
		if (ft_strncmp(line->s1, line->s2, \
			ft_strlen(line->s1) + ft_strlen(line->s2) + 1))
		{
			free(line->s2);
			line->s2 = ft_strdup(line->s1);
		}
	}
	return (append_empty(history));
}

char	*get_history(int dir, t_history *history)
{
	if (dir == PREC && !history->history->last)
		history->history = history->history->next;
	else if (dir == NEXT && !history->history->pre->last)
		history->history = history->history->pre;
	return (get_str2(history->history)->s2);
}

void	close_history(t_history *history)
{
	int	i;

	i = history->count_new;
	history->history = ft_clstlast(history->history)->next->next;
	while (history->history && i > 1)
	{
		history->history = history->history->next;
		i--;
	}
	while (history->history && history->count_new > 0)
	{
		ft_putstr_fd(get_str2(history->history)->s2, history->fd);
		ft_putstr_fd("\n", history->fd);
		history->count_new--;
		history->history = history->history->pre;
	}
	close(history->fd);
	ft_clstclear(&history->history, free_str2);
}
