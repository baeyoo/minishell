/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:25:56 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/14 18:25:46 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	switch_special(char *buff, t_term *term)
{
	if (!ft_strncmp(SS_UP, buff, 7))
		move_history(term, PREC);
	else if (!ft_strncmp(SS_LEFT, buff, 7))
		cursorbackward(term);
	else if (!ft_strncmp(SS_RIGHT, buff, 7))
		cursorforward(term);
	else if (!ft_strncmp(SS_DOWN, buff, 7))
		move_history(term, NEXT);
	else if (!ft_strncmp(SHIFT_SS_LEFT, buff, 7))
		return (echo_input(";2D", term));
	else if (!ft_strncmp(SHIFT_SS_RIGHT, buff, 7))
		return (echo_input(";2C", term));
	else if (buff[0] == SS_DEL && !buff[1])
		return (delete(term));
	else if (buff[0] == SS_TAB && !buff[1])
		return (0);
	else
		return (echo_input(buff, term));
	return (1);
}

static int	gnl_utils(t_term *term, char buff[7], int rd)
{
	term->cursor = 0;
	while (rd >= 0)
	{
		ft_bzero(buff, 7);
		tcsetattr(0, TCSANOW, &term->cconf);
		rd = read(0, buff, 6);
		tcsetattr(0, TCSANOW, &term->dconf);
		if (buff[0] == EOT && term->input[0])
			continue ;
		else if (buff[0] == EOT && !term->input[0])
		{
			ft_strlcpy(buff, "exit", 5);
			switch_special(buff, term);
			return (append_history(&term->history));
		}
		if (buff[0] == '\n' && term->input[0])
			return (append_history(&term->history));
		if (buff[0] == '\n' && !term->input[0])
			return (1);
		if (rd > 0)
			switch_special(buff, term);
	}
	return (rd);
}

int	get_next_line(int fd, t_term *term)
{
	char	buff[7];

	if (fd < 0)
		return (-1);
	term->input = ft_calloc(1, 1);
	if (!(term->input))
		return (-1);
	return (gnl_utils(term, buff, 1));
}

int	get_next_line_basic(int fd, char **line)
{
	char	buff[2];
	char	*temp;
	int		rd;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_calloc(1, 1);
	if (!(*line))
		return (-1);
	buff[0] = 0;
	buff[1] = 0;
	rd = read(fd, buff, 1) > 0;
	while (rd)
	{
		if (buff[0] == '\n')
			return (1);
		if (rd == -1)
			return (-1);
		temp = *line;
		*line = ft_strjoin(temp, buff);
		free(temp);
		rd = read(fd, buff, 1) > 0;
	}
	return (0);
}
