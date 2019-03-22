/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/22 14:21:12 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				stock_decrem(t_glenv *env, int nb)
{
	if (nb == 1)
	{
		env->indices[env->ind] -= 1;
		env->textures[env->ind] -= 1;
		if (!ft_isdigit(env->split[1][ft_strlen(env->split[1]) - 1]))
			return (0);
	}
	else if (nb == 2)
	{
		env->indices[env->ind] -= 1;
		env->textures[env->ind] -= 1;
		if (!ft_isdigit(env->split[2][ft_strlen(env->split[2]) - 1]))
			return (0);
	}
	return (1);
}

int				parse_faces2(t_glenv *env, char **tab, int i)
{
	tab = ft_strsplit(env->split[i], '/');
	if (tab_len(tab) == 2 && pos_atoi(tab[0], &env->indices[env->ind])
		&& pos_atoi(tab[1], &env->textures[env->ind]))
		return (stock_decrem(env, 1) ? 1 : 0);
	else if (tab_len(tab) == 3 && pos_atoi(tab[0], &env->indices[env->ind])
		&& pos_atoi(tab[1], &env->textures[env->ind])
			&& pos_atoi(tab[2], &env->empty))
		return (stock_decrem(env, 2) ? 1 : 0);
	else
	{
		free(tab);
		return (0);
	}
	return (1);
}

int				parse_faces(t_glenv *env, int i)
{
	char **tab;

	tab = NULL;
	if (ft_isdigit(env->split[1][0]) && (ft_count_c(env->split[i], '/') == 1
		|| ft_count_c(env->split[i], '/') == 2))
	{
		if (!parse_faces2(env, tab, i))
		{
			free(tab);
			return (0);
		}
	}
	else
		return (0);
	return (1);
}

void			parse_4_faces(t_glenv *env, int tmp, int i)
{
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		env->indices[env->ind] = ft_atoi(env->split[i]) - 1;
		env->ind++;
		i++;
		if (i == 2)
			i = 3;
	}
	env->indices_nbr += 3;
}

int				store_faces(t_glenv *env)
{
	int i;
	int tmp;

	i = 1;
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		if (pos_atoi(env->split[i], &env->indices[env->ind]))
			env->indices[env->ind] -= 1;
		else
			parse_faces(env, i);
		env->ind++;
		i++;
	}
	i = 1;
	if (env->four == true)
		parse_4_faces(env, tmp, i);
	env->indices_nbr += 3;
	return (1);
}
