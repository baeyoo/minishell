/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:16:19 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/01 14:51:28 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <curses.h>
# include <fcntl.h>
# include "graphic.h"
# include "get_next_line.h"
# include "libft.h"
# include "my_main_functions.h"
# include "commands.h"
# include "struct.h"
# include "history.h"
# include "env.h"

t_term	*g_term;

#endif