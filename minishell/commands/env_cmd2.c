/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:33:17 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/26 16:25:51 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
static void	export_view_print(char *s, int fd[2])
{
	char	**spl;

	spl = ft_strcut(s, ft_strchrid(s, '=') + 1);
	ft_putstr_fd(spl[0], fd[WRITE]);
	ft_putstr_fd("\"", fd[WRITE]);
	ft_putstr_fd(spl[1], fd[WRITE]);
	ft_putstr_fd("\"", fd[WRITE]);
	free_table(spl);
}

int	export_view(int pid, char **environ, int fd[2])
{
	int		i;
	char	**tmp;

	tmp = mat_dup(environ);
	ft_sort_matrix(tmp, mat_row((void **)tmp));
	i = 0;
	while (tmp[i])
	{
		ft_putstr_fd("declare -x ", fd[WRITE]);
		if (ft_strchrid(tmp[i], '=') != -1)
			export_view_print(tmp[i], fd);
		else
			ft_putstr_fd(tmp[i], fd[WRITE]);
		ft_putstr_fd("\n", fd[WRITE]);
		i++;
	}
	free_table(tmp);
	if (!pid)
		exit(0);
	return (0);
}

int	env(int pid, char **environ, int fd[2])
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if ((ft_strccount(environ[i], '=') > 0))
		{
			ft_putstr_fd(environ[i], fd[WRITE]);
			ft_putstr_fd("\n", fd[WRITE]);
		}
		i++;
	}
	if (!pid)
		exit(0);
	return (0);
}

int	unset(char **input, int pid, t_term *term)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_unsetenv(input[i], term->env))
		{
			if (!pid)
				exit(1);
			return (1);
		}
		i++;
	}
	if (!pid)
		exit(0);
	return (0);
}
