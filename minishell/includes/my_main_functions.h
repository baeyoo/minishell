/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:54:25 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/23 17:38:42 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MAIN_FUNCTIONS_H
# define MY_MAIN_FUNCTIONS_H

# define PATH_MAX	4096 
# define RED_WRITE	1
# define RED_READ	2
# define RED_STDIN	0
# define RED_APPEND	3
# include "struct.h"

void	init(t_term *term, char **env);
int		find_command(t_term *term);
void	ft_signal_manager(void);
void	my_clear_screen(void);
int		ft_parsing_hub(t_term *term);
void	ft_execute_commands(t_clist *queque, t_term *term, int pid);
void	exec_manager(t_clist *queque, t_term *term);
t_op	*get_op(t_clist *cls);
char	*ft_translate(char *input, t_term *term);
void	ft_dollar(char **input, t_term *term, char **trans, int *iter);
void	quotes(int *iter, char *input, char **new, char quote);
void	free_op(void *op);

void	find_cmd(t_term *term, int *iter, t_op **new);
void	find_cmd_input(t_term *term, int *iter, t_op **new);
void	find_red(t_term *term, int *iter, t_op **new);
char	**arg_matrix(char *input, t_term *term);
int		redirection(t_op *op, char **fd_error);
void	get_red(t_term *term, int *iter, t_clist **red, int type);
char	*freejoin(char *s1, char *s2, int n);
#endif
