/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:59:39 by notraore          #+#    #+#             */
/*   Updated: 2017/04/13 16:59:40 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c, char **tab)
{
	int		i;
	int		taille;
	int		index;

	index = 0;
	i = 0;
	taille = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			taille = 0;
		else if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				tab[index] = ft_strsub(s, i - taille, taille + 1);
				index++;
			}
			taille++;
		}
		i++;
	}
	return (tab);
}
