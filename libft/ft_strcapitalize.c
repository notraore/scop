/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcapitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:00:07 by notraore          #+#    #+#             */
/*   Updated: 2017/03/26 15:00:08 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (flag == 1)
				str[i] = str[i] - 32;
			flag = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (str);
}
