/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:15:07 by arive-de          #+#    #+#             */
/*   Updated: 2017/07/24 10:05:09 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}