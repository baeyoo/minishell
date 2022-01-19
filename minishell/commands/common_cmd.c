/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:12:51 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/28 18:31:40 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Create a second process where it execute shell base command like ls
//		we need 2 proces because execve substitute the current process with 
//		called proces

static void	son_exe(char *cmd, char **args, char **env)
{
	int		i;
	char	*temp;
	char	**path;

	path = ft_split(ft_getenv("PATH", env), ':');
	i = 0;
	if (!path)
		return ;
	while (path[i])
	{
		temp = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(temp);
		temp = ft_strjoin(path[i], cmd);
		execve(temp, args, env);
		free(temp);
		i++;
	}
	free_table(path);
}

static void	loop(t_op *op, char **args)
{
	int	i;

	i = -1;
	if (op->cmd)
		args[0] = op->cmd;
	while (op->argv[++i])
		args[i + 1] = op->argv[i];
}

int	exec_cmd(t_op *op, int pid, char **env)
{
	char	**args;

	args = ft_calloc(mat_row((void **)op->argv) + 2, sizeof(char *));
	loop(op, args);
	if (!pid)
	{
		son_exe(op->cmd, args, env);
		if (execve(op->cmd, args, env) == -1)
		{
			if (!((!g_term->red && (op->cmd[0] == '<' || op->cmd[0] == '>')) \
			 || op->cmd[0] == '|'))
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(op->cmd, 2);
				if (!ft_getenv("PATH", env))
					ft_putstr_fd(": No such file or directory\n", 2);
				else
					ft_putstr_fd(": command not found:\n", 2);
			}
			exit((free_table(args) * 0) + 127);
		}
	}
	return (1);
}
