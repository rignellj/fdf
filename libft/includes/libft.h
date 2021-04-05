/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:09:52 by ttampio           #+#    #+#             */
/*   Updated: 2021/04/03 19:33:58 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "stack.h"

# define BUFF_SIZE 32
# define FD_SIZE 4096

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef enum e_strjointype
{
	FREE_BOTH,
	FREE_LEFT,
	FREE_RIGHT,
	NOFREE
}					t_strjointype;

unsigned long long	ft_abs(long long num);
void				ft_arraydel(char ***array);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_check_malloc(void *ptr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa_base_u(unsigned long long int value,
						int base, int upper);
char				*ft_itoa_base(long long value, int base, int upper);
char				*ft_itoa(int n);
char				*ft_joindel(char *s1, char *s2);
char				*ft_lftoa(long double value, size_t precision);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
size_t				ft_strarrlen(char **strarr);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, t_strjointype frtype);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);

#endif
