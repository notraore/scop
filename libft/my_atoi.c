/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:49:49 by arive-de          #+#    #+#             */
/*   Updated: 2017/06/09 10:50:01 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		my_atoi(char *str, int *a)
{
	int					i;
	int					neg;
	unsigned long long	stock;
	int					fail;

	i = 0;
	neg = 1;
	stock = 0;
	fail = 0;
	if (str[i] == '-' && str[i + 1] != '\0')
	{
		neg = -1;
		i++;
	}
	if (str[i] == '+' && neg != -1 && str[i + 1] != '\0')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
		stock = stock * 10 + ((int)str[i++] - 48);
	fail = (str[i] != '\0' ? 1 : 0);
	if ((stock > 2147483647 && neg > 0) || (stock > 2147483648 && neg < 0))
		fail++;
	*a = (int)stock * neg;
	return (fail > 0 ? 0 : 1);
}
