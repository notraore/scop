/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:46:42 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:46:47 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	char			*str;
	unsigned int	count;

	str = (char *)s;
	if (str && f)
	{
		count = 0;
		while (str[count])
		{
			(*f)(&str[count]);
			count++;
		}
	}
}
