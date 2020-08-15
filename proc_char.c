/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:34:36 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:34:38 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			proc_c(const char ft, va_list ap, t_wp f)
{
	char	arg;
	char	c;
	int		ret;

	c = ' ';
	ret = 0;
	arg = '%';
	if (f.null > 0)
		c = '0';
	if (ft == 'c')
		arg = va_arg(ap, int);
	if (f.minus == 0 && f.widh == 0)
		return (ft_putchar(arg));
	if (f.widh > 0)
		return (util_prnt_w(c, f.widh - 1) + ft_putchar(arg));
	if (f.widh < 0 && !f.minus)
		f.minus = f.widh *= -1;
	return (ft_putchar(arg) + util_prnt_w(' ', f.minus - 1));
}

int			s_dot(char *str, int dot)
{
	int		ret;

	ret = 0;
	while (dot > 0)
	{
		ret += ft_putchar(*str);
		str++;
		dot--;
	}
	return (ret);
}

int			proc_s(va_list ap, t_wp f)
{
	t_pft	var;

	ft_bzero(&var, sizeof(var));
	if (!(var.s = va_arg(ap, char *)))
		var.s = "(null)";
	var.sz = ft_strlen(var.s);
	if (f.prec < 0 || (f.prec == 0 && f.flg == 0))
		f.prec = var.sz;
	if (f.prec >= var.sz)
		f.prec = var.sz;
	if (f.widh > f.prec)
	{
		var.d = util_prnt_w(' ', f.widh - f.prec);
		return (s_dot(var.s, f.prec) + var.d);
	}
	else if (f.widh < 0 || f.minus > 0)
	{
		if (f.widh < 0)
			f.minus = f.widh * -1;
		if (f.minus > f.prec)
			return (s_dot(var.s, f.prec) + util_prnt_w(' ', f.minus - f.prec));
	}
	return (s_dot(var.s, f.prec));
}
