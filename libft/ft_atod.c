/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:25:01 by notraore          #+#    #+#             */
/*   Updated: 2017/11/22 16:25:17 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		decimal(const char *str, double res, int i, int negative)
{
	double	rest;
	double	puis;

	rest = 0;
	if (str[i] == '.')
	{
		puis = 0;
		i++;
		while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
		{
			rest = rest * 10;
			rest = rest + str[i] - '0';
			puis++;
			i++;
		}
		res = res + (rest * pow(10, -puis));
	}
	if (negative == 1)
		return (-res);
	return (res);
}

double		ft_atod(const char *str)
{
	size_t	negative;
	size_t	i;
	double	res;

	negative = 0;
	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	res = decimal(str, res, i, negative);
	return (res);
}
