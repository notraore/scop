/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:26:12 by notraore          #+#    #+#             */
/*   Updated: 2019/02/18 21:14:52 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				win_update(void *f(float), GLFWwindow *win)
{
	double last;
	double now;
	double delta = 0.01f;

	last = glfwGetTime();
	(*f)(delta);
	glfwSwapBuffers(win);
	glfwPollEvents();

	now = glfwGetTime();
	delta = (now - last) * 10.0f;
}

void				update_triangle(double *triangl, bool *res)
{
	if (*triangl >= 1)
		*res = 1;
	else if (*triangl <= -1)
		*res = 0;
	if (*res == 0)
		*triangl += 0.005;
	else if (*res == 1)
		*triangl -= 0.005;
}

void				init_glversion(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

// t_mat4				setup_camera()
// {
// 	t_mat4		new;

// 	t_mat4		proj;
// 	t_mat4		view;
// 	t_mat4		model;

// 	view = 


// 	return (new);
// }

void				add_movement(float *value, t_vec3 xyz, int i)
{
	int		count;

	count = 0;
	while (count < i)
	{
		value[count] += xyz.x;
		// value[count + 1] += xyz.y;
		// value[count + 2] += xyz.z;
		count++;
	}
}

int					main(int argc, char **argv)
{
	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	t_glenv		env;

	env.window = glfwCreateWindow(980, 980, "Scop - 42", NULL, NULL);
	if (!env.window)
		ft_kill("Can't create window.");

	glfwMakeContextCurrent(env.window);
	glfwSwapInterval(1);
	double triangl = 1;
	bool res = 0;
	double		current_time;
	double		last_time;
	int			frames;
	char		*line;
	char		**split;
	// float		*vertex;
	float		vertex[200000];
	t_vec3		xyz[200000];
	int			nbr = 0;

	int		fd;
	int		i = 0;
	int		ver = 0;
	int		times = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		if (line[0] == 'v')
		{
			xyz[times].x = ft_atod(split[1]);
			xyz[times].y = ft_atod(split[2]);
			xyz[times].z = ft_atod(split[3]);
			times++;
		}
		else if (line[0] == 'f')
		{
			nbr = 1;
			while (nbr < 4)
			{
				vertex[i] = xyz[ft_atoi(split[nbr]) - 1].x;
				vertex[i + 1] = xyz[ft_atoi(split[nbr]) - 1].y;
				vertex[i + 2] = xyz[ft_atoi(split[nbr]) - 1].z;
				i += 3;
				nbr++;
			}
			nbr = 1;
			if (split[4])
			{
				while (nbr < 5)
				{
					vertex[i] = xyz[ft_atoi(split[nbr]) - 1].x;
					vertex[i + 1] = xyz[ft_atoi(split[nbr]) - 1].y;
					vertex[i + 2] = xyz[ft_atoi(split[nbr]) - 1].z;
					i += 3;
					nbr++;
					if (nbr == 2)
						nbr = 3;
				}
				nbr--;
				vertex[i] = xyz[ft_atoi(split[nbr]) - 1].x;
				vertex[i + 1] = xyz[ft_atoi(split[nbr]) - 1].y;
				vertex[i + 2] = xyz[ft_atoi(split[nbr]) - 1].z;
				i += 3;
			}
			free_tab(split);
			free(line);
		}
	}
	// printf("times = [%d]\n", times);
	i--;
	printf("i = [%d]\n", i);
	ver = 0;
	// while (ver < i)
	// {
	// 	printf("vertex[%d] = %f || vertex[%d] = %f || vertex[%d] = %f\n", ver, vertex[ver], ver + 1, vertex[ver + 1], ver + 2, vertex[ver + 2]);
	// 	ver +=3 ;
	// }
	last_time = glfwGetTime();
	frames = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		current_time = glfwGetTime();
		frames++;
		if (current_time - last_time >= 0.2f)
		{
			// ft_putnbr(frames);
			// ft_putendl(" FPS");
			frames = 0;
			last_time += 1.0;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetFramebufferSize(env.window, &env.width, &env.height);
		env.ratio = env.width / (double)env.height;
		glViewport(0, 0, env.width, env.height);

		// unsigned int		buffer;
		// glGenBuffers(1, &buffer);
		// glBindBuffer(GL_ARRAY_BUFFER, buffer);
		// glBufferData(GL_ARRAY_BUFFER, 42*3, vertex, GL_STATIC_DRAW);

		// glBindBuffer(GL_ARRAY_BUFFER, buffer);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertex);

		// color[0] = fmod(color[0] + 0.001, 1);
		// color[1] = fmod(color[1]+ 0.002, 1);
		// color[2] = fmod(color[2] + 0.003, 1);
		// glColor3f(color[0], color[1], color[2]);
		glRotatef(0.25, 0, -1, 0);
		// glRotatef(0.35, 1, 1, 1);
		// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, color);
		// glEnableVertexAttribArray(1);
		// glDrawArrays(GL_POINTS, 0, i / 3);
		// glDrawArrays(GL_LINE_STRIP, 0, i/3);
		// glDrawArrays(GL_QUADS, 0, i / 3);
		glDrawArrays(GL_TRIANGLES, 0, 42*6);
		// glDrawArrays(GL_TRIANGLE_FAN, 0, i / 3);
		// glDrawArrays(GL_TRIANGLE_STRIP, 0, i / 3);
		// add_movement(vertex, create_tvec3(0.001, 0, 0), i);
		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	// t_mat4		trans_cube = translation_mat4(create_tvec3(16, 0, 0));
	// t_vec4		cube = create_tvec4(10, 10, 10, 1);
	// cube = mult_mat4_vec4(trans_cube, cube);
	// print_vec4(cube);
	// print_mat4(scale_mat4(create_tvec3(10, 10, 10)));
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return 0;
}
