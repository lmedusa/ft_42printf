/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:42:12 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:42:13 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

int			ft_putstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		i += ft_putchar(*str);
		str++;
	}
	return (i);
}

int			util_prnt_w(char c, int size)
{
	int		ret;

	ret = 0;
	while (size > 0)
	{
		ret += ft_putchar(c);
		size--;
	}
	return (ret);
}
