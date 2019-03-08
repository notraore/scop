/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/03 00:03:45 by bano             ###   ########.fr       */
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
//
// t_mat4		create_rot_matrice(t_mat4 *to_rot, float degree, t_vec3 axis)
// {
// 	to_rot[0][0] = 1.0f;
// 	to_rot[0][0] = 0.0f;
// 	to_rot[0][0] = 0.0f;
// 	to_rot[0][0] = 0.0f;
// 	to_rot[0][0] = 0;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = 0.0f;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = 0.0f;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = ;
// 	to_rot[0][0] = 1.0f;
//
// }*/

// t_vec3		extract_vec3(t_mat4 *matrix)
// {
// 	t_vec3		extracted;

// 	extracted.x = matrix->m[0][0] + matrix->m[0][1] + matrix->m[0][2] + matrix->m[0][3];
// 	extracted.y = matrix->m[1][0] + matrix->m[1][1] + matrix->m[1][2] + matrix->m[1][3];
// 	extracted.z = matrix->m[2][0] + matrix->m[2][1] + matrix->m[2][2] + matrix->m[2][3];
// 	return (extracted);
// }

t_mat4		make_rot_x(t_mat4 *transform, float degree)
{
	t_mat4		to_rotate;

	to_rotate.m[0][0] = 1.0f;
	to_rotate.m[0][1] = 0.0f;
	to_rotate.m[0][2] = 0.0f;
	to_rotate.m[0][3] = transform->m[0][3];
	to_rotate.m[1][0] = 0.0f;
	to_rotate.m[1][1] = cosf((degree * PI) / 180);
	to_rotate.m[1][2] = -sinf((degree * PI) / 180);
	to_rotate.m[1][3] = transform->m[1][3];
	to_rotate.m[2][0] = 0.0f;
	to_rotate.m[2][1] = sinf((degree * PI) / 180);
	to_rotate.m[2][2] = cosf((degree * PI) / 180);
	to_rotate.m[2][3] = 0.0f;
	to_rotate.m[3][0] = 0.0f;
	to_rotate.m[3][1] = 0.0f;
	to_rotate.m[3][2] = 0.0f;
	to_rotate.m[3][3] = 1.0f;
	return (to_rotate);
}


t_mat4		make_rot_y(t_mat4 *transform, float degree)
{
	t_mat4		to_rotate;

	to_rotate.m[0][0] = cosf((degree * PI) / 180);
	to_rotate.m[0][1] = 0.0f;
	to_rotate.m[0][2] = sinf((degree * PI) / 180);
	to_rotate.m[0][3] = transform->m[0][3];
	to_rotate.m[1][0] = 0.0f;
	to_rotate.m[1][1] = 1.0f;
	to_rotate.m[1][2] = 0.0f;
	to_rotate.m[1][3] = transform->m[1][3];
	to_rotate.m[2][0] = -sinf((degree * PI) / 180);
	to_rotate.m[2][1] = 0.0f;
	to_rotate.m[2][2] = cosf((degree * PI) / 180);
	to_rotate.m[2][3] = 0.0f;
	to_rotate.m[3][0] = 0.0f;
	to_rotate.m[3][1] = 0.0f;
	to_rotate.m[3][2] = 0.0f;
	to_rotate.m[3][3] = 1.0f;
	return (to_rotate);
}


t_mat4		make_rot_z(t_mat4 *transform, float degree)
{
	t_mat4		to_rotate;

	to_rotate.m[0][0] = cosf((degree * PI) / 180);
	to_rotate.m[0][1] = -sinf((degree * PI) / 180);
	to_rotate.m[0][2] = 0.0f;
	to_rotate.m[0][3] = transform->m[0][3];
	to_rotate.m[1][0] = sinf((degree * PI) / 180);
	to_rotate.m[1][1] = cosf((degree * PI) / 180);
	to_rotate.m[1][2] = 0.0f;
	to_rotate.m[1][3] = transform->m[1][3];
	to_rotate.m[2][0] = 0.0f;
	to_rotate.m[2][1] = 0.0f;
	to_rotate.m[2][2] = 1.0f;
	to_rotate.m[2][3] = 0.0f;
	to_rotate.m[3][0] = 0.0f;
	to_rotate.m[3][1] = 0.0f;
	to_rotate.m[3][2] = 0.0f;
	to_rotate.m[3][3] = 1.0f;
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

// void		make_cam_trans(t_mat4 *translated, t_vec3 *new_pos)
// {
// 	translated->m[0][0] = 1.0;
// 	translated->m[0][1] = 0.0;
// 	translated->m[0][2] = 0.0;
// 	translated->m[0][3] = -new_pos->x;
// 	translated->m[1][0] = 0.0;
// 	translated->m[1][1] = 1.0;
// 	translated->m[1][2] = 0.0;
// 	translated->m[1][3] = -new_pos->y;
// 	translated->m[2][0] = 0.0;
// 	translated->m[2][1] = 0.0;
// 	translated->m[2][2] = 1.0;
// 	translated->m[2][3] = -new_pos->z;
// 	translated->m[3][0] = 0.0;
// 	translated->m[3][1] = 0.0;
// 	translated->m[3][2] = 0.0;
// 	translated->m[3][3] = 1.0;
// }

// void		mat4_mult_mat4(t_mat4 *a, t_mat4 *b, t_mat4 *result)
// {
// 	result->m[0][0] = a->m[0][0] * b->m[0][0];
// 	result->m[0][1] = a->m[0][1] * b->m[0][1];
// 	result->m[0][2] = a->m[0][2] * b->m[0][2];
// 	result->m[0][3] = a->m[0][3] * b->m[0][3];

// 	result->m[1][0] = a->m[1][0] * b->m[1][0];
// 	result->m[1][1] = a->m[1][1] * b->m[1][1];
// 	result->m[1][2] = a->m[1][2] * b->m[1][2];
// 	result->m[1][3] = a->m[1][3] * b->m[1][3];

// 	result->m[2][0] = a->m[2][0] * b->m[2][0];
// 	result->m[2][1] = a->m[2][1] * b->m[2][1];
// 	result->m[2][2] = a->m[2][2] * b->m[2][2];
// 	result->m[2][3] = a->m[2][3] * b->m[2][3];

// 	result->m[3][0] = a->m[3][0] * b->m[3][0];
// 	result->m[3][1] = a->m[3][1] * b->m[3][1];
// 	result->m[3][2] = a->m[3][2] * b->m[3][2];
// 	result->m[3][3] = a->m[3][3] * b->m[3][3];
// }


// t_mat4		mult_mvp(t_mat4 *p, t_mat4 *v, t_mat4 *m)
// {
// 	t_mat4		mvp;

// 	mvp.m[0][0] = p->m[0][0] * v->m[0][0] * m->m[0][0];
// 	mvp.m[0][1] = p->m[0][1] * v->m[0][1] * m->m[0][1];
// 	mvp.m[0][2] = p->m[0][2] * v->m[0][2] * m->m[0][2];
// 	mvp.m[0][3] = p->m[0][3] * v->m[0][3] * m->m[0][3];

// 	mvp.m[1][0] = p->m[1][0] * v->m[1][0] * m->m[1][0];
// 	mvp.m[1][1] = p->m[1][1] * v->m[1][1] * m->m[1][1];
// 	mvp.m[1][2] = p->m[1][2] * v->m[1][2] * m->m[1][2];
// 	mvp.m[1][3] = p->m[1][3] * v->m[1][3] * m->m[1][3];

// 	mvp.m[2][0] = p->m[2][0] * v->m[2][0] * m->m[2][0];
// 	mvp.m[2][1] = p->m[2][1] * v->m[2][1] * m->m[2][1];
// 	mvp.m[2][2] = p->m[2][2] * v->m[2][2] * m->m[2][2];
// 	mvp.m[2][3] = p->m[2][3] * v->m[2][3] * m->m[2][3];

// 	mvp.m[3][0] = p->m[3][0] * v->m[3][0] * m->m[3][0];
// 	mvp.m[3][1] = p->m[3][1] * v->m[3][1] * m->m[3][1];
// 	mvp.m[3][2] = p->m[3][2] * v->m[3][2] * m->m[3][2];
// 	mvp.m[3][3] = p->m[3][3] * v->m[3][3] * m->m[3][3];
// 	return (mvp);
// }

t_mat4		mat4_plus_mat4(t_mat4 *a, t_mat4 *b)
{
	t_mat4		a_plus_b;

	a_plus_b.m[0][0] = a->m[0][0] + b->m[0][0];
	a_plus_b.m[0][1] = a->m[0][1] + b->m[0][1];
	a_plus_b.m[0][2] = a->m[0][2] + b->m[0][2];
	a_plus_b.m[0][3] = a->m[0][3] + b->m[0][3];
	a_plus_b.m[1][0] = a->m[1][0] + b->m[1][0];
	a_plus_b.m[1][1] = a->m[1][1] + b->m[1][1];
	a_plus_b.m[1][2] = a->m[1][2] + b->m[1][2];
	a_plus_b.m[1][3] = a->m[1][3] + b->m[1][3];
	a_plus_b.m[2][0] = a->m[2][0] + b->m[2][0];
	a_plus_b.m[2][1] = a->m[2][1] + b->m[2][1];
	a_plus_b.m[2][2] = a->m[2][2] + b->m[2][2];
	a_plus_b.m[2][3] = a->m[2][3] + b->m[2][3];
	a_plus_b.m[3][0] = a->m[3][0] + b->m[3][0];
	a_plus_b.m[3][1] = a->m[3][1] + b->m[3][1];
	a_plus_b.m[3][2] = a->m[3][2] + b->m[3][2];
	a_plus_b.m[3][3] = a->m[3][3] + b->m[3][3];
	return (a_plus_b);
}

// void		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector)
// {
// 	to_mult->m[0][0] = to_mult->m[0][0] * vector->x;
// 	to_mult->m[0][1] = to_mult->m[0][1] * vector->x;
// 	to_mult->m[0][2] = to_mult->m[0][2] * vector->x;
// 	to_mult->m[0][3] = to_mult->m[0][3] * vector->x;

// 	to_mult->m[1][0] = to_mult->m[1][0] * vector->y;
// 	to_mult->m[1][1] = to_mult->m[1][1] * vector->y;
// 	to_mult->m[1][2] = to_mult->m[1][2] * vector->y;
// 	to_mult->m[1][3] = to_mult->m[1][3] * vector->y;
	
// 	to_mult->m[2][0] = to_mult->m[2][0] * vector->z;
// 	to_mult->m[2][1] = to_mult->m[2][1] * vector->z;
// 	to_mult->m[2][2] = to_mult->m[2][2] * vector->z;
// 	to_mult->m[2][3] = to_mult->m[2][3] * vector->z;

// 	to_mult->m[3][0] = to_mult->m[3][0] * vector->w;
// 	to_mult->m[3][1] = to_mult->m[3][1] * vector->w;
// 	to_mult->m[3][2] = to_mult->m[3][2] * vector->w;
// 	to_mult->m[3][3] = to_mult->m[3][3] * vector->w;
// }


// void		mult_mat4_vec3(t_mat4 *to_mult, t_vec3 *vector, t_mat4 *result)
// {
// 	result->m[0][0] += to_mult->m[0][0] * vector->x;
// 	result->m[0][1] += to_mult->m[0][1] * vector->x;
// 	result->m[0][2] += to_mult->m[0][2] * vector->x;
// 	result->m[0][3] += to_mult->m[0][3] * vector->x;

// 	result->m[1][0] += to_mult->m[1][0] * vector->y;
// 	result->m[1][1] += to_mult->m[1][1] * vector->y;
// 	result->m[1][2] += to_mult->m[1][2] * vector->y;
// 	result->m[1][3] += to_mult->m[1][3] * vector->y;
	
// 	result->m[2][0] += to_mult->m[2][0] * vector->z;
// 	result->m[2][1] += to_mult->m[2][1] * vector->z;
// 	result->m[2][2] += to_mult->m[2][2] * vector->z;
// 	result->m[2][3] += to_mult->m[2][3] * vector->z;

// 	result->m[3][0] += to_mult->m[3][0] * 0;
// 	result->m[3][1] += to_mult->m[3][1] * 0;
// 	result->m[3][2] += to_mult->m[3][2] * 0;
// 	result->m[3][3] += to_mult->m[3][3] * 1;
// }

// void		plus_mat4_vec3(t_mat4 *to_plus, t_vec3 *vector)
// {
// 	// t_mat4		plus;

// 	to_plus->m[0][0] = to_plus->m[0][0] + vector->x;
// 	to_plus->m[0][1] = to_plus->m[0][1] + vector->x;
// 	to_plus->m[0][2] = to_plus->m[0][2] + vector->x;
// 	to_plus->m[0][3] = to_plus->m[0][3] + vector->x;

// 	to_plus->m[1][0] = to_plus->m[1][0] + vector->y;
// 	to_plus->m[1][1] = to_plus->m[1][1] + vector->y;
// 	to_plus->m[1][2] = to_plus->m[1][2] + vector->y;
// 	to_plus->m[1][3] = to_plus->m[1][3] + vector->y;
	
// 	to_plus->m[2][0] = to_plus->m[2][0] + vector->z;
// 	to_plus->m[2][1] = to_plus->m[2][1] + vector->z;
// 	to_plus->m[2][2] = to_plus->m[2][2] + vector->z;
// 	to_plus->m[2][3] = to_plus->m[2][3] + vector->z;

// 	to_plus->m[3][0] = to_plus->m[3][0] + 0;
// 	to_plus->m[3][1] = to_plus->m[3][1] + 0;
// 	to_plus->m[3][2] = to_plus->m[3][2] + 0;
// 	to_plus->m[3][3] = to_plus->m[3][3] + 1;
// 	// return (plus);
// }

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


void		make_trans(t_mat4 *translated, t_vec3 *new_pos)
{
	translated->m[0][0] = 1.0;
	translated->m[0][1] = 0.0;
	translated->m[0][2] = 0.0;
	translated->m[0][3] = new_pos->x;
	translated->m[1][0] = 0.0;
	translated->m[1][1] = 1.0;
	translated->m[1][2] = 0.0;
	translated->m[1][3] = new_pos->y;
	translated->m[2][0] = 0.0;
	translated->m[2][1] = 0.0;
	translated->m[2][2] = 1.0;
	translated->m[2][3] = new_pos->z;
	translated->m[3][0] = 0.0;
	translated->m[3][1] = 0.0;
	translated->m[3][2] = 0.0;
	translated->m[3][3] = 1.0;
}

t_mat4		m4_x_m4(t_mat4 *transform, t_mat4 *rotation)
{
	t_mat4	final_matrix;
	int			i;
	int			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			final_matrix.m[j][i] =
			rotation->m[j][0] * transform->m[0][i] +
			rotation->m[j][1] * transform->m[1][i] +
			rotation->m[j][2] * transform->m[2][i] +
			rotation->m[j][3] * transform->m[3][i];
			i++;
		}
		j++;
	}
	return (final_matrix);
}

t_mat4		translate_mat4(t_vec3 *new_pos)
{
	t_mat4		translated;

	translated = create_mat4(1.0f);
	make_trans(&translated, new_pos);
	return (translated);
}

t_mat4		rescale_mat4(t_vec3 *new_size)
{
	t_mat4		scaled;

	scaled = create_mat4(1.0f);
	make_rescale(&scaled, new_size);
	return (scaled);
}

// t_mat4		rotate_mat4(t_mat4 *transform, float degree, t_vec3 *axis)
// {
// 	t_mat4		rot;

// 	if (axis->x == 1.0f)
// 		rot = make_rot_x(&rot, degree);
// 	if (axis->y == 1.0f)
// 		rot = make_rot_y(&rot, degree);
// 	if (axis->z == 1.0f)
// 		rot = make_rot_z(&rot, degree);
// 	rot = m4_x_m4(transform, &rot);
// 	return (rot);
// }
