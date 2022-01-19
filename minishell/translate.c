/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:33:21 by mobrycki          #+#    #+#             */
/*   Updated: 2021/07/28 11:58:55 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

char	*freejoin(char *s1, char *s2, int n)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	if (n == 1)
		free(s1);
	else if (n == 2)
		free(s2);
	else if (n)
	{
		free(s1);
		free(s2);
	}
	return (new);
}

int	if1(char **input, char **trans, int *iter)
{
	int	flag;
	int	quotes;
	int	i;

	i = 0;
	quotes = 0;
	flag = ((*input)[*iter] == 39);
	if (flag)
	{
		(*iter)++;
		while ((*input)[*iter + i] && !quotes)
			quotes = (quotes || ((*input)[*iter + i++] == '\''));
		if (quotes)
		{
			*trans = freejoin(*trans, ft_substr(*input, *iter, i - 1), 3);
			(*iter) = *iter + i;
		}
		else
			*trans = freejoin(*trans, "\'", 1);
	}
	return (flag);
}

static void	ifuck2(char **input, char **trans, int *iter, t_term *term)
{
	while ((*input)[*iter] && (*input)[*iter] != '\"')
	{
		if ((*input)[*iter] == '$')
			ft_dollar(input, term, trans, iter);
		else
			*trans = freejoin(*trans, ft_substr(*input, (*iter)++, 1), 3);
	}
	if ((*input)[*iter])
		(*iter)++;
}

void	if2(char **input, char **trans, int *iter, t_term *term)
{
	int	i;

	i = 0;
	if ((*input)[*iter] == '\"')
	{
		(*iter)++;
		while ((*input)[i + *iter] && (*input)[*iter + i] != '\"')
			i++;
		if ((*input)[*iter + i] == '\"')
			ifuck2(input, trans, iter, term);
		else
			*trans = freejoin(*trans, "\"", 1);
	}
	else if ((*input)[*iter] == '$')
		ft_dollar(input, term, trans, iter);
	else if ((*input)[*iter])
		*trans = freejoin(*trans, ft_substr(*input, (*iter)++, 1), 3);
}

//look over the string for special char and translate them
char	*ft_translate(char *input, t_term *term)
{
	char	*trans;
	int		iter;	

	iter = 0;
	trans = ft_strdup("");
	while (input[iter])
	{
		if (input[iter] == ' ')
		{
			trans = freejoin(trans, " ", 1);
			ft_skip(input, &iter, ' ');
		}
		if (!if1(&input, &trans, &iter))
			if2(&input, &trans, &iter, term);
	}
	return (trans);
}
