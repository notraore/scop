/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:49:22 by notraore          #+#    #+#             */
/*   Updated: 2017/04/13 14:49:24 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	tmp_dst[len];

	if (len < 134217728)
	{
		ft_memcpy(tmp_dst, (unsigned char*)src, len);
		ft_memcpy(dst, tmp_dst, len);
		return (dst);
	}
	return (NULL);
}
