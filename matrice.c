/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/12 08:12:11 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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

// t_vec3		extract_vec3(t_mat4 *matrix)
// {
// 	t_vec3		extracted;

// 	extracted.x = matrix->m[0][0] + matrix->m[0][1] + matrix->m[0][2] + matrix->m[0][3];
// 	extracted.y = matrix->m[1][0] + matrix->m[1][1] + matrix->m[1][2] + matrix->m[1][3];
// 	extracted.z = matrix->m[2][0] + matrix->m[2][1] + matrix->m[2][2] + matrix->m[2][3];
// 	return (extracted);
// }

t_mat4		make_rot_x(float degree)
{
	t_mat4		to_rotate;

	to_rotate = create_mat4(1.0f);
	to_rotate.m[1][1] = cosf((degree * PI) / 180);
	to_rotate.m[1][2] = -sinf((degree * PI) / 180);
	to_rotate.m[2][1] = sinf((degree * PI) / 180);
	to_rotate.m[2][2] = cosf((degree * PI) / 180);
	return (to_rotate);
}


t_mat4		make_rot_y(float degree)
{
	t_mat4		to_rotate;

	to_rotate = create_mat4(1.0f);
	to_rotate.m[0][0] = cosf((degree * PI) / 180);
	to_rotate.m[0][2] = sinf((degree * PI) / 180);
	to_rotate.m[2][0] = -sinf((degree * PI) / 180);
	to_rotate.m[2][2] = cosf((degree * PI) / 180);
	return (to_rotate);
}


t_mat4		make_rot_z(float degree)
{
	t_mat4		to_rotate;

	to_rotate = create_mat4(1.0f);
	to_rotate.m[0][0] = cosf((degree * PI) / 180);
	to_rotate.m[0][1] = -sinf((degree * PI) / 180);
	to_rotate.m[1][0] = sinf((degree * PI) / 180);
	to_rotate.m[1][1] = cosf((degree * PI) / 180);
	return (to_rotate);
}

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

t_mat4		lookat(t_vec3 *eye, t_vec3 *center, t_vec3 *up)
{
	t_mat4		lookat;

	lookat = create_mat4(1.0f);
	t_vec3		fcen_eye = v_v_subs(center, eye);

	t_vec3		f_eye = normalize(&fcen_eye);
	t_vec3		u_up = normalize(up);

	t_vec3		fu_cross = v_v_mult(&fcen_eye, &u_up);

	t_vec3		s_center = normalize(&fu_cross);
	u_up = v_v_mult(&s_center, &f_eye);

	lookat.m[0][0] = s_center.x;
	lookat.m[1][0] = s_center.y;
	lookat.m[2][0] = s_center.z;

	lookat.m[0][1] = u_up.x;
	lookat.m[1][1] = u_up.y;
	lookat.m[2][1] = u_up.z;

	lookat.m[0][2] = -f_eye.x;
	lookat.m[1][2] = -f_eye.y;
	lookat.m[2][2] = -f_eye.z;

	lookat.m[3][0] = -dot_product(&s_center, eye);
	lookat.m[3][1] = -dot_product(&u_up, eye);
	lookat.m[3][2] = dot_product(&f_eye, eye);
	return lookat;
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
