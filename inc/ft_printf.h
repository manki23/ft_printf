/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:47:33 by manki             #+#    #+#             */
/*   Updated: 2019/07/22 17:43:56 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
/*
# define E_START 1
# define E_END 15
# define M_START 16
# define M_END 127
# define E_BIAS 16383
# define BUF 16
*/
# define E_START 1
# define E_END 11
# define M_START 12
# define M_END 63
# define E_BIAS 1023
# define BUF 8

typedef unsigned char	t_byte;

typedef struct		s_option
{
	t_byte	flag;
	t_byte	option;
	t_byte	modif;
	int		width;
	int		precision;
}					t_option;

typedef char		*(*t_ft_conv)(t_option, va_list *, size_t *size);

typedef struct		s_conv
{
	char			*c;
	t_ft_conv		fun;
}					t_conv;

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *restrict format, ...);

char				*ft_conv(char **p, va_list *ap, size_t *size);
void				ft_fill_t_option(t_option *opt, char **p);
int					ft_is_conv(char c);
void				ft_init_option(t_option *opt);

void				ft_add_bit(t_byte *tab, t_byte bit, t_byte at);
t_byte				ft_read(t_byte tab[], t_byte at);
t_byte				ft_fill_opt(t_byte *dst, char src, char tab[]);

t_list				*ft_lstnew(char *content, size_t content_size);
void				ft_lsadd(t_list **list, char *content, size_t c_size);
int					ft_lstlen(t_list *list);
size_t				ft_lst_content_size(t_list *list);
size_t				ft_lstprint(t_list list[]);
void				ft_lstdel(t_list **alst);

int					ft_nblen(long long n);
int					ft_unblen_base(unsigned long long n, char *base);
void				ft_tr(char *s, char old, char neww);
double				ft_ipower(double nb, double power);

t_byte				ft_is_max(char *bit_nb, int from, int to);
t_byte				ft_is_null(char *bit_nb, int from, int to);
char				*ft_traduct(char *nb, int op, double f);
unsigned long long	ft_mul2(char *nb, int i, int end);

void				ft_afficher_bit(char *str, int mod);
void				ft_display(t_option opt);

char				*ft_float_to_str(double arg);
void				ft_round(char *mantissa, int precision);
char				*ft_round2(char *nb, int len);

char				*ft_fill_di_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_uoxx_output(t_option opt, va_list *ap, size_t *s);
char				*ft_fill_c_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_s_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_p_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_f_output(t_option opt, va_list *ap, size_t *size);

char				*ft_ctob(unsigned char *tab, int size);
int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);
int					ft_isdigit(int c);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long n, char base[]);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ulltoa_base(unsigned long long n, char base[]);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strljoin(char const *s1, char const *s2, int a, int b);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
#endif
