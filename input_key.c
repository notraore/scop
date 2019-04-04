/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:32:40 by notraore          #+#    #+#             */
/*   Updated: 2019/03/27 17:33:15 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		input_key(t_glenv *env)
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

void		input_key2(t_glenv *env)
{
	if (glfwGetKey(env->window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (env->autorotate == false)
			env->autorotate = true;
		else
			env->autorotate = false;
	}
	else if (glfwGetKey(env->window, GLFW_KEY_L) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (glfwGetKey(env->window, GLFW_KEY_K) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else if (glfwGetKey(env->window, GLFW_KEY_SEMICOLON) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	else if (glfwGetKey(env->window, GLFW_KEY_U) == GLFW_PRESS)
		reset_model(env);
	else if (glfwGetKey(env->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		env->greymode = false;
	else if (glfwGetKey(env->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		env->greymode = true;
	else if (glfwGetKey(env->window, GLFW_KEY_M) == GLFW_PRESS)
	{
		env->alphmode = false;
		if (env->greymode == true)
			env->greymode = false;
	}
}

void		input_key3(t_glenv *env)
{
	input_key(env);
	input_key2(env);
	if (glfwGetKey(env->window, GLFW_KEY_N) == GLFW_PRESS)
		env->alphmode = true;
	else if (glfwGetKey(env->window, GLFW_KEY_UP) == GLFW_PRESS)
		env->smoothiemode = true;
	else if (glfwGetKey(env->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		env->smoothiemode = false;
	else if (glfwGetKey(env->window, GLFW_KEY_F) == GLFW_PRESS)
	{
		env->texmode = true;
		if (env->bfactormode > 0.0f)
			env->bfactormode -= 0.01;
	}
	else if (glfwGetKey(env->window, GLFW_KEY_G) == GLFW_PRESS)
	{
		if (env->bfactormode < 1.0f)
			env->bfactormode += 0.01;
		if (env->bfactormode == 1.0f)
			env->texmode = false;
	}
	else if (glfwGetKey(env->window, GLFW_KEY_Y) == GLFW_PRESS)
		env->f = (((float)rand() / (float)(RAND_MAX)) / 1);
}
