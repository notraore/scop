/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:47:05 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:48:01 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	char			*str_new;
	unsigned int	count;

	str = (char *)s;
	if (str && f)
	{
		count = 0;
		if (!(str_new = malloc(ft_strlen(str) + 1)))
			return (NULL);
		while (str[count])
		{
			str_new[count] = f(str[count]);
			count++;
		}
		str_new[count] = '\0';
		return (str_new);
	}
	return (NULL);
}
