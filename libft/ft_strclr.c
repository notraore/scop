/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:46:07 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:46:12 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char			*str;
	unsigned int	count;

	str = (char *)s;
	count = 0;
	if (str)
	{
		while (str[count])
		{
			str[count] = '\0';
			count++;
		}
	}
}
