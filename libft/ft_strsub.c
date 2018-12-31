/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:48:49 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:48:51 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str_new;
	unsigned int	count;

	if (!(str_new = ft_strnew(len)) || (!s))
		return (NULL);
	str = (char *)s;
	count = 0;
	while (count < len)
	{
		str_new[count] = str[start];
		start++;
		count++;
	}
	return (str_new);
}
