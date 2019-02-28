/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:44:45 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:44:50 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*str;

	str = (char *)b;
	if (len == 0)
		return (str);
	count = 0;
	while (count < len)
	{
		str[count] = (char)c;
		count++;
	}
	return (b);
}
