/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:38:35 by amarcell          #+#    #+#             */
/*   Updated: 2021/07/14 16:29:59 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define	EMPTY			0
# define	OVERWRITE		1
# define	JOIN			2

int		ft_unsetenv(char *name, char **env);
int		ft_setenv(char *name, char *content, int option, t_term *terms);
char	*ft_getenv(char *name, char **env);
int		id_env(char *name, char **env);
#endif