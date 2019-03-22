/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:26:15 by arive-de          #+#    #+#             */
/*   Updated: 2019/03/22 15:26:26 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				load_texture(t_glenv *env)
{
	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	env->data = stbi_load("texture/color.jpg", \
		&env->tex_width, &env->tex_height, &env->nr_channels, 0);
	if (env->data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, env->tex_width, \
			env->tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, env->data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		ft_putendl("Failed to load the texture.");
	stbi_image_free(env->data);
}
