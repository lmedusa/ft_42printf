/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_hex_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:34:54 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:34:55 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_toup(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			i++;
		}
	}
	return (str);
}

char		*ft_hex(unsigned int ptr)
{
	t_pft		var;
	char		*base;

	base = NULL;
	ft_bzero(&var, sizeof(var));
	if (!ptr)
		return (ft_strdup("0"));
	var.x = ptr;
	while (var.x /= 16)
		var.sz++;
	var.sz += 1;
	base = "0123456789abcdef";
	if (!(var.s = (char *)malloc(sizeof(char) * var.sz + 1)))
		return (NULL);
	var.s[var.sz] = '\0';
	while (var.sz > 0)
	{
		var.s[var.sz - 1] = base[ptr % 16];
		var.sz--;
		ptr /= 16;
	}
	return (var.s);
}

int			proc_x(const char ft, va_list ap, t_wp f)
{
	t_pft	var;
	int		ret;

	ft_bzero(&var, sizeof(var));
	ret = 0;
	var.x = va_arg(ap, unsigned int);
	var.s = ft_hex(var.x);
	var.sz = ft_strlen(var.s);
	if (ft == 'X')
		var.s = ft_toup(var.s);
	ret += proc_d_wid(var, f, 2);
	if (f.flg == 1 && f.prec == 0 && var.x == 0)
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

char		*ft_ptr(unsigned long ptr)
{
	t_pft		var;
	char		*base;

	base = NULL;
	ft_bzero(&var, sizeof(var));
	if (!ptr)
		return (ft_strdup("0"));
	var.x = ptr;
	while (var.x /= 16)
		var.sz++;
	var.sz += 1;
	base = "0123456789abcdef";
	if (!(var.s = (char *)malloc(sizeof(char) * var.sz + 1)))
		return (NULL);
	var.s[var.sz] = '\0';
	while (var.sz > 0)
	{
		var.s[var.sz - 1] = base[ptr % 16];
		var.sz--;
		ptr /= 16;
	}
	return (var.s);
}

int			proc_ptr(va_list ap, t_wp f)
{
	t_pft	var;
	int		ret;

	ft_bzero(&var, sizeof(var));
	ret = 0;
	var.x = (unsigned long)va_arg(ap, unsigned long);
	var.s = ft_ptr(var.x);
	var.sz = ft_strlen(var.s) + 2;
	ret += util_prnt_w(' ', f.widh - var.sz);
	ret += ft_putstr("0x");
	ret += ft_putstr(var.s);
	ret += util_prnt_w(' ', f.minus - var.sz);
	free(var.s);
	return (ret);
}
