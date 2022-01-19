/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:15:14 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/31 15:16:24 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	dimension(int n)
{
	int	dim;

	if (n == 0)
		return (0);
	dim = 0;
	while (n)
	{
		n = n / 10;
		dim++;
	}
	return (dim - 1);
}

static int	power(int n, int p)
{
	int	res;

	res = 1;
	while (p)
	{
		res *= n;
		p--;
	}
	return (res);
}

static int	converter(int dim, int i, long num, char *str)
{
	while (dim >= 10)
	{
		str[i] = '0' + (num / dim);
		num = num % dim;
		dim /= 10;
		i++;
	}
	str[i] = '0' + num;
	return (i + 1);
}

static char	*supp(int dim, int i, long num, char *str)
{
	dim = power(10, dim);
	i = converter(dim, i, num, str);
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int		dim;
	long	num;
	char	*str;
	int		i;

	i = 0;
	num = n;
	dim = dimension(n);
	if (num < 0 && num != 0)
	{
		str = (char *)malloc(sizeof(char) * (dim + 3));
		if (!str)
			return (0);
		str[i++] = '-';
		num *= -1;
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (dim + 2));
		if (!str)
			return (0);
	}
	return (supp(dim, i, num, str));
}
