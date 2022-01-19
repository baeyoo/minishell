/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarbone <gcarbone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 23:04:11 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/07/26 18:17:19 by gcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//

char	*find_path(void)
{
	char	*current_path;
	char	*buf;

	buf = malloc((size_t) PATH_MAX + 1);
	if (buf)
		current_path = getcwd(buf, PATH_MAX + 1);
	else
		return (NULL);
	free(buf);
	return (current_path);
}

//

int	change_path(char *new_path, t_term *term)
{
	if (!new_path || !new_path[0] || new_path[0] == '~')
		new_path = ft_getenv("HOME", term->env);
	if (chdir(new_path) != 0)
	{
		printf("minishell: cd: %s: No such file or directory\n", new_path);
		return (1);
	}
	ft_setenv("OLDPWD", ft_getenv("PWD", g_term->env), OVERWRITE, g_term);
	ft_setenv("PWD", find_path(), OVERWRITE, g_term);
	return (0);
}
