/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:09:52 by ttampio           #+#    #+#             */
/*   Updated: 2021/03/22 14:59:03 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "libftprintf.h"
# include "get_next_line.h"
# include "queue.h"
# include "stack.h"
# include "btree.h"
# include "trie.h"
# include "dlist.h"

# define BUFF_SIZE 32
# define FD_SIZE 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef enum		e_strjointype
{
	FREE_BOTH,
	FREE_LEFT,
	FREE_RIGHT,
	NOFREE
}					t_strjointype;

size_t				ft_charcnt(char *s, char target);
int					ft_strchrescpd(char *str, size_t i, char escp_chr);
int					ft_power(int num, int power);
void				ft_arraydel(char **array);
char				*ft_strjoinchar(char const *s1, char c);
char				**ft_arraynew(size_t size);
char				**ft_array_push(char **array, char *str, int index);
size_t				ft_charscnt(char *s, char *targets);
void				ft_putchar(char c);
int					ft_iputchar(int c);
size_t				ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
long				ft_strchri(char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcmp_ci(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isspace(int c);
int					ft_isquote(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f) (char*));
void				ft_striteri(char *s, void (*f) (unsigned int, char*));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_math_operation(const void *first, const void *second,
					size_t size, char *(*op)(int, int));
char				*ft_multiply(int int_1, int int_2);
char				*ft_division(int int_1, int int_2);
char				*ft_addition(int int_1, int int_2);
char				*ft_substraction(int int_1, int int_2);
char				*ft_modulo(int int_1, int int_2);
char				*ft_lessthan(int int_1, int int_2);
char				*ft_greaterthan(int int_1, int int_2);
char				*ft_lessthan_orequal(int int_1, int int_2);
char				*ft_greaterthan_orequal(int int_1, int int_2);
char				*ft_logequal(int int_1, int int_2);
char				*ft_logiequal(int int_1, int int_2);
char				*ft_math_and(int int_1, int int_2);
char				*ft_math_or(int int_1, int int_2);
char				*ft_math_and(int int_1, int int_2);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, t_strjointype frtype);
char				*ft_strtrim(char const *s);
void				ft_putstr(char const *s);
void				ft_putstr_ltrl(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putendl_ltrl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_or_add(t_list **head, const void *data,
					size_t size);
void				ft_lstdelone(t_list **alst, void (*del) (void*, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_lstaddend(t_list **ast, t_list *new);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_strndup(const char *s1, size_t n);
void				ft_swaparr(void **ptr1, void **ptr2);
void				ft_swap_size_t(size_t *a, size_t *b);
long				ft_strchri(char *s, int c);
void				ft_strrev(char *str);
char				*ft_itoa_base(long long value, int base, int upper);
int					ft_atoi_base64(const char *num, int base);
char				*ft_itoa_base64(long long value, int base, int upper);
int					ft_belongs_to_base(char c, int base);
char				*ft_dec_to_base(int base, unsigned long long input_num, \
		int uppr_case);
char				*ft_lltoa(long long n);
unsigned long long	ft_power_of_ten(int n);
long long			ft_atoll(const char *str);
int					ft_contains_chrs(char *str, char *chrs);
int					ft_contains_only_chrs(char *str, char *chrs,
										int allow_empty);
int					ft_contains_chrs_n(char *str, char *chrs, size_t n);
void				ft_memfree(void **mem, size_t num);
char				*ft_ret_filename(char *file_str);
char				*ft_ret_filename2(char *file_str);
size_t				ft_strarrlen(char **strarr);
void				ft_putstre(const char *str);
char				*ft_ptpsub(char *start, char *end);
unsigned long long	ft_abs(long long num);
int					ft_strskp(char *str, char skipchar, int skipescpd, \
								size_t *org_i);
int					ft_strpush(char ***strarr, char *new_str);
void				ft_strarrfree(char ***strarr);
int					ft_jmpesc(char *cur_chr, char esc_chr, size_t *i, \
				size_t strlen);
char				*ft_strarrtostr(char **strarr, int free_arr);
int					ft_isdelim(char c, char *chrarr, int incl_spaces);
char				*ft_malchr(char c);
char				*ft_strremnchr(char **str, size_t n);
int					ft_strunshift(char ***strarr, char *new_str);
int					ft_strlstc(char *str, int c);
int					ft_strremchr(char **str, size_t i);
int					ft_str_in_arr(char **arr, char *str);
void				ft_strarrsort(char **arr);
void				ft_putnchar(size_t cnt, unsigned char c);
char				*ft_straddchr(char **str_ptr, char c);
int					ft_chrescpd(size_t i, char esc_c, char *str);
char				**ft_strarrjoin(char **arr1, char **arr2);
int					get_next_line(const int fd, char **line);

#endif
