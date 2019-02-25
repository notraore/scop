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

int					main(int argc, char **argv)
{
	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	// GLFWwindow *env.window;
	t_glenv		env;

	env.window = glfwCreateWindow(480, 480, "Scop - 42", NULL, NULL);
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
	float		vertex[126];
	t_vtx		xyz[42];
	int			nbr = 0;
	float		color[3] = {0.5, 1, 0.5};

	int			fd;
	int			i = 0;
	int			ver = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v')
		{
			split = ft_strsplit(line, ' ');
			xyz[ver].x = ft_atod(split[1]);
			xyz[ver].y = ft_atod(split[2]);
			xyz[ver].z = ft_atod(split[3]);
			// printf("xyz[0] = %f || xyz[1] = %f || xyz[2] = %f\n", xyz[ver].x, xyz[ver].y, xyz[ver].z);
			ver++;
			// vertex[i] = ft_atof(split[1]);
			// i++;
			// vertex[i] = ft_atof(split[2]);
			// i++;
			// vertex[i] = ft_atof(split[3]);
			// i++;
			// printf("split[0] = %s || split[1] = %s || split[2] = %s || split[3] = %s\n", split[0], split[1], split[2], split[3]);
			// printf("vertex[0] = %f || vertex[1] = %f || vertex[2] = %f\n", vertex[i - 3], vertex[i - 2], vertex[i - 1]);
		}
		else if (line[0] == 'f')
		{
			split = ft_strsplit(line, ' ');

			if (split[4])
			{
				while (nbr < 4)
				{
					vertex[i] = xyz[ft_atoi(split[1])].x;
					// printf("ver[ver] = %f ", xyz[ft_atoi(split[1])].x);
					vertex[i + 1] = xyz[ft_atoi(split[1])].y;
					// printf("ver[ver] = %f ", xyz[ft_atoi(split[1])].y);
					vertex[i + 2] = xyz[ft_atoi(split[1])].z;
					// printf("ver[ver] = %f\n", xyz[ft_atoi(split[1])].z);
					nbr++;
				}

				vertex[i + 3] = xyz[ft_atoi(split[1])].x;
				vertex[i + 4] = xyz[ft_atoi(split[3])].y;
				vertex[i + 5] = xyz[ft_atoi(split[4])].z;
				i += 6;
				// printf("Four || i = %d\n", i);
			}
			else
			{
				vertex[i] = xyz[ft_atoi(split[3])].x;
				vertex[i + 1] = xyz[ft_atoi(split[3])].y;
				vertex[i + 2] = xyz[ft_atoi(split[3])].z;
				i += 3;
			}
			// printf("line = %s\n", line);
		}
	}
	// ver = 0;
	// while (ver < i)
	// {
	// 	printf("vertex[%d] = %f\n", ver, vertex[ver]);
	// 	ver++;
	// }
	last_time = glfwGetTime();
	frames = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		current_time = glfwGetTime();
		frames++;
		if (current_time - last_time >= 0.2f)
		{
			ft_putnbr(frames);
			ft_putendl(" FPS");
			frames = 0;
			last_time += 1.0;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetFramebufferSize(env.window, &env.width, &env.height);
		env.ratio = env.width / (double)env.height;
		glViewport(0, 0, env.width, env.height);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertex);
		glEnableVertexAttribArray(0);
		// color[0] = fmod(color[0] + 0.001, 1);
		// color[1] = fmod(color[1]+ 0.002, 1);
		// color[2] = fmod(color[2] + 0.003, 1);
		// glColor3f(color[0], color[1], color[2]);
		// glRotatef(0.5, 0, 1, 0);
		// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, color);
		// glEnableVertexAttribArray(1);
		glDrawArrays(GL_TRIANGLES, 0, 42);
		// glDrawArrays(GL_TRIANGLES, 0, 42);

		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return 0;
}
