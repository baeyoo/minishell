/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:25:33 by dlanotte          #+#    #+#             */
/*   Updated: 2021/07/28 17:42:16 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "minishell.h"

int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				free_table(char **table);
char			*find_path(void);
int				change_path(char *new_path, t_term *term);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			**ft_strcut(char *s, int pos);
int				ft_strdigit(char *s);
int				ft_putstr_fd(char *s, int fd);
char			*ft_itoa(int n);
int				ft_isdigit(int c);
long			ft_latoi(const char *str);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strnstr(const char *haystack, \
					const char *needle, size_t len);
int				ft_strccount(char *s, char c);
int				ft_strchrid(const char *str, int c);
size_t			mat_row(void **str);
int				ft_stralpha(char *s);
int				ft_isalpha(int c);
void			**mat_join_row(void **mat, void *row);
void			**mat_init(int dim, int h);
char			**mat_dup(char **mat);
void			ft_sort_matrix(char **tab, int size);

t_clist			*ft_clstnew(void *content);
void			ft_clstadd_front(t_clist **lst, t_clist *new);
int				ft_clstsize(t_clist *lst);
t_clist			*ft_clstlast(t_clist *lst);
void			ft_clstadd_back(t_clist **lst, t_clist *new);
void			ft_clstdelone(t_clist *lst, void (*del)(void*));
void			ft_clstclear(t_clist **lst, void (*del)(void*));
void			ft_clstiter(t_clist *lst, void (*f)(void *));
t_clist			*ft_clst_export(t_clist *lst);
char			*ft_strdup(char *s);
char			**table_dup(char **mat);
int				ft_isalnum(int c);
int				ft_stralnum(char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_skip(char *s, int *iter, char c);
char			*ft_shint(int *a, int c);
#endif
