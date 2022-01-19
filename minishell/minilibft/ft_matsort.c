/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:03:16 by alexmarcell       #+#    #+#             */
/*   Updated: 2021/07/15 15:56:07 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_strzocmp(const char *s1, const char *s2)
{
	size_t	i;
	int		n;
	int		n2;

	n = ft_strchrid(s1, '=');
	n2 = ft_strchrid(s2, '=');
	if (n == -1)
		n = ft_strlen(s1);
	if (n2 == -1)
		n2 = ft_strlen(s2);
	if (n < n2)
		n = n2;
	i = 0;
	if (!n)
		return (0);
	while (i < (size_t)n - 1 && s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	ft_swap(char **tab, int i, int j)
{
	char	*c;

	c = tab[i];
	tab[i] = tab[j];
	tab[j] = c;
}

void	ft_sort_matrix(char **tab, int size)
{
	int	i;
	int	j;

	if (size <= 1)
		return ;
	ft_sort_matrix(tab, size - 1);
	i = size - 1;
	j = i - 1;
	while (j >= 0 && ft_strzocmp(tab[i], tab[j]) < 0)
	{
		ft_swap(tab, i, j);
		i--;
		j--;
	}
}
