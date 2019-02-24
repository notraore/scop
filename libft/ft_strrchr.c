/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:48:25 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:48:26 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	len;
	int		counter;

	str = (char*)s;
	counter = 0;
	len = ft_strlen(str);
	while (counter < (int)len)
	{
		counter++;
		str++;
	}
	while (counter >= 0)
	{
		if (str[0] == (char)c)
			return (str);
		str--;
		counter--;
	}
	return (NULL);
}
