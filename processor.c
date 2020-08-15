/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:44:49 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:44:51 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			processor(const char ft, va_list ap, t_wp flgs)
{
	if (flgs.null > 0)
	{
		if (flgs.minus > 0)
		{
			flgs.null = 0;
			flgs.widh = 0;
		}
	}
	if (ft == 'c' || ft == '%')
		return (proc_c(ft, ap, flgs));
	if (ft == 's')
		return (proc_s(ap, flgs));
	if (ft == 'd' || ft == 'i' || ft == 'u')
		return (proc_d(ft, ap, flgs));
	if (ft == 'x' || ft == 'X')
		return (proc_x(ft, ap, flgs));
	if (ft == 'p')
		return (proc_ptr(ap, flgs));
	return (0);
}
