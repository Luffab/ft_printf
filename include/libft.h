/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 12:09:09 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 16:47:16 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	int				zero;
	int				minus;
	int				point;
	int				champ_min;
	int				champ_point;
	char			type;
	int				star;
	char			*s;
	char			c;
	char			*d;
	char			*x;
	char			*p;
	char			*u;
}					t_list;

int					ft_printf
					(const char *str, ...) __attribute__((format(printf,1,2)));
int					ft_count_size(int nbr);
int					ft_len_of_space(t_list *list);
int					ft_putspace(int len);
int					ft_putzero(int len);
void				ft_check_flags(const char *str, int i,
					t_list *list, va_list va);
void				ft_typeof(const char *str, int i, t_list *list);
int					ft_putstring(t_list *list, char *str);
int					ft_putnull(t_list *l);
int					ft_put_char(t_list *list, va_list va);
int					ft_string(t_list *list, va_list va);
int					ft_put_number(t_list *l, va_list va);
int					ft_put_number_neg(t_list *l, char *nb,
					int len, va_list vacpy);
void				ft_initialize(t_list *list, va_list vacpy);
void				ft_len_star(const char *str, int i,
					t_list *list, va_list va);
void				ft_initialize_string(t_list *list, va_list vacpy);
int					ft_put_p(t_list *l, va_list va);
char				*ft_utoa_base(unsigned int long long n, char *base);
char				*ft_itoa_base(long long int n, char *base);
char				*ft_litoa_base(long int nb, char *base);
int					ft_put_number(t_list *l, va_list va);
int					ft_put_unsigned(t_list *l, va_list va);
int					ft_put_hexa_min(t_list *l, va_list va);
int					ft_put_hexa_maj(t_list *l, va_list va);
int					ft_int_corps(t_list *l, int len, char *nb);
char				*ft_hextoa_base(unsigned int nb, char *base);
void				ft_freelist(t_list *l);
int					ft_ispoint(const char *str, int i);

#endif
