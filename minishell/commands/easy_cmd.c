/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:42:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/28 17:58:05 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error404(char *line, int pid, t_term *term)
{
	char	*tmp;

	if (line)
	{
		tmp = ft_translate(line, term);
		printf("minishell: %s: command not found\n", tmp);
		free(tmp);
	}
	if (!pid)
		exit(127);
	return (127);
}

static void	quit_exit(t_op *op, t_term *term)
{
	int		neg;

	neg = 0;
	if (!mat_row((void **)op->argv))
	{
		ft_putstr_fd("exit\n", 1);
		ft_clstclear(&term->queque.first, free_op);
		exit(term->last_status);
	}
	if (op->argv[0][0] == '-' && op->argv[0][0])
		neg = 1;
	if (!ft_strdigit(&op->argv[0][neg]))
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(op->argv[0], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		ft_clstclear(&term->queque.first, free_op);
		exit (1);
	}
	neg = ft_latoi(op->argv[0]);
	ft_clstclear(&term->queque.first, free_op);
	ft_putstr_fd("exit\n", 1);
	exit(neg);
}

int	quit(t_op *op, t_term *term)
{
	if (mat_row((void **)op->argv) > 1)
		return (ft_putstr_fd("minishell: exit: too many argument\n", 1) * 0 + 1);
	close_history(&term->history);
	free(term->input);
	quit_exit(op, term);
	return (0);
}

int	pwd(int pid, int fd[2])
{
	ft_putstr_fd(find_path(), fd[WRITE]);
	ft_putstr_fd("\n", fd[WRITE]);
	if (!pid)
		exit(0);
	return (0);
}

int	cd(t_op *op, int pid, t_term *term)
{
	int	ret;

	ret = change_path(op->argv[0], term);
	if (!pid)
		exit(ret);
	return (ret);
}
