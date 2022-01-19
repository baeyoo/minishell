#include "../includes/minishell.h"

int	included(int c, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

size_t	new_dim(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	size_t	dim;

	dim = ft_strlen((char *)s1);
	i = 0;
	y = 0;
	while (s1[i])
	{
		if (!included(s1[i], set))
			break ;
		i++;
	}
	while (dim > 0 && included(s1[dim - 1], set))
		dim--;
	if (dim < i)
		return (0);
	return (dim - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	y;
	size_t	dim;

	dim = new_dim(s1, set);
	str = (char *)malloc(sizeof(char) * (dim + 1));
	if (!str)
		return (0);
	i = 0;
	y = 0;
	while (s1[i])
	{
		if (!included(s1[i], set))
			break ;
		i++;
	}
	ft_strlcpy(str, &s1[i], dim + 1);
	dim = ft_strlen(str) - 1;
	while (dim > 0 && included(str[dim], set))
	{
		str[dim] = 0;
		dim--;
	}
	return (str);
}
