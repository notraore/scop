/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:20:43 by arive-de          #+#    #+#             */
/*   Updated: 2019/03/22 15:20:54 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				moves(t_glenv *env)
{
	if (glfwGetKey(env->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->window, true);
	else if (glfwGetKey(env->window, GLFW_KEY_E) == GLFW_PRESS)
		env->new_pos.y += 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_Q) == GLFW_PRESS)
		env->new_pos.y -= 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_D) == GLFW_PRESS)
		env->new_pos.x -= 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_A) == GLFW_PRESS)
		env->new_pos.x += 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_W) == GLFW_PRESS)
		env->new_pos.z += 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_S) == GLFW_PRESS)
		env->new_pos.z -= 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_I) == GLFW_PRESS)
		env->rotx += 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_O) == GLFW_PRESS)
		env->roty += 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_P) == GLFW_PRESS)
		env->rotz += 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_X) == GLFW_PRESS)
		env->scaling += 0.1;
	else if (glfwGetKey(env->window, GLFW_KEY_Z) == GLFW_PRESS)
		env->scaling -= 0.1;
}

void				reset(t_glenv *env)
{
	if (glfwGetKey(env->window, GLFW_KEY_U) == GLFW_PRESS)
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
}

void				input_key(t_glenv *env)
{
	moves(env);
	if (glfwGetKey(env->window, GLFW_KEY_T) == GLFW_PRESS)
	{
		if (env->tpressed == true)
			env->tpressed = false;
		else if (env->tpressed == false)
			env->tpressed = true;
		env_shader_texture_vertices_var(env);
	}
	else if (glfwGetKey(env->window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (env->autorotate == false)
			env->autorotate = true;
		else
			env->autorotate = false;
	}
	else if (glfwGetKey(env->window, GLFW_KEY_F) == GLFW_PRESS)
	{
		if (env->framed == false)
			env->framed = true;
		else
			env->framed = false;
	}
	reset(env);
}
