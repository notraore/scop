/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/13 15:41:03 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
//			A RETIRER					//
void		print_mat4(t_mat4 to_print)
{
	printf( "[%f ", to_print.m[0][0]);
	printf( "%f ", to_print.m[0][1]);
	printf( "%f ", to_print.m[0][2]);
	printf( "%f]\n", to_print.m[0][3]);
	printf( "[%f ", to_print.m[1][0]);
	printf( "%f ", to_print.m[1][1]);
	printf( "%f ", to_print.m[1][2]);
	printf( "%f]\n", to_print.m[1][3]);
	printf( "[%f ", to_print.m[2][0]);
	printf( "%f ", to_print.m[2][1]);
	printf( "%f ", to_print.m[2][2]);
	printf( "%f]\n", to_print.m[2][3]);
	printf( "[%f ", to_print.m[3][0]);
	printf( "%f ", to_print.m[3][1]);
	printf( "%f ", to_print.m[3][2]);
	printf( "%f]\n", to_print.m[3][3]);
}
/*************************************/

void		make_rescale(t_mat4 *to_scale, t_vec3 *vector)
{
	to_scale->m[0][0] = vector->x;
	to_scale->m[0][1] = 0.0f;
	to_scale->m[0][2] = 0.0f;
	to_scale->m[0][3] = 0.0f;
	to_scale->m[1][0] = 0.0f;
	to_scale->m[1][1] = vector->y;
	to_scale->m[1][2] = 0.0f;
	to_scale->m[1][3] = 0.0f;
	to_scale->m[2][0] = 0.0f;
	to_scale->m[2][1] = 0.0f;
	to_scale->m[2][2] = vector->z;
	to_scale->m[2][3] = 0.0f;
	to_scale->m[3][0] = 0.0f;
	to_scale->m[3][1] = 0.0f;
	to_scale->m[3][2] = 0.0f;
	to_scale->m[3][3] = 1.0;
}

t_mat4		create_mat4(float homogene)
{
	t_mat4		create_mat;

	create_mat.m[0][0] = 1.0f;
	create_mat.m[0][1] = 0.0f;
	create_mat.m[0][2] = 0.0f;
	create_mat.m[0][3] = 0.0f;
	create_mat.m[1][0] = 0.0f;
	create_mat.m[1][1] = 1.0f;
	create_mat.m[1][2] = 0.0f;
	create_mat.m[1][3] = 0.0f;
	create_mat.m[2][0] = 0.0f;
	create_mat.m[2][1] = 0.0f;
	create_mat.m[2][2] = 1.0f;
	create_mat.m[2][3] = 0.0f;
	create_mat.m[3][0] = 0.0f;
	create_mat.m[3][1] = 0.0f;
	create_mat.m[3][2] = 0.0f;
	create_mat.m[3][3] = homogene;
	return (create_mat);
}

t_mat4		make_translation(t_vec3 *src)
{
	t_mat4		new;

	new = create_mat4(1.0f);
	new.m[0][3] = src->x;
	new.m[1][3] = src->y;
	new.m[2][3] = src->z;
	return (new);
}

t_mat4		m4_x_m4(t_mat4 *a, t_mat4 *b)
{
	t_mat4		final_matrix;
	int			i;
	int			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			final_matrix.m[j][i] =
			a->m[j][0] * b->m[0][i] +
			a->m[j][1] * b->m[1][i] +
			a->m[j][2] * b->m[2][i] +
			a->m[j][3] * b->m[3][i];
			i++;
		}
		j++;
	}
	return (final_matrix);
}

t_mat4		matrix_scale(float value)
{
	t_mat4		scale;

	scale = create_mat4(1.0f);
	scale.m[0][0] = value;
	scale.m[1][1] = value;
	scale.m[2][2] = value;
	return (scale);
}
