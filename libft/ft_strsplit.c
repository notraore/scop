/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:48:29 by notraore          #+#    #+#             */
/*   Updated: 2017/04/12 12:48:40 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		nb;
	char	**tab;

	if (!s || !c)
		return (NULL);
	nb = ft_strcount(s, c);
	if (!(tab = ft_memalloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	tab = ft_split(s, c, tab);
	tab[nb] = NULL;
	return (tab);
}
