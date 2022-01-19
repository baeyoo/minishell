/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:33:31 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/28 15:09:37 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "includes/my_main_functions.h"
#include <stdio.h>

int	count_row(char *input, int *iter)
{
	int	size;
	int	flag;

	size = 0;
	flag = 0;
	while (input[*iter] && (input[*iter] != ' ' || (flag % 2)))
	{
		flag += (input[*iter] == '\"' || input[*iter] == '\'');
		(*iter)++;
		size++;
	}
	return (size);
}

void	split_input(char *input, t_term *term, char ***split)
{
	int		iter;
	int		size;
	int		i;
	char	*tmp;
	int		iter2;

	iter = 0;
	i = 0;
	while (input[iter])
	{
		iter2 = iter;
		size = count_row(input, &iter);
		if (size)
		{
			tmp = ft_calloc(size + 1, 1);
			ft_strlcpy(tmp, &input[iter2], size + 1);
			(*split)[i] = ft_translate(tmp, term);
			i++;
			free(tmp);
		}
		ft_skip(input, &iter, ' ');
	}
	(*split)[i] = NULL;
}

char	**arg_matrix(char *input, t_term *term)
{
	char	**matrix;
	int		count;
	int		iter;

	count = 0;
	iter = 0;
	while (input[iter])
	{
		if (count_row(input, &iter))
			count++;
		while (input[iter] == ' ')
			iter++;
	}
	matrix = ft_calloc(count + 2, sizeof(char *));
	split_input(input, term, &matrix);
	return (matrix);
}
