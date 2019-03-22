/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/22 14:59:13 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STB_IMAGE_IMPLEMENTATION
#include "scop.h"

void				end_program(t_glenv *env)
{
	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	glfwDestroyWindow(env->window);
	glfwTerminate();
}

void				framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

int					unite_all(t_glenv *env, bool tpressed)
{
	int			index;
	int			face_i;
	int			tex_i;
	int			nbr;
	int		clr;

	clr = 0;

	nbr = 1;
	srand((unsigned int)time(NULL));

	index = 0;
	face_i = 0;
	tex_i = 0;
	// printf("vtx_nbr = %d\n", env->vtx_nbr);
	// env->vertices = {0};
	while (index < env->vtx_nbr * 8)
	{
		env->vertices[index] = (env->v_v[face_i]);
		env->vertices[index + 1] = (env->v_v[face_i + 1]);
		env->vertices[index + 2] = (env->v_v[face_i + 2]);

		if (clr >= 0 && clr <= 2)
		{
			env->vertices[index + 3] = 1;
			env->vertices[index + 4] = 0;
			env->vertices[index + 5] = 0;
		// 	printf("red\n");
		}
		else if (clr >= 3 && clr <= 5)
		{
			env->vertices[index + 3] = 0;
			env->vertices[index + 4] = 1;
			env->vertices[index + 5] = 0;
		// 	printf("green\n");
		}
		else if (clr >= 6 && clr <= 8)
		{
			env->vertices[index + 3] = 0;
			env->vertices[index + 4] = 0;
			env->vertices[index + 5] = 1;
		}
		clr++;
		if (clr == 9)
			clr = 0;

		// env->vertices[index + 3] = 0.5;
		// env->vertices[index + 4] = 0.5;
		// env->vertices[index + 5] = 0.5;
		// printf("ver[0] = %f || ver[1] = %f || ver[3] = %f\n", env->vertices[face_i], env->vertices[face_i + 1], env->vertices[face_i + 2]);
		index += 8;
		face_i += 3;
	}
	index = 0;
	face_i = 0;
	((void)tpressed);
	if (tpressed)
		while (index < 29 * 8)
		{
			env->vertices[index + 6] = env->v_uv[tex_i];
			env->vertices[index + 7] = env->v_uv[tex_i + 1];
			index += 8;
			tex_i += 2;
			// printf("uv[0] = %f || uv[1] = %f\n", env->v_uv[tex_i], env->v_uv[tex_i + 1]);
		}
	// 	else
	// 		return 0;
	return (0);
}

void				win_update(void *f(float), GLFWwindow *win)
{
	double last;
	double now;
	double delta;

	delta = 0.01f;
	last = glfwGetTime();
	(*f)(delta);
	glfwSwapBuffers(win);
	glfwPollEvents();
	now = glfwGetTime();
	delta = (now - last) * 10.0f;
}

void				auto_roty(t_glenv *env)
{
	env->roty += 0.2f;
}


void				generate_buff_arr(t_glenv *env)
{
	glGenVertexArrays(1, &env->vao);
	glGenBuffers(1, &env->vbo);
	glGenBuffers(1, &env->ebo);
	glBindVertexArray(env->vao);
}

void				vertices_setter(t_glenv *env)
{
	generate_buff_arr(env);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(env->indices), env->indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(env->vertices), env->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void				init_glversion(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);
}

void				render(t_glenv *env)
{
	env->transform = create_mat4(1.0f);
	env->scale = create_mat4(1.0f);
	env->rotate[0] = create_mat4(1.0f);
	env->rotate[1] = create_mat4(1.0f);
	env->rotate[2] = create_mat4(1.0f);
	env->rotate[0] = make_rot_x(env->rotx);
	env->rotate[1] = make_rot_y(env->roty);
	env->rotate[2] = make_rot_z(env->rotz);
	env->trans = make_translation(&env->new_pos);
	env->scale = matrix_scale(env->scaling);
	env->transform = m4_x_m4(&env->transform, &env->proj);
	env->transform = m4_x_m4(&env->transform, &env->trans);
	env->transform = m4_x_m4(&env->transform, &env->rotate[0]);
	env->transform = m4_x_m4(&env->transform, &env->rotate[1]);
	env->transform = m4_x_m4(&env->transform, &env->rotate[2]);
	env->transform = m4_x_m4(&env->transform, &env->scale);
	if (env->autorotate)
		auto_roty(env);
	glUseProgram(env->program);
	env->transform_loc = glGetUniformLocation(env->program, "mvp");
	glUniformMatrix4fv(env->transform_loc, 1, GL_FALSE, &env->transform.m[0][0]);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glBindVertexArray(env->vao);
	glDrawElements(GL_TRIANGLES, env->indices_nbr, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(env->window);
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
	while (i < env.vtx_nbr * 3)
		i += 3;
	env_shader_texture_vertices_var(&env);
	while (!glfwWindowShouldClose(env.window))
	{
		input_key(&env);
		print_fps_counter(&env);
		glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_MULTISAMPLE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glDisable(GL_LIGHTING);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glActiveTexture(GL_TEXTURE0);
		render(&env);
		glfwPollEvents();
	}
	end_program(&env);
	return (0);
}
