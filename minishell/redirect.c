/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:45:45 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/27 16:30:47 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	mortacci(int pp[2], t_red *tmp)
{
	char	*line;

	while (get_next_line_basic(0, &line) != -1 \
		 && ft_strncmp(line, tmp->input, ft_strlen(tmp->input) + 1))
	{
		ft_putstr_fd(line, pp[WRITE]);
		ft_putstr_fd("\n", pp[WRITE]);
		ft_putstr_fd(">", 1);
		free(line);
	}
	if (line)
		free(line);
	exit(0);
}

static int	red_stdin(t_op *op, t_red *tmp)
{
	char	*line;
	int		pp[2];

	if (op->fd[READ] > READ)
		close (op->fd[READ]);
	if (pipe(pp) == -1)
		return (1);
	op->fd[READ] = pp[READ];
	ft_putstr_fd(">", 1);
	line = 0;
	g_term->pid = fork();
	if (!g_term->pid)
	{
		mortacci(pp, tmp);
	}
	waitpid(g_term->pid, &g_term->last_status, 0);
	close(pp[WRITE]);
	return (0);
}

static int	red_support(t_op *op, t_red *tmp)
{
	if ((tmp->input && !tmp->input[0]) || !tmp->input)
		return (-1);
	if (tmp->type == RED_WRITE || tmp->type == RED_APPEND)
	{
		if (op->fd[WRITE] > 1)
			close(op->fd[WRITE]);
		if (tmp->type == RED_WRITE)
			op->fd[WRITE] = open(tmp->input, O_RDWR | O_TRUNC | O_CREAT, 0755);
		else
			op->fd[WRITE] = open(tmp->input, O_RDWR | O_APPEND | O_CREAT, 0755);
		if (op->fd[WRITE] < 0)
			return (1);
	}
	else if (tmp->type == RED_READ)
	{
		if (op->fd[READ] > 0)
			close(op->fd[READ]);
		op->fd[READ] = open(tmp->input, O_RDONLY, 0444);
		if (op->fd[READ] < 0)
			return (1);
	}
	else if (tmp->type == RED_STDIN)
		return (red_stdin(op, tmp));
	return (0);
}

static	int	ck_token(t_op *op)
{
	t_red	*tmp;
	int		ex;
	int		error;

	ex = 0;
	while (!ex)
	{
		tmp = (t_red *)op->red->content;
		error = (tmp->input && !tmp->input[0]) || !tmp->input;
		ex = op->red->last;
		op->red = op->red->next;
	}
	return (error);
}

int	redirection(t_op *op, char **fd_error)
{
	t_red	*tmp;
	int		ex;
	int		error;

	if (ck_token(op))
		return (-1);
	ex = 0;
	while (!ex)
	{
		tmp = (t_red *)op->red->content;
		error = red_support(op, tmp);
		if (error)
		{
			*fd_error = ft_strjoin("", tmp->input);
			return (error);
		}
		ex = op->red->last;
		op->red = op->red->next;
	}
	return (0);
}
