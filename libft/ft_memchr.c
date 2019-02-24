/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:44:10 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:44:12 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		count;

	count = 0;
	str = (const char*)s;
	while (count < n)
	{
		if (str[count] == (char)c)
			return ((void*)str + count);
		count++;
	}
	return (NULL);
}
