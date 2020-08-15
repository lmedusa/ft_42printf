/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:03:39 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/08 23:03:41 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_spec(const char ft, char *spec)
{
	while (*spec)
	{
		if (*spec == ft)
			return (1);
		spec++;
	}
	return (0);
}

void		parser(const char *ft, va_list ap, t_wp *wp)
{
	if (*ft == '0')
	{
		wp->null = 1;
		while (*ft && *ft == '0')
			ft++;
	}
	if (*ft == '-')
	{
		wp->minus = proc_minus(ft, ap);
		while (*ft && check_spec(*ft, "-*1234567890"))
			ft++;
	}
	if (*ft == '*' || check_spec(*ft, "123456789"))
	{
		wp->widh = proc_width(ft, ap);
		while (*ft && check_spec(*ft, "*0123456789"))
			ft++;
	}
	if (*ft == '.')
		wp->prec = proc_prec(ft, ap, wp);
}

int			start_proc(const char *ft, va_list ap, t_wp wp, int ret)
{
	while (*ft)
	{
		if (*ft == '%')
		{
			ft++;
			if (check_spec(*ft, "0123456789*.-") == 1)
			{
				parser(ft, ap, &wp);
				while (*ft && check_spec(*ft, "0123456789*.-") == 1)
					ft++;
			}
			if (check_spec(*ft, "cspdiuxX%"))
				ret += processor(*ft, ap, wp);
			else
				return (0);
			ft_bzero(&wp, sizeof(wp));
			ft++;
		}
		else
		{
			ret += ft_putchar(*ft);
			ft++;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	int			ret;
	t_pft		p;
	t_wp		f;

	ret = 0;
	ft_bzero(&f, sizeof(f));
	ft_bzero(&p, sizeof(p));
	va_start(p.ap, format);
	p.sz = start_proc(format, p.ap, f, ret);
	va_end(p.ap);
	return (p.sz);
}
