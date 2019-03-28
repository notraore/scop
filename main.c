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

#define STB_IMAGE_IMPLEMENTATION
#include "scop.h"

int					parse_vertex(t_glenv *env)
{
	if (env->line[0] == 'v' && env->line[1] == ' ')
	{
		if (!ft_atof(env->split[1], &env->v_v[env->vtx_nbr])
			|| !ft_atof(env->split[2], &env->v_v[env->vtx_nbr + 1])
			|| !ft_atof(env->split[3], &env->v_v[env->vtx_nbr + 2]))
			return (0);
		env->vtx_nbr += 3;
	}
	else if (env->line[0] == 'v'
		&& env->line[1] == 't' && env->line[2] == ' ')
	{
		if (!ft_atof(env->split[1], &env->v_uv[env->vt])
			|| !ft_atof(env->split[2], &env->v_uv[env->vt + 1]))
			return (0);
		env->vt += 2;
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
		parse_vertex(env);
		if (env->line[0] == 'f')
		{
			if (tab_len(env->split) > 3)
				env->nb_faces = tab_len(env->split) - 1;
			if (!store_faces(env))
				return (0);
			env->face_nbr++;
		}
		free(env->line);
		free_tab(env->split);
	}
	return (1);
}

int					main(int argc, char **argv)
{
	t_glenv		env;

	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	init_glversion();
	ft_bzero(&env, sizeof(env));
	if (argc == 2)
		if (!parse_obj(&env, argv[1]))
			ft_kill("Error parser.");
	env_shader_texture_vertices_var(&env);
	while (!glfwWindowShouldClose(env.window))
	{
		input_key3(&env);
		print_fps_counter(&env);
		glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render(&env);
		glfwPollEvents();
	}
	end_program(&env);
	return (0);
}
