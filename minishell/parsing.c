/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:02:58 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/28 13:18:48 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	new_node(t_term *term, int *iter, t_op **new)
{
	(*new)->fd[WRITE] = WRITE;
	(*new)->oldfd[WRITE] = WRITE;
	(*new)->fd[READ] = READ;
	(*new)->oldfd[READ] = READ;
	if (term->input[*iter] == '|')
	{
		(*new)->pipe = 1;
		ft_clstadd_back(&(term->queque.first), ft_clstnew(*new));
		(*iter)++;
		ft_skip(term->input, iter, ' ');
		*new = ft_calloc(1, sizeof(t_op));
	}
	else if (!term->input[*iter])
		ft_clstadd_back(&(term->queque.first), ft_clstnew(*new));
}

static void	parse_cmd(t_term *term)
{
	int		iter;
	t_op	*new;

	iter = 0;
	while (term->input[iter] == ' ')
		iter++;
	new = ft_calloc(1, sizeof(t_op));
	while (term->input[iter])
	{
		if (!new->cmd || !(new->cmd)[0])
			find_cmd(term, &iter, &new);
		find_cmd_input(term, &iter, &new);
		while (term->input[iter] && term->input[iter] != '|' \
		 && term->input[iter] != ' ')
			find_red(term, &iter, &new);
		if (!term->input[iter] || term->input[iter] == '|')
			new_node(term, &iter, &new);
	}
}

int	ft_parsing_hub(t_term *term)
{
	int		ex;
	t_clist	*cmds;

	ex = 0;
	term->queque.first = 0;
	if (term->input[0])
	{
		parse_cmd(term);
		cmds = term->queque.first;
		write(1, "\n", 1);
		printf("\033[0m\033[0;37m");
		while (!ex && cmds)
		{
			exec_manager(cmds, term);
			ex = cmds->last;
			cmds = cmds->next;
		}
		ft_clstclear(&term->queque.first, free_op);
		free(term->input);
	}
	else
		ft_putstr_fd("\n", 1);
	return (1);
}
