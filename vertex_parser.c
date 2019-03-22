/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/22 14:21:12 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			parse_vertex(t_glenv *env)
{
	if (env->line[0] == 'v' && env->line[1] == ' ')
	{
		if (!ft_atof(env->split[1], &env->v_v[env->vtx_nbr])
			|| !ft_atof(env->split[2], &env->v_v[env->vtx_nbr + 1])
				|| !ft_atof(env->split[3], &env->v_v[env->vtx_nbr + 2]))
			return (0);
		env->vtx_nbr += 3;
	}
	else if (env->line[0] == 'v' && env->line[1] == 't' && env->line[2] == ' ')
	{
		if (!ft_atof(env->split[1], &env->v_uv[env->vt])
			|| !ft_atof(env->split[2], &env->v_uv[env->vt + 1]))
			return (0);
		env->vt += 2;
	}
	return (1);
}

int			parse_obj(t_glenv *env, char *srcpath)
{
	int	v;
	int	vn;

	v = 0;
	vn = 0;
	env->vtx_nbr = 0;
	env->fd = open(srcpath, O_RDONLY);
	if (env->fd == -1)
		ft_kill("Open error");
	while (get_next_line(env->fd, &env->line))
	{
		env->split = ft_strsplit(env->line, ' ');
		parse_vertex(env);
		if (env->line[0] == 'f')
		{
			if (tab_len(env->split) > 5)
				return (0);
			env->four = (env->split[4]) ? true : false;
			if (!store_faces(env))
				return (0);
			env->face_nbr++;
		}
		free_tab(env->split);
	}
	return (1);
}
