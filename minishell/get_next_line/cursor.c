/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:01:57 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/14 18:25:40 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cursorforward(t_term *term)
{
	if ((term->cursor < (int)ft_strlen(term->input)))
	{
		write(1, "\033[1C", 4);
		term->cursor++;
	}
	return (1);
}

int	cursorbackward(t_term *term)
{
	if ((term->cursor > 0))
	{
		write(1, "\033[1D", 4);
		term->cursor--;
	}
	return (1);
}

void	cursorto(int pos, t_term *term)
{
	int	step;
	int	sign;

	sign = 1;
	step = pos - term->cursor;
	if (step < 0)
		sign = -1;
	while (step)
	{
		if (sign == -1)
			cursorbackward(term);
		else
			cursorforward(term);
		step -= sign;
	}
}
