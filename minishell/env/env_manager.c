/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:36:59 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/26 16:25:57 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*new_var(char *name, char *content, int empty)
{
	char	*var;
	char	*temp;

	if (empty)
		return (ft_strdup(name));
	var = ft_strjoin(name, "=");
	temp = var;
	var = ft_strjoin(var, content);
	free(temp);
	return (var);
}

int	ft_unsetenv(char *name, char **env)
{
	int	id;
	int	j;

	id = id_env(name, env);
	if (id == -1)
		return (0);
	free(env[id]);
	j = id;
	while (env[++id])
	{
		env[j] = env[id];
		j++;
	}
	env[j] = 0;
	return (1);
}

char	*ft_getenv(char *name, char **env)
{
	int	id;

	id = id_env(name, env);
	if (id == -1)
		return (0);
	return ((&env[id][ft_strlen(name) + 1]));
}

static int	join_var(char *name, char *content, char **env)
{
	char	*temp;
	int		id;

	id = id_env(name, env);
	if (id != -1)
	{
		temp = env[id];
		env[id] = new_var(name, ft_strjoin(ft_getenv(name, env), content), 0);
		free(temp);
		return (1);
	}
	return (0);
}

int	ft_setenv(char *name, char *content, int option, t_term *term)
{
	int	id;

	id = id_env(name, term->env);
	if (id == -1 && option == EMPTY)
		term->env = (char **)mat_join_row((void **)term->env, \
			(void *)new_var(name, content, 1));
	else if (id == -1 && option != EMPTY)
		term->env = (char **)mat_join_row((void **)term->env, \
			(void *)new_var(name, content, 0));
	else if (option == OVERWRITE)
	{
		free(term->env[id]);
		term->env[id] = new_var(name, content, 0);
		return (term->env[id] != 0);
	}
	else if (option == JOIN)
		return (join_var(name, content, term->env));
	return (0);
}
