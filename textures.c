/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:33:03 by notraore          #+#    #+#             */
/*   Updated: 2019/03/27 17:33:26 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				apply_texture(t_glenv *env, int all)
{
	int				index;

	index = 0;
	while (index < all)
	{
		env->vertices[index + 6] = 0.0f;
		env->vertices[index + 7] = 0.0f;
		index += 8;
		env->vertices[index + 6] = 0.0f;
		env->vertices[index + 7] = 1.0f;
		index += 8;
		env->vertices[index + 6] = 1.0f;
		env->vertices[index + 7] = 1.0f;
		index += 8;
		env->vertices[index + 6] = 1.0;
		env->vertices[index + 7] = 0.0;
		index += 8;
	}
}

void				separate_texture(t_glenv *env)
{
	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	env->data = parse_bmp("texture/texture.bmp", env);
}

void				load_texture(t_glenv *env)
{
	if (env->data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0,
			GL_RGB, env->tex_width, env->tex_height, 0,
		GL_RGB, GL_UNSIGNED_BYTE, env->data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		ft_putendl("Failed to load the texture.");
	free(env->data);
}
