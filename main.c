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

// void				scop_loop(double delta)
// {
// 	glClearColor(0.5f , 0.5f, 0.5f, 1);
// 	glClear(GL_COLOR_BUFFER_BIT);
// }


void				update_triangle(double *triangl, bool *res)
{
	if (*triangl >= 1)
		*res = 1;
	else if (*triangl <= -1)
		*res = 0;
	if (*res == 0)
		*triangl += 0.0005;
	else if (*res == 1)
		*triangl -= 0.0005;
}

int					main(void)
{
	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	// GLFWwindow *env.window;
	t_glenv		env;

	env.window = glfwCreateWindow(480, 480, "Scop - 42", NULL, NULL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!env.window)
		ft_kill("Can't create window.");

	glfwMakeContextCurrent(env.window);
	glfwSwapInterval(1);
	double triangl = 1;
	bool res = 0;
	double		current_time;
	double		last_time;
	int			frames;
	float couleurs[] = {1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0};

	last_time = glfwGetTime();
	frames = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		current_time = glfwGetTime();
		frames++;
		if (current_time - last_time >= 0.2f)
		{
			printf("%d fps\n", frames);
			frames = 0;
			last_time += 1.0;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetFramebufferSize(env.window, &env.width, &env.height);
		env.ratio = env.width / (double)env.height;
		glViewport(0, 0, env.width, env.height);

		glBegin(GL_TRIANGLES);

		glVertex3d(0, 0, 0);
		glVertex3d(triangl, 0, 0);
		glVertex3d(0, triangl, 0);

		update_triangle(&triangl, &res);
		glEnd();

		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	glfwDestroyWindow(env.window);
	glfwTerminate();
	return 0;
}
