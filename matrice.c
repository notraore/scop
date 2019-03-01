/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/02/27 11:30:44 by notraore         ###   ########.fr       */
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

// t_vec4		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector)
// t_mat4		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector)
void		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector)
{
	// t_mat4		multiplied;

	// multiplied = *to_mult;
	// t_vec4		multiplied;

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

	// multiplied.x = to_mult->m[0][0] * vector->x;
	// multiplied.x += to_mult->m[0][1] * vector->y;
	// multiplied.x += to_mult->m[0][2] * vector->z;
	// multiplied.x += to_mult->m[0][3] * 1.0f;;

	// multiplied.y = to_mult->m[1][0] * vector->x;
	// multiplied.y += to_mult->m[1][0] * vector->y;
	// multiplied.y += to_mult->m[1][0] * vector->z;
	// multiplied.y += to_mult->m[1][0] * 1.0f;

	// multiplied.z = to_mult->m[2][0] * vector->x;
	// multiplied.z += to_mult->m[2][0] * vector->y;
	// multiplied.z += to_mult->m[2][0] * vector->z;
	// multiplied.z += to_mult->m[2][3] * 1.0f;

	// multiplied.w = to_mult->m[3][0] * vector->x;
	// multiplied.w += to_mult->m[3][0] * vector->y;
	// multiplied.w += to_mult->m[3][0] * vector->z;
	// multiplied.w += to_mult->m[3][3] * 1.0f;
	// print_vec4(multiplied);
	// return (multiplied);
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

t_mat4		translate_mat4(t_mat4 *transform, t_vec3 *new_pos)
{
	t_mat4		translated;
	t_vec4		next_pos;

	next_pos = create_tvec4(new_pos->x, new_pos->y, new_pos->z, 1.0f);
	printf("%f || %f | %f\n", new_pos->x, new_pos->y, new_pos->z );
	translated = create_mat4(1.0f);
	make_trans(&translated, new_pos);
	// print_mat4(translated);
	mult_mat4_vec4(transform, &next_pos);
	return (translated);
}
