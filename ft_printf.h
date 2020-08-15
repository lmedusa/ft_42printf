/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:44:05 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/13 23:44:06 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef	struct		s_wp
{
	int					prec;
	int					widh;
	int					minus;
	int					null;
	int					flg;
}					t_wp;

typedef	struct		s_pft
{
	long long			d;
	int					sz;
	unsigned long int	x;
	char				*s;
	char				c;
	va_list				ap;
}					t_pft;

int					ft_printf(const char *format, ...);
int					start_proc(const char *ft, va_list ap, t_wp wp, int ret);
int					check_spec(const char ft, char *spec);
int					processor(const char ft, va_list ap, t_wp flgs);
int					proc_width(const char *ft, va_list ap);
int					proc_minus(const char *ft, va_list ap);
int					proc_prec(const char *ft, va_list ap, t_wp *f);
int					ft_putchar(const char c);
int					ft_putstr(const char *str);
int					util_prnt_w(char c, int size);
int					proc_d_wid(t_pft var, t_wp f, int flg);
int					proc_d_f(t_pft var, t_wp f, int flg);
int					proc_d_minus(t_pft var, t_wp f);
int					proc_d(const char ft, va_list ap, t_wp f);
int					proc_x(const char ft, va_list ap, t_wp f);
int					proc_ptr(va_list ap, t_wp f);
int					proc_s(va_list ap, t_wp f);
int					s_dot(char *str, int dot);
int					proc_c(const char ft, va_list ap, t_wp f);
int					ft_util_w(const char *ft);
int					int_len(long long num);
int					ft_check(char s);
int					ft_atoi(const char *str);
char				*ft_spc(char *s);
char				*ft_strdup(const char *str);
char				*ft_strnew(size_t size);
char				*ft_intstr(long long nb, char *res, int size);
char				*ft_itoa(long long n);
char				*ft_toup(char *str);
char				*ft_hex(unsigned int ptr);
void				ft_bzero(void *str, size_t len);
void				parser(const char *ft, va_list ap, t_wp *wp);
size_t				ft_strlen(const char *str);

#endif
