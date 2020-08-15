/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:43:39 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:43:40 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			proc_width(const char *ft, va_list ap)
{
	t_pft	var;

	ft_bzero(&var, sizeof(var));
	if (*ft == '*')
		var.d = va_arg(ap, int);
	else
		var.d = ft_util_w(ft);
	return (var.d);
}

int			proc_minus(const char *ft, va_list ap)
{
	int		i;

	i = 0;
	while (*ft && check_spec(*ft, "-0"))
		ft++;
	if (*ft == '*')
	{
		i = va_arg(ap, int);
		if (i < 0)
			i *= -1;
	}
	else if (check_spec(*ft, "123456789"))
		i = ft_util_w(ft);
	return (i);
}

int			proc_prec(const char *ft, va_list ap, t_wp *f)
{
	t_pft	var;

	ft_bzero(&var, sizeof(var));
	f->flg = 1;
	ft++;
	if (*ft == '*')
		var.d = va_arg(ap, int);
	else
		var.d = ft_util_w(ft);
	if (var.d < 0)
		f->flg = 0;
	return (var.d);
}
