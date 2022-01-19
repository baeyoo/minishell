/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:36:59 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/30 15:02:15 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	other_id(char *cmd, char **cmds)
{
	int	ret;

	if (!ft_strncmp(cmd, cmds[MY_EXIT], 10))
		ret = MY_EXIT;
	else if (!ft_strncmp(cmd, cmds[MY_EXPORT], 10))
		ret = MY_EXPORT;
	else if (!ft_strncmp(cmd, cmds[MY_PWD], 10) \
	 || !ft_strncmp(cmd, cmds[MY_PWD2], 10))
		ret = MY_PWD;
	else if (!ft_strncmp(cmd, cmds[MY_UNSET], 10))
		ret = MY_UNSET;
	else
		ret = ERROR;
	return (ret);
}

int	cmd_id(char *cmd)
{
	char	**cmds;
	int		ret;

	cmds = ft_split(COMMANDS, ',');
	if (!ft_strncmp(cmd, cmds[MY_CD], 10))
		ret = MY_CD;
	else if (!ft_strncmp(cmd, cmds[MY_CLEAR], 10))
		ret = MY_CLEAR;
	else if (!ft_strncmp(cmd, cmds[MY_ECHO], 10) \
		 || !ft_strncmp(cmd, cmds[MY_ECHO2], 10))
		ret = MY_ECHO;
	else if (!ft_strncmp(cmd, cmds[MY_ENV], 10) \
	 || !ft_strncmp(cmd, cmds[MY_ENV2], 10))
		ret = MY_ENV;
	else
		ret = other_id(cmd, cmds);
	free_table(cmds);
	return (ret);
}

int	n_flag(char *input)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	if (input && !ft_strncmp(input, "-n", 2))
	{
		n = 1;
		while (i != -1 && input[i])
		{
			if (input[i++] != 'n')
				return (0);
		}
	}
	return (n);
}

int	my_echo(t_op *op, int pid)
{
	int	i;
	int	n;

	i = 0;
	while (n_flag(op->argv[i]))
		i++;
	n = i;
	while (op->argv[i])
	{
		if (n != i)
			ft_putstr_fd(" ", op->fd[WRITE]);
		ft_putstr_fd(op->argv[i++], op->fd[WRITE]);
	}
	if (!n)
		ft_putstr_fd("\n", op->fd[WRITE]);
	if (!pid)
		exit(0);
	return (0);
}

int	clear_cmd(int pid)
{
	my_clear_screen();
	if (!pid)
		exit(0);
	return (0);
}
