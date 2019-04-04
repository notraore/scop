/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/14 11:32:37 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					parse_vertex(t_glenv *env)
{
	if (env->line[0] == 'v' && env->line[1] == ' ')
	{
		if (env->split[1] && env->split[2] && env->split[3])
		{
			if (!ft_atof(env->split[1], &env->v_v[env->vtx_nbr]))
				if (!my_atoi(env->split[1], (int*)&env->v_v[env->vtx_nbr]))
					return (0);
			if (!ft_atof(env->split[2], &env->v_v[env->vtx_nbr + 1]))
				if (!my_atoi(env->split[2], (int*)&env->v_v[env->vtx_nbr + 1]))
					return (0);
			if (!ft_atof(env->split[3], &env->v_v[env->vtx_nbr + 2]))
				if (!my_atoi(env->split[3], (int*)&env->v_v[env->vtx_nbr + 2]))
					return (0);
		}
		else
			ft_kill("Missing vertex point");
		env->vtx_nbr += 3;
	}
	return (1);
}

int					parse_indice(t_glenv *env)
{
	if (env->line[0] == 'f' && env->line[1] == ' ')
	{
		if (tab_len(env->split) > 3)
			env->nb_faces = tab_len(env->split) - 1;
		if (!store_faces(env))
			return (0);
		env->face_nbr++;
	}
	return (1);
}

int					parse_obj(t_glenv *env, char *srcpath)
{
	env->vtx_nbr = 0;
	env->fd = open(srcpath, O_RDONLY);
	if (env->fd == -1)
		ft_kill("Open error");
	while (get_next_line(env->fd, &env->line))
	{
		env->split = ft_strsplit(env->line, ' ');
		if (!parse_vertex(env))
			return (0);
		if (!parse_indice(env))
			return (0);
		free(env->line);
		free_tab(env->split);
	}
	return (1);
}

void				parse_file(t_glenv *env, char *srcpath)
{
	env->fd = open(srcpath, O_RDONLY);
	if (env->fd == -1)
		ft_kill("Open error");
	while (get_next_line(env->fd, &env->line))
	{
		if (env->line[0] == 'v' && env->line[1] == ' ')
		{
			env->tmp_vertex += 3;
			env->texcor += 2;
		}
		else if (env->line[0] == 'f' && env->line[1] == ' ')
		{
			env->tab_tmp = ft_strsplit(env->line, ' ');
			if (tab_len(env->tab_tmp) <= 3)
				ft_kill("faces must have a minimum of 3 indices.");
			if (tab_len(env->tab_tmp) == 3 || tab_len(env->tab_tmp) == 4)
				env->ind_alloc += (tab_len(env->tab_tmp) - 1);
			else
				env->ind_alloc += (tab_len(env->tab_tmp) - 3) * 3;
			free_tab(env->tab_tmp);
		}
		free(env->line);
	}
	env->ver_alloc = (env->tmp_vertex * 2) + env->texcor;
	malloc_tabs(env);
}
