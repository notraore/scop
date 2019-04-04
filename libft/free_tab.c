/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <notraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:25:26 by notraore          #+#    #+#             */
/*   Updated: 2017/10/19 11:41:22 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void		free_itab(int **itab)
{
	int i;

	i = 0;
	while (itab[i])
	{
		free(itab[i]);
		itab[i] = NULL;
		i++;
	}
	free(itab);
	itab = NULL;
}

void		free_ftab(float **ftab)
{
	int i;

	i = 0;
	while (ftab[i])
	{
		free(ftab[i]);
		ftab[i] = NULL;
		i++;
	}
	free(ftab);
	ftab = NULL;
}
