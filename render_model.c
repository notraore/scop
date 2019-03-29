/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:32:52 by notraore          #+#    #+#             */
/*   Updated: 2019/03/27 17:33:24 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				apply_grey_shader(t_glenv *env, int all)
{
	float		random;
	int			index;

	random = 0.5;
	index = 0;
	while (index < all)
	{
		env->vertices[index + 3] = (((float)rand() / (float)(RAND_MAX)) / 1);
		env->vertices[index + 4] = (((float)rand() / (float)(RAND_MAX)) / 1);
		env->vertices[index + 5] = (((float)rand() / (float)(RAND_MAX)) / 1);
		index += 8;
	}
}

int					unite_all(t_glenv *env)
{
	int			index;
	int			face_i;
	int			tex_i;
	int			clr;
	int			all;

	clr = 0;
	index = 0;
	face_i = 0;
	tex_i = 0;
	all = (env->vtx_nbr * 2) + ((env->vtx_nbr / 3) * 2);
	srand((unsigned int)time(NULL));
	// printf("vtx-nbr = %d\n", all);
	while (index < all)
	{
		env->vertices[index] = (env->v_v[face_i]);
		env->vertices[index + 1] = (env->v_v[face_i + 1]);
		env->vertices[index + 2] = (env->v_v[face_i + 2]);
		// printf("env->vertices[%d] = %f, env->vertices[%d] = %f, env->vertices[%d] = %f\n", index, env->vertices[index], index + 1, env->vertices[index + 1], index + 2, env->vertices[index + 2]);
		index += 8;
		face_i += 3;
	}
	apply_grey_shader(env, all);
	apply_texture(env, all);
	return (0);
}

void				render(t_glenv *env)
{
	reset_matrix(env);
	create_final_matrix(env);
	if (env->autorotate)
		auto_roty(env);
	glUseProgram(env->program);
	env->transform_loc = glGetUniformLocation(env->program, "mvp");
	env->greyloc = glGetUniformLocation(env->program, "greymode");
	env->texloc = glGetUniformLocation(env->program, "texmode");
	env->alphmodeloc = glGetUniformLocation(env->program, "alphmode");
	env->smoothieloc = glGetUniformLocation(env->program, "smoothie");
	env->blendloc = glGetUniformLocation(env->program, "blend");
	env->bfactorloc = glGetUniformLocation(env->program, "blendfactor");
	glUniformMatrix4fv(env->transform_loc, 1,
	GL_FALSE, &env->transform.m[0][0]);
	glUniform1i(env->greyloc, env->greymode);
	glUniform1i(env->texloc, env->texmode);
	glUniform1i(env->alphmodeloc, env->alphmode);
	glUniform1i(env->smoothieloc, env->smoothiemode);
	glUniform1i(env->blendloc, env->blendmode);
	glUniform1f(env->bfactorloc, env->bfactormode);
	glBindVertexArray(env->vao);
	glDrawElements(GL_TRIANGLES, env->indices_nbr, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(env->window);
	// glUseProgram(0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
