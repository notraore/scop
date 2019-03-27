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

int					store_faces(t_glenv *env)
{
	int i;
	int tmp;
	char **tab;

	i = 1;
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		if (pos_atoi(env->split[i], &env->indices[env->ind]))
		{
			env->indices[env->ind] -= 1;
		}
		else
		{
			if (ft_isdigit(env->split[1][0]) && (ft_count_c(env->split[i], '/') == 1 || ft_count_c(env->split[i], '/') == 2))
			{
				tab = ft_strsplit(env->split[i], '/');

				if (tab_len(tab) != 2 && tab_len(tab) != 3)
				{
					free(tab);
					return (0);
				}
				if (tab_len(tab) == 2 && pos_atoi(tab[0], &env->indices[env->ind]) && pos_atoi(tab[1], &env->textures[env->ind]))
				{
					env->indices[env->ind] -= 1;
					env->textures[env->ind] -=1;
					if (!ft_isdigit(env->split[1][ft_strlen(env->split[1]) - 1]))
					{
						free(tab);
						return (0);
					}
				}
				else if (tab_len(tab) == 3 && pos_atoi(tab[0], &env->indices[env->ind]) && pos_atoi(tab[1], &env->textures[env->ind]) && pos_atoi(tab[2], &env->normales[env->ind]))
				{
					env->indices[env->ind] -= 1;
					env->textures[env->ind] -= 1;
					env->normales[env->ind] -= 1;
					if (!ft_isdigit(env->split[2][ft_strlen(env->split[2]) - 1]))
					{
						free(tab);
						return (0);
					}
				}
				else
				{
					free(tab);
					return 0;
				}
				free(tab);
			}
			else
				return (0);				
		}
		env->ind++;
		i++;
	}
	i = 1;
	if (env->four == true)
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
	env->indices_nbr += 3;
	return (1);
}

int					parse_obj(t_glenv *env, char *srcpath)
{
	int 	v;
	int 	vn;

	v = 0;
	vn = 0;
	env->vtx_nbr = 0;
	// srand((unsigned int)time(NULL));

	// float nbr = 255;
	env->fd = open(srcpath, O_RDONLY);
	if (env->fd == -1)
		ft_kill("Open error");
	while (get_next_line(env->fd, &env->line))
	{
		env->split = ft_strsplit(env->line, ' ');
		if (env->line[0] == 'v' && env->line[1] == ' ')
		{
			if (!ft_atof(env->split[1], &env->v_v[env->vtx_nbr]) || !ft_atof(env->split[2], &env->v_v[env->vtx_nbr + 1]) || !ft_atof(env->split[3], &env->v_v[env->vtx_nbr + 2]))
			{
				return (0);
			}

			// printf("v0 = %f || v1 = %f || v2 = %f\n", env->v_v[v], env->v_v[v + 1], env->v_v[v + 2]);
			env->vtx_nbr += 3;
		}
		else if (env->line[0] == 'v' && env->line[1] == 't' && env->line[2] == ' ')
		{
			if (!ft_atof(env->split[1], &env->v_uv[env->vt]) || !ft_atof(env->split[2], &env->v_uv[env->vt + 1]))
			{
				return (0);
			}
			// printf("split0 = %s || split2 = %s\n", env->split[1], env->split[2]);
			// printf("v0 = %f || v1 = %f || v2 = %f\n", env->v_uv[vt], env->v_uv[vt + 1], env->v_uv[vt + 2]);
			env->vt += 2;
		}
		else if (env->line[0] == 'f')
		{
			if (tab_len(env->split) > 5)
			{

				return (0);
			}
			if (env->split[4])
				env->four = true;
			else
				env->four = false;
			if (!store_faces(env))
			{
				return (0);
			}
			env->face_nbr++;
		}
		else if (env->line[0] == 's')
		{
			if (tab_len(env->split) > 2)
				return (0);
			if (ft_strcmp(env->split[1], "1") == 0)
			{
			}
			else if (ft_strcmp(env->split[1], "off") == 0)
			{

			}
			else
			{
				return (0);
			}
		}
		free_tab(env->split);
	}
	return (1);
}

int					main(int argc, char **argv)
{
	t_glenv		env;
	int			i;

	i = 0;
	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	init_glversion();
	ft_bzero(&env, sizeof(env));
	if (argc == 2)
		if (!parse_obj(&env, argv[1]))
			ft_kill("Error parser.");
	i = env.vtx_nbr * 3;
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
