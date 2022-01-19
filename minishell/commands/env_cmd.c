/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:49:54 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/26 17:04:38 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	strck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isalnum(s[i]) || s[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

static char	**export_segmentation(char *input)
{
	char	**cut;
	int		plus;
	int		len;
	char	**ret;

	ret = ft_calloc(3, sizeof(char *));
	if (ft_strchrid(input, '=') != -1)
	{
		cut = ft_strcut(input, ft_strchrid(input, '=') + 1);
		ret[1] = ft_strdup(cut[1]);
		plus = (cut[0][ft_strchrid(input, '=') - 1] == '+');
		len = ft_strlen(cut[0]) - plus;
		free_table(cut);
		cut = ft_strcut(input, len - 1);
		ret[0] = ft_strdup(cut[0]);
		free_table(cut);
	}
	else
	{
		ret[0] = ft_strdup(input);
		ret[1] = ft_strdup("");
	}
	return (ret);
}

static int	ck_input(char *input)
{
	char	**cut;
	int		plus;
	int		len;
	int		equal;

	equal = ft_strchrid(input, '=');
	if (equal != -1)
	{
		cut = ft_strcut(input, ft_strchrid(input, '='));
		plus = (cut[0][ft_strchrid(input, '=') - 1] == '+');
		len = ft_strlen(cut[0]) - plus;
		if (len && (ft_isalpha(cut[0][0]) || cut[0][0] == '_'))
		{
			free_table(cut);
			cut = ft_strcut(input, len);
			len = strck(&cut[0][1]);
			free_table(cut);
			return (len);
		}
		free_table(cut);
		return (0);
	}
	return ((ft_isalpha(input[0]) || input[0] == '_' ) && strck(&input[1]));
}

static void	export2(char **input, t_term *term, int i)
{
	char	**var;
	int		equal;

	var = export_segmentation(input[i]);
	equal = ft_strchrid(input[i], '=');
	if (equal == -1)
		ft_setenv(var[0], var[1], EMPTY, term);
	else if (input[i][equal - 1] == '+')
		ft_setenv(var[0], var[1], JOIN, term);
	else
		ft_setenv(var[0], var[1], OVERWRITE, term);
	free_table(var);
}

int	export(char **input, int pid, t_term *term, int *fd)
{
	int		ck;
	int		i;

	i = 0;
	if (!input[i])
		ck = export_view(pid, term->env, fd);
	while (input[i])
	{
		ck = ck_input(input[i]);
		if (ck)
			export2(input, term, i);
		else
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(input[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			break ;
		}
		i++;
	}
	if (!pid)
		exit(!ck);
	return (!ck);
}
