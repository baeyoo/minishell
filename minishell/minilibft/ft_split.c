/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:22:26 by dlanotte          #+#    #+#             */
/*   Updated: 2021/05/24 17:09:24 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**occurences(char const *s, char c, size_t *size)
{
	char	*pt;
	size_t	length;

	length = 0;
	*size = 1;
	pt = (char *)s;
	while (*pt)
	{
		if (*pt == c && length)
		{
			(*size)++;
			length = 0;
		}
		length += (*pt != c);
		pt++;
	}
	if (length)
		(*size)++;
	return ((char **) malloc((*size) * sizeof(char *)));
}

static	char	*ft_copy(const char *src, size_t length)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)malloc((length + 1) * sizeof(char));
	if (dst != NULL)
	{
		while (i < length)
		{
			dst[i] = src[i];
			i++;
		}
		dst[length] = '\0';
		return (dst);
	}
	return (NULL);
}

static	void	fill(char **array, char const *s, char c, size_t size)
{
	size_t	length;
	int		flag;
	int		i;
	char	*pt;

	i = 0;
	pt = (char *)s;
	flag = 1;
	length = 0;
	while (*pt)
	{
		if (*pt != c && flag)
			flag = 0;
		else if (*pt == c && !flag)
		{
			flag = 1;
			array[i] = ft_copy(pt - length, length);
			length = 0;
			i++;
		}
		length += (*pt != c);
		pt++;
	}
	if (length)
		array[size - 2] = ft_copy(pt - length, length);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	if (!s)
		return (NULL);
	array = occurences(s, c, &size);
	if (!array)
		return (NULL);
	fill(array, s, c, size);
	array[size - 1] = NULL;
	return (array);
}
