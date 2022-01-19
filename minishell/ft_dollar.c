#include "./includes/minishell.h"

void	trans_pid(char **input, char **trans, int *iter)
{
	char	*pid;

	pid = ft_itoa(getpid());
	*trans = freejoin(*trans, pid, 4);
	(*iter)++;
	if ((*input)[*iter] == '\"')
		(*iter)++;
}

void	trans_error(char **input, char **trans, int *iter, int error)
{
	char	*status;

	status = ft_itoa(error);
	*trans = freejoin(*trans, status, 4);
	(*iter)++;
	if ((*input)[*iter] == '\"')
		(*iter)++;
}

void	find_var(char **input, char **env, char **arg, int *iter)
{
	char	*find;
	int		i;

	i = 0;
	while ((*input)[*iter + i] && (*input)[*iter + i] != ' '
		&& (*input)[*iter + i] != '\"'
		&& (*input)[*iter + i] != '$' && (*input)[*iter + i] != '\'')
		i++;
	find = ft_calloc(i + 1, 1);
	i = 0;
	while ((*input)[*iter] && (*input)[*iter] != ' '
		&& (*input)[*iter] != '\"' && (*input)[*iter] != '$'
		&& (*input)[*iter] != '\'')
		find[i++] = (*input)[(*iter)++];
	*arg = ft_getenv(find, env);
	if (*arg)
		*arg = ft_strdup(ft_getenv(find, env));
	free(find);
}

void	ft_dollar(char **input, t_term *term, char **trans, int *iter)
{
	char	*arg;

	arg = NULL;
	(*iter)++;
	if ((*input)[*iter] == '$')
		trans_pid(input, trans, iter);
	else if ((*input)[*iter] == '?')
		trans_error(input, trans, iter, term->last_status);
	else if ((*input)[*iter] != 0 && (*input)[*iter] != ' ' \
	 && (*input)[*iter] != '\"' && (*input)[*iter] != '\'')
	{
		find_var(input, term->env, &arg, iter);
		if (arg)
			*trans = freejoin(*trans, arg, 3);
	}
	else
		 *trans = freejoin(*trans, "$", 1);
}
