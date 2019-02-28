/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:24:18 by notraore          #+#    #+#             */
/*   Updated: 2017/04/10 19:26:28 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int negatif;

	i = 0;
	j = 0;
	negatif = 1;
	while (ft_isspace(str[i]) == 1)
		str++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (j * negatif);
}
