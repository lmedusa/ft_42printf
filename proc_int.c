/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:34:26 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:34:28 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			proc_d_wid(t_pft var, t_wp f, int flg)
{
	char	c;

	c = ' ';
	if (f.flg == 0 && f.null == 1)
		c = '0';
	if (f.widh < var.sz || f.widh < 0)
		return (0);
	if (f.flg == 1 && f.prec == 0)
	{
		if (flg == 0 && var.d == 0)
			var.sz = 0;
		else if (flg == 2 && var.x == 0)
			var.sz = 0;
	}
	if (f.prec <= var.sz)
		f.prec = var.sz;
	if (flg == 1)
		return (util_prnt_w(c, f.widh - f.prec - 1));
	return (util_prnt_w(c, f.widh - f.prec));
}

int			proc_d_f(t_pft var, t_wp f, int flg)
{
	if (f.widh < 0)
		f.minus = f.widh * -1;
	if (f.minus <= f.prec || f.minus <= var.sz)
		return (0);
	if (f.prec < var.sz)
		f.prec = var.sz;
	if (flg == 1)
		return (util_prnt_w(' ', f.minus - f.prec - 1));
	return (util_prnt_w(' ', f.minus - f.prec));
}

int			proc_d_minus(t_pft var, t_wp f)
{
	int		ret;

	ret = 0;
	var.d *= -1;
	var.sz = int_len(var.d);
	var.s = ft_itoa(var.d);
	if (f.flg == 1 || f.null == 0)
		ret += proc_d_wid(var, f, 1);
	if (f.prec == 0 && var.d == 0)
		var.sz = 0;
	if (var.sz > 0)
	{
		ret += ft_putchar('-');
		if (f.flg == 0 && f.null == 1)
			ret += proc_d_wid(var, f, 1);
		ret += util_prnt_w('0', f.prec - var.sz);
		ret += ft_putstr(var.s);
	}
	ret += proc_d_f(var, f, 1);
	free(var.s);
	return (ret);
}

int			proc_d(const char ft, va_list ap, t_wp f)
{
	int		ret;
	t_pft	var;

	ret = 0;
	ft_bzero(&var, sizeof(var));
	if (ft == 'u')
		var.d = (unsigned int)va_arg(ap, unsigned int);
	else
		var.d = (int)va_arg(ap, int);
	var.sz = int_len(var.d);
	if (var.d < 0)
		return (proc_d_minus(var, f));
	var.s = ft_itoa(var.d);
	ret += proc_d_wid(var, f, 0);
	if (f.flg == 1 && f.prec == 0 && var.d == 0)
		var.sz = 0;
	if (var.sz > 0)
	{
		ret += util_prnt_w('0', f.prec - var.sz);
		ret += ft_putstr(var.s);
	}
	ret += proc_d_f(var, f, 0);
	free(var.s);
	return (ret);
}
