/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:44:00 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:50:58 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pointer;

	pointer = NULL;
	if (size)
	{
		if (!(pointer = (void *)malloc(sizeof(void) * size)))
			return (NULL);
		ft_bzero(pointer, size);
	}
	return ((void *)pointer);
}
