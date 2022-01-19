/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:19:20 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/28 13:15:26 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// tramite la funzione getcwd trova il path della directory attuale
// printa le cazzate tipo l'AK 

int	find_command(t_term *term)
{
	int		flag_stop;
	char	*current_path;

	flag_stop = 1;
	while (flag_stop > 0)
	{
		current_path = find_path();
		graphic_hub(2, current_path);
		flag_stop = get_next_line(0, term);
		ft_parsing_hub(term);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_term	term;

	argc = 0;
	argv[0] = argv[0];
	init(&term, env);
	g_term = &term;
	write(1, "", 1);
	g_term->pid = getpid();
	my_clear_screen();
	ft_signal_manager();
	find_command(&term);
	return (0);
}

// Execute the commands if it aren't a build-in cmd, set the correct
// in/out fd whit dup

static void	ft_execute_buildin(int commands, int pid, \
	t_clist *queque, t_term *term)
{
	if (commands == MY_CLEAR)
		term->last_status = clear_cmd(pid);
	else if (commands == MY_EXIT)
		term->last_status = quit(get_op(queque), term);
	else if (commands == MY_CD)
		term->last_status = cd(get_op(queque), pid, term);
	else if (commands == MY_PWD)
		term->last_status = pwd(pid, get_op(queque)->fd);
	else if (commands == MY_EXPORT)
		term->last_status = export(get_op(queque)->argv, pid, term, \
			get_op(queque)->fd);
	else if (commands == MY_UNSET)
		term->last_status = unset(get_op(queque)->argv, pid, term);
	else if (commands == MY_ENV)
		term->last_status = env(pid, term->env, get_op(queque)->fd);
	else if (commands == MY_ECHO)
		term->last_status = my_echo(get_op(queque), pid);
}

void	ft_execute_commands(t_clist *queque, t_term *term, int pid)
{
	int	commands;

	commands = cmd_id(get_op(queque)->cmd);
	if (commands != -1)
		ft_execute_buildin(commands, pid, queque, term);
	else
	{
		if (get_op(queque)->fd[WRITE] > 1 )
			dup2(get_op(queque)->fd[WRITE], WRITE);
		if (get_op(queque)->fd[READ])
			dup2(get_op(queque)->fd[READ], READ);
		exec_cmd(get_op(queque), pid, term->env);
	}
}
