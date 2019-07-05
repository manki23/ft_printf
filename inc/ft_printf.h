/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:47:33 by manki             #+#    #+#             */
/*   Updated: 2019/07/05 11:41:18 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_option
{
	char	flag;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hashtag;
	int		point;
	int		width;
	int		precision;
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		ld;
}					t_option;

typedef unsigned char	t_byte;

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

t_list				*ft_lstnew(char *content, size_t content_size);
void				ft_lsadd(t_list **list, char *content, size_t c_size);
int					ft_lstlen(t_list *list);
size_t				ft_lst_content_size(t_list *list);
void				ft_lstprint(t_list *list);

int					ft_nblen(long long n);
int					ft_unblen_base(unsigned long long n, char *base);
void				ft_tr(char *s, char old, char neww);
int					ft_ipower(int nb, int power);

void				ft_display_option(t_option opt);

char				*ft_fill_di_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_uoxx_output(t_option opt, va_list *ap, size_t *s);
char				*ft_fill_c_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_s_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_p_output(t_option opt, va_list *ap, size_t *size);
char				*ft_fill_f_output(t_option opt, va_list *ap, size_t *size);

int					ft_atoi(const char *str);
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
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
#endif
