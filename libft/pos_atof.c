/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:38:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/27 18:38:46 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		pos_atof_suite(char *str, int i, double a, bool neg)
{
	int j;

	j = 0;
	if (str[i] == '.')
	{
		++i;
		while (ft_isdigit(str[i + j]))
			j++;
		if (neg)
			a = a - (double)ft_atoi(str + i) / (pow(10, j));
		else
			a = a + (double)ft_atoi(str + i) / (pow(10, j));
	}
	return (a);
}

int			pos_parse(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return (0);
	while (ft_isdigit(str[++i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

double		pos_atof(char *str, float *stock)
{
	int		i;
	double	a;
	bool	neg;
	int		fail;

	i = 0;
	a = 0;
	fail = 0;
	neg = false;
	if (!pos_parse(str))
		fail++;
	if (str[i] == '-')
		neg = true;
	a = (double)ft_atoi(str + i);
	while (str[i] != '.' && (ft_isdigit(str[i]) || str[i] == ' '
	|| str[i] == '-'))
		i++;
	*stock = pos_atof_suite(str, i, a, neg);
	return (fail > 0 ? 0 : 1);
}
