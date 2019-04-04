/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:13:26 by notraore          #+#    #+#             */
/*   Updated: 2017/04/13 18:13:26 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcount(const char *str, char c)
{
	int		i;
	int		flag;
	int		count;

	i = 0;
	flag = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			flag = 0;
		else if ((str[i] != c) && flag == 0)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	return (count);
}
