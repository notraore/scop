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

void				malloc_tabs(t_glenv *env)
{
	if (!(env->vertices = (float*)malloc(sizeof(float) * env->ver_alloc)))
		ft_kill("Couldn't allocate memory for vertices");
	if (!(env->v_v = (float*)malloc(sizeof(float) * env->ver_alloc)))
		ft_kill("Couldn't allocate memory for vertices");
	if (!(env->indices = (unsigned int*)malloc(sizeof(unsigned int)
	* env->ind_alloc)))
		ft_kill("Couldn't allocate memory for faces");
}

int					is_regular_file(const char *path)
{
	struct stat path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

void				ft_help(void)
{
	ft_putendl("'W', 'A', 'S', 'D' to move camera in space.");
	ft_putendl("Lift up and down 'Q' and 'E'.");
	ft_putendl("'K', 'L', ';' to switch between \
	filled, point and wireframe vertex.");
	ft_putendl("'G' to increase 'G' to decrease texture alpha.");
	ft_putendl("'R' toggle autorotate.");
	ft_putendl("'U' to reset obj to initial position.");
	ft_putendl("'Z' and 'X' to scale obj on screen.");
	ft_putendl("'I', 'O', 'P' to rotate on X, Y and Z axis.");
	ft_putendl("Toggle transparency with 'N' and 'M'.");
	ft_putendl("Change color mode with 'LEFT' and 'RIGHT'.");
	ft_putendl("Change between flat and smooth mode with 'UP' and 'DOWN'.");
	ft_kill("\n./scop [file.obj]");
}

void				error(char *str)
{
	if (!is_regular_file(str))
		ft_kill("Dont try to use directory to render.");
	if (!glfwInit())
		ft_kill("Can't init GLFW.");
}

int					main(int argc, char **argv)
{
	t_glenv		env;

	if (argc != 2)
		ft_help();
	error(argv[1]);
	ft_bzero(&env, sizeof(env));
	parse_file(&env, argv[1]);
	init_glversion();
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
