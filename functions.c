/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:32:27 by notraore          #+#    #+#             */
/*   Updated: 2019/03/27 17:33:22 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				reset_model(t_glenv *env)
{
	env->scaling = 9.0f;
	env->rotx = 0.0f;
	env->roty = 0.0f;
	env->rotz = 0.0f;
	env->new_pos.x = 0.0f;
	env->new_pos.y = 0.0f;
	env->new_pos.z = -50.0f;
	env->fov = 45.0f;
}

void				end_program(t_glenv *env)
{
	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	glfwDestroyWindow(env->window);
	glfwTerminate();
}

void				framebuffer_size_callback(GLFWwindow *window,
					int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void				auto_roty(t_glenv *env)
{
	env->roty += 0.2f;
}

double				degree_to_radian(double degree_angle)
{
	return (degree_angle * ((float)PI / 180.0));
}
