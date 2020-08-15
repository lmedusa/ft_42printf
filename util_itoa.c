/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:39:48 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:39:50 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			int_len(long long num)
{
	int		i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char		*ft_intstr(long long nb, char *res, int size)
{
	if (nb == 0)
	{
		res[0] = '0';
		res[size] = '\0';
		return (res);
	}
	else if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[size] = '\0';
	while (nb)
	{
		res[--size] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (res);
}

char		*ft_itoa(long long n)
{
	char	*res;
	int		sizes;

	sizes = int_len(n);
	if (!(res = (char *)malloc(sizeof(char) * sizes + 1)))
		return (NULL);
	res = ft_intstr(n, res, sizes);
	return (res);
}
