/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/13 15:40:28 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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