/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:45:50 by lmedusa           #+#    #+#             */
/*   Updated: 2020/08/14 02:45:51 by lmedusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (6);
	while (str[i] != '\0')
		i++;
	return (i);
}

void		ft_bzero(void *str, size_t len)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		src[i] = '\0';
		i++;
	}
}

char		*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (size < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}

int			ft_util_w(const char *ft)
{
	int			i;
	char		*str;

	str = NULL;
	i = 0;
	while (ft[i] >= '0' && ft[i] <= '9')
		i++;
	if (!(str = ft_strnew(i)))
		return (0);
	i = 0;
	while (*ft >= '0' && *ft <= '9')
	{
		str[i] = *ft;
		ft++;
		i++;
	}
	i = ft_atoi(str);
	free(str);
	return (i);
}

char		*ft_strdup(const char *str)
{
	char	*res;
	int		i;
	int		max;

	max = ft_strlen(str);
	i = 0;
	res = (char *)malloc(sizeof(char) * max + 1);
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
