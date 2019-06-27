/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:47:33 by manki             #+#    #+#             */
/*   Updated: 2019/06/27 16:00:35 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_option
{
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hashtag;
	int		point;
	int		width;
	int		precision;
}					t_option;

int					ft_printf(const char *restrict format, ...);

char				*ft_conv(char **p, va_list *ap);

int					ft_nblen(int n);
void				ft_display_option(t_option opt);
void				ft_init_option(t_option *opt);
void				ft_tr(char *s, char old, char neww);
void				ft_fill_t_option(t_option *opt, char **p);
char				*ft_fill_di_output(t_option opt, int arg);

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, char base[]);
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
