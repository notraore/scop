/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:50:17 by notraore          #+#    #+#             */
/*   Updated: 2017/04/13 14:50:17 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*tmp_dest;
	unsigned const char		*tmp_src;
	size_t					count;

	tmp_dest = (unsigned char*)dst;
	tmp_src = (unsigned const char*)src;
	count = 0;
	while (count < n)
	{
		tmp_dest[count] = tmp_src[count];
		count++;
	}
	return ((char*)dst);
}
