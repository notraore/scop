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
	ft_putstr("[");
	ft_putnbr(to_print.m[0][0]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[0][1]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[0][2]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[0][3]);
	ft_putendl("]");
	ft_putstr("[");
	ft_putnbr(to_print.m[1][0]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[1][1]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[1][2]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[1][3]);
	ft_putendl("]");
	ft_putstr("[");
	ft_putnbr(to_print.m[2][0]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[2][1]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[2][2]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[2][3]);
	ft_putendl("]");
	ft_putstr("[");
	ft_putnbr(to_print.m[3][0]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[3][1]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[3][2]);
	ft_putstr(" ");
	ft_putnbr(to_print.m[3][3]);
	ft_putendl("]");
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

void make_rot_x(t_mat4 *to_rotate, float degree)
{
	const float PI = 3.1415926;

	to_rotate->m[0][0] = 1.0f;
	to_rotate->m[0][1] = 0.0f;
	to_rotate->m[0][2] = 0.0f;
	to_rotate->m[0][3] = 0.0f;
	to_rotate->m[1][0] = 0.0f;
	to_rotate->m[1][1] = cosf((degree * PI) / 180);
	to_rotate->m[1][2] = -sinf((degree * PI) / 180);
	to_rotate->m[1][3] = 0.0f;
	to_rotate->m[2][0] = 0.0f;
	to_rotate->m[2][1] = 0.0f;
	to_rotate->m[2][2] = sinf((degree * PI) / 180);
	to_rotate->m[2][3] = cosf((degree * PI) / 180);
	to_rotate->m[3][0] = 0.0f;
	to_rotate->m[3][1] = 0.0f;
	to_rotate->m[3][2] = 0.0f;
	to_rotate->m[3][3] = 1.0f;
}


void make_rot_y(t_mat4 *to_rotate, float degree)
{
	to_rotate->m[0][0] = degree;
	to_rotate->m[0][1] = 0.0f;
	to_rotate->m[0][2] = 0.0f;
	to_rotate->m[0][3] = 0.0f;
	to_rotate->m[1][0] = 0.0f;
	to_rotate->m[1][1] = 0.0f;
	to_rotate->m[1][2] = 0.0f;
	to_rotate->m[1][3] = 0.0f;
	to_rotate->m[2][0] = 0.0f;
	to_rotate->m[2][1] = 0.0f;
	to_rotate->m[2][2] = 0.0f;
	to_rotate->m[2][3] = 0.0f;
	to_rotate->m[3][0] = 0.0f;
	to_rotate->m[3][1] = 0.0f;
	to_rotate->m[3][2] = 0.0f;
	to_rotate->m[3][3] = 0.0f;
}


void make_rot_z(t_mat4 *to_rotate, float degree)
{
	to_rotate->m[0][0] = degree;
	to_rotate->m[0][1] = 0.0f;
	to_rotate->m[0][2] = 0.0f;
	to_rotate->m[0][3] = 0.0f;
	to_rotate->m[1][0] = 0.0f;
	to_rotate->m[1][1] = 0.0f;
	to_rotate->m[1][2] = 0.0f;
	to_rotate->m[1][3] = 0.0f;
	to_rotate->m[2][0] = 0.0f;
	to_rotate->m[2][1] = 0.0f;
	to_rotate->m[2][2] = 0.0f;
	to_rotate->m[2][3] = 0.0f;
	to_rotate->m[3][0] = 0.0f;
	to_rotate->m[3][1] = 0.0f;
	to_rotate->m[3][2] = 0.0f;
	to_rotate->m[3][3] = 0.0f;
}

void		make_rescale(t_mat4 *to_scale, t_vec3 *vector)
{
	to_scale->m[0][0] = vector->x;
// 	to_scale->m[0][1] = 0.0f;
// 	to_scale->m[0][2] = 0.0f;
// 	to_scale->m[0][3] = 0.0f;
// 	to_scale->m[1][0] = 0.0f;*/
	to_scale->m[1][1] = vector->y;
	// to_scale->m[1][2] = 0.0f;
	// to_scale->m[1][3] = 0.0f;
	// to_scale->m[2][0] = 0.0f;
	// to_scale->m[2][1] = 0.0f;*/
	to_scale->m[2][2] = vector->z;
// 	to_scale->m[2][3] = 0.0f;
// 	to_scale->m[3][0] = 0.0f;
// 	to_scale->m[3][1] = 0.0f;
// 	to_scale->m[3][2] = 0.0f;*/
	to_scale->m[3][3] = 1.0;
}

void		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector)
{
	to_mult->m[0][0] = to_mult->m[0][0] * vector->x;
	to_mult->m[0][1] = to_mult->m[0][1] * vector->y;
	to_mult->m[0][2] = to_mult->m[0][2] * vector->z;
	to_mult->m[0][3] = to_mult->m[0][3] * vector->w;
	to_mult->m[1][0] = to_mult->m[1][0] * vector->x;
	to_mult->m[1][1] = to_mult->m[1][0] * vector->y;
	to_mult->m[1][2] = to_mult->m[1][0] * vector->z;
	to_mult->m[1][3] = to_mult->m[1][0] * vector->w;
	to_mult->m[2][0] = to_mult->m[2][0] * vector->x;
	to_mult->m[2][1] = to_mult->m[2][0] * vector->y;
	to_mult->m[2][2] = to_mult->m[2][0] * vector->z;
	to_mult->m[2][3] = to_mult->m[2][3] * vector->w;
	to_mult->m[3][0] = to_mult->m[3][0] * vector->x;
	to_mult->m[3][1] = to_mult->m[3][0] * vector->y;
	to_mult->m[3][2] = to_mult->m[3][0] * vector->z;
	to_mult->m[3][3] = to_mult->m[3][3] * vector->w;
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

t_mat4		mat4_mult_mat4(t_mat4 *a, t_mat4 *b)
{
	t_mat4		a_mult_b;

	a_mult_b.m[0][0] = a->m[0][0] * b->m[0][0];
	a_mult_b.m[0][1] = a->m[0][1] * b->m[0][1];
	a_mult_b.m[0][2] = a->m[0][2] * b->m[0][2];
	a_mult_b.m[0][3] = a->m[0][3] * b->m[0][3];
	a_mult_b.m[1][0] = a->m[1][0] * b->m[1][0];
	a_mult_b.m[1][1] = a->m[1][1] * b->m[1][1];
	a_mult_b.m[1][2] = a->m[1][2] * b->m[1][2];
	a_mult_b.m[1][3] = a->m[1][3] * b->m[1][3];
	a_mult_b.m[2][0] = a->m[2][0] * b->m[2][0];
	a_mult_b.m[2][1] = a->m[2][1] * b->m[2][1];
	a_mult_b.m[2][2] = a->m[2][2] * b->m[2][2];
	a_mult_b.m[2][3] = a->m[2][3] * b->m[2][3];
	a_mult_b.m[3][0] = a->m[3][0] * b->m[3][0];
	a_mult_b.m[3][1] = a->m[3][1] * b->m[3][1];
	a_mult_b.m[3][2] = a->m[3][2] * b->m[3][2];
	a_mult_b.m[3][3] = a->m[3][3] * b->m[3][3];
	return (a_mult_b);
}

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

t_mat4		rotate_mat4(t_mat4 *transform, float degree, t_vec3 *axis, t_vec3 *new_rot)
{
	t_mat4	rotated;
	t_vec4	next_rot;

	(void)axis;
	// if (axis[0].x == 1.0f)

	next_rot = create_tvec4(new_rot->x, new_rot->y, new_rot->z, 1.0f);

	make_rot_x(&rotated, degree);

	// else if (axis[1].x == 1.0f)
	// 	make_rot_y(&rotated, degree);
	// else if (axis[2].x == 1.0f)
	// 	make_rot_z(&rotated, degree);
	mult_mat4_vec4(transform, &next_rot);

	return (rotated);
}

t_mat4		translate_mat4(t_mat4 *transform, t_vec3 *new_pos)
{
	t_mat4		translated;
	t_vec4		next_pos;

	next_pos = create_tvec4(new_pos->x, new_pos->y, new_pos->z, 1.0f);
	//  printf("%f || %f | %f\n", new_pos->x, new_pos->y, new_pos->z );*/
	// translated = create_mat4(1.0f);*/
	make_trans(&translated, new_pos);
	mult_mat4_vec4(transform, &next_pos);
	return (translated);
}

t_mat4		rescale_mat4(t_mat4 *transform, t_vec3 *new_size)
{
	t_vec4	next_size;
	// t_mat4		scaled;

	next_size = create_tvec4(new_size->x, new_size->y, new_size->z, 1.0f);
	printf("%f || %f | %f\n", new_size->x, new_size->y, new_size->z);
	// scaled = create_mat4(1.0f);
	make_rescale(transform, new_size);
	// mult_mat4_vec4(transform, &next_size);
	return (*transform);
}
