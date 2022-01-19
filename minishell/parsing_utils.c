#include "includes/minishell.h"

static int	fucknorm2(char **str, int i, t_term *term, int fuck)
{
	char	*s;

	if (!fuck)
		return ((*str)[i] && (*str)[i] != '|' \
		 && (*str)[i] != '>' && (*str)[i] != '<' \
	 	 && (*str)[i] != ' ');
	else
	{
		s = ft_translate(*str, term);
		free(*str);
		*str = s;
	}
	return (0);
}

void	get_red(t_term *term, int *iter, t_clist **red, int type)
{
	int		iter2;
	t_red	*new;

	new = ft_calloc(1, sizeof(t_red));
	while (term->input[*iter] == ' ')
		(*iter)++;
	iter2 = *iter;
	while (fucknorm2(&term->input, iter2, term, 0))
		iter2++;
	new->input = ft_calloc(iter2 - *iter + 2, 1);
	if (term->input[*iter] == '\"')
		quotes(iter, term->input, &new->input, '\"');
	iter2 = 0;
	while (fucknorm2(&term->input, *iter, term, 0))
		new->input[iter2++] = term->input[(*iter)++];
	while (new->input[--iter2] == ' ')
		new->input[iter2] = 0;
	fucknorm2(&new->input, 0, term, 1);
	new->type = type;
	if (*red)
		ft_clstadd_back(red, ft_clstnew(new));
	else
		*red = ft_clstnew(new);
}

int	count_row2(char *input, int *iter)
{
	int		size;
	char	c;

	size = *iter;
	c = input[*iter];
	while (c && ((c != ' ' && c != '>' && c != '<' && c != '|')))
	{
		if ((c == '\"') && ft_strchrid(input + *iter + 1, '\"') > -1)
			*iter += ft_strchrid(input + *iter + 1, '\"') + 1;
		else if ((c == '\'') && ft_strchrid(input + *iter + 1, '\'') > -1)
			*iter += ft_strchrid(input + *iter + 1, '\'') + 1;
		(*iter)++;
		c = input[*iter];
	}
	size = *iter - size;
	return (size);
}

/* int	count_row2(char *input, int *iter)
{
	int		size;
	int		flag;
	//int		quotes;
	char	c;
	int		i;

	i = *iter;
	size = 0;
	flag = 0;
	c = input[*iter];
	while (c)
	{
		if (c == ' ' || c == '>' || c == '<' || c == '|')
		{
			if ((flag == 1) && flag %2 && (ft_strchrid(input + *iter + 1, '\"') < 0))
				break;
			else if ((flag == 2) && (ft_strchrid(input + *iter + 1, '\'') < 0))
				break;
			else if (!flag)
				break;
		}
		if (!flag)
			flag = (c == '\"');
		if (!flag)
			flag = (c == '\'') * 3;
		(*iter)++;
		size++;
		c = input[*iter];
	}
	return (size);
} */

void	find_cmd(t_term *term, int *iter, t_op **new)
{
	int		size;
	char	*temp;
	int		iter2;
	int		len;

	if ((*new)->cmd)
		free((*new)->cmd);
	ft_skip(term->input, iter, ' ');
	iter2 = *iter;
	size = count_row2(term->input, iter);
	(*new)->cmd = ft_calloc(size + 1, 1);
	ft_strlcpy((*new)->cmd, term->input + iter2, size + 1);
	temp = (*new)->cmd;
	len = ft_strlen((*new)->cmd) - 1;
	while ((*new)->cmd[len] == ' ')
		(*new)->cmd[len--] = 0;
	(*new)->cmd = ft_translate((*new)->cmd, term);
	free(temp);
}

void	find_cmd_input(t_term *term, int *iter, t_op **new)
{
	int		size;
	char	*tmp;
	int		iter2;

	size = 0;
	if ((*new)->input)
		free((*new)->input);
	if ((*new)->argv)
		free_table((*new)->argv);
	ft_skip(term->input, iter, ' ');
	iter2 = *iter;
	while (term->input[*iter] && term->input[*iter] != '>' \
		&& term->input[*iter] != '<' && term->input[*iter] != '|')
	{
		size += count_row2(term->input, iter) + (term->input[*iter] == ' ');
		*iter += (term->input[*iter] == ' ');
	}
	(*new)->input = ft_calloc(size + 1, 1);
	ft_strlcpy((*new)->input, term->input + iter2, size + 1);
	tmp = (*new)->input;
	(*new)->input = ft_strtrim((*new)->input, " ");
	(*new)->argv = arg_matrix((*new)->input, term);
	free(tmp);
}
