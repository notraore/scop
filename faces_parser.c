/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:32:16 by notraore          #+#    #+#             */
/*   Updated: 2019/04/02 00:11:22 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					stock_decrem(t_glenv *env, int part)
{
	if (part == 1)
	{
		env->indices[env->ind] -= 1;
		if (!ft_isdigit(env->split[1][ft_strlen(env->split[1]) - 1]))
			return (0);
	}
	else if (part == 2)
	{
		env->indices[env->ind] -= 1;
		if (!ft_isdigit(env->split[2][ft_strlen(env->split[2]) - 1]))
			return (0);
	}
	return (1);
}

int					parse_faces2(t_glenv *env, int i)
{
	unsigned int	tmp;

	env->tab = ft_strsplit(env->split[i], '/');
	if (tab_len(env->tab) == 2 && pos_atoi(env->tab[0], &env->indices[env->ind])
		&& pos_atoi(env->tab[1], &tmp))
		return (stock_decrem(env, 1) ? 1 : 0);
	else if (tab_len(env->tab) == 3 && pos_atoi(env->tab[0],
	&env->indices[env->ind])
		&& pos_atoi(env->tab[1], &tmp)
		&& pos_atoi(env->tab[2], &tmp))
		return (stock_decrem(env, 2) ? 1 : 0);
	else
	{
		free_tab(env->tab);
		return (0);
	}
	return (1);
}

int					parse_faces(t_glenv *env, int i)
{
	if (ft_isdigit(env->split[1][0])
		&& (ft_count_c(env->split[i], '/') == 1
			|| ft_count_c(env->split[i], '/') == 2))
	{
		if (!parse_faces2(env, i))
		{
			free_tab(env->tab);
			return (0);
		}
	}
	else
		return (0);
	free_tab(env->tab);
	return (1);
}

void				parse_multiple_faces(t_glenv *env, int tmp, int i, int n)
{
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		if (n % 3 == 0)
			env->indices[env->ind] = ft_atoi(env->split[1]) - 1;
		else
			env->indices[env->ind] = ft_atoi(env->split[i + 1]) - 1;
		env->ind++;
		i++;
		n++;
	}
	env->indices_nbr += 3;
}

int					store_faces(t_glenv *env)
{
	int i;
	int tmp;
	int n;

	i = 1;
	tmp = env->ind + 3;
	if (!env->split[1] && env->split[2] && env->split[3])
	{
		while (env->ind < tmp)
		{
			if (pos_atoi(env->split[i], &env->indices[env->ind]))
				env->indices[env->ind] -= 1;
			else if (!parse_faces(env, i))
				return (0);
			env->ind++;
			i++;
		}
		i = 1;
		n = 0;
		while (env->nb_faces - 3 > 0)
		{
			parse_multiple_faces(env, tmp, i, n);
			i++;
			env->nb_faces -= 1;
		}
		env->indices_nbr += 3;
	}
	else
		ft_kill("Faces must have a minimum of 3 vertex points.");
	return (1);
}
