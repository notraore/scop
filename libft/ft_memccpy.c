/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:58:39 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:58:41 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char			*tmp1;
	unsigned const char		*tmp2;
	size_t					i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned const char *)s2;
	i = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if ((*tmp1++ = *tmp2++) == c)
			return (tmp1);
		i++;
	}
	return (NULL);
}
