/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:53:57 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/28 16:59:20 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <termios.h>

typedef struct s_str2
{
	char		*s1;
	char		*s2;
}			t_str2;

typedef struct s_red
{
	char		*input;
	int			type;
}			t_red;

typedef struct s_clist
{
	void			*content;
	struct s_clist	*next;
	struct s_clist	*pre;
	int				last;
}				t_clist;

typedef struct s_op
{
	char		*cmd;
	char		*input;
	char		**argv;
	int			pipe;
	t_clist		*red;
	int			error;
	int			fd[2];
	int			oldfd[2];
}			t_op;

typedef struct s_queque
{
	t_clist			*first;
	int				size;
}				t_queque;

typedef struct s_history
{
	int		fd;
	t_clist	*history;
	int		count_new;
}	t_history;

typedef struct s_term
{
	char			*type;
	struct termios	dconf;
	struct termios	cconf;
	t_queque		queque;
	char			*input;
	int				cursor;
	int				last_status;
	t_history		history;
	char			**env;
	int				pid;
	int				red;
}	t_term;

#endif
