/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:23:22 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/14 18:25:50 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	composer(char *buff, t_term *term)
{
	char	**cut;
	char	*temp;
	int		ex_pos;

	cut = ft_strcut(term->input, term->cursor);
	ex_pos = term->cursor + 1;
	cursorto(0, term);
	term->input[0] = 0;
	temp = term->input;
	term->input = ft_strjoin(temp, cut[0]);
	free(temp);
	temp = term->input;
	term->input = ft_strjoin(temp, buff);
	free(temp);
	temp = term->input;
	term->input = ft_strjoin(temp, cut[1]);
	free(temp);
	free_table(cut);
	write(1, term->input, ft_strlen(term->input));
	history_change(&term->history, ft_strjoin("", term->input));
	term->cursor = ft_strlen(term->input);
	cursorto(ex_pos, term);
}

//ESC[0K
int	delete(t_term *term)
{
	char	**cut;
	int		ex_pos;

	if (!term->cursor)
		return (0);
	cut = ft_strcut(term->input, term->cursor);
	ex_pos = term->cursor - 1;
	cut[0][strlen(cut[0]) - 1] = 0;
	cursorto(0, term);
	write(1, "\033[0K", 4);
	free(term->input);
	term->input = ft_strjoin(cut[0], cut[1]);
	history_change(&term->history, ft_strjoin("", term->input));
	free_table(cut);
	write(1, term->input, ft_strlen(term->input));
	term->cursor = ft_strlen(term->input);
	cursorto(ex_pos, term);
	return (0);
}

int	echo_input(char *buff, t_term *term)
{
	char	*temp;

	if (term->cursor < (int)ft_strlen(term->input))
		composer(buff, term);
	else
	{
		term->cursor++;
		temp = term->input;
		term->input = ft_strjoin(temp, buff);
		history_change(&term->history, ft_strdup(term->input));
		free(temp);
		write(1, buff, ft_strlen(buff));
	}
	return (2);
}

void	move_history(t_term *term, int dir)
{
	free(term->input);
	term->input = ft_strjoin("", get_history(dir, &term->history));
	cursorto(0, term);
	write(1, "\033[0K", 4);
	ft_putstr_fd(term->input, 1);
	term->cursor = ft_strlen(term->input);
}
