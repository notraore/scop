/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/12 09:28:36 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec3		create_tvec3(double x, double y, double z)
{
	t_vec3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

float		magnitude(t_vec3 *a)
{
	return (sqrtf(a->x * a->x + a->y * a->y + a->z * a->z));
}

t_vec3		normalize(t_vec3 *a)
{
	t_vec3	normalized;
	float		magn;

	magn = magnitude(a);
	normalized.x = a->x / magn;
	normalized.y = a->y / magn;
	normalized.z = a->z / magn;
	return (normalized);
}

t_vec3		v_v_subs(t_vec3 *a, t_vec3 *b)
{
	t_vec3	r;

	r.x = a->x - b->x;
	r.y = a->y - b->y;
	r.z = a->z - b->z;
	return (r);
}

t_vec3		v_v_mult(t_vec3 *a, t_vec3 *b)
{
	t_vec3	r;

	r.x = (a->y * b->z) - (a->z * b->y);
	r.y = (a->z * b->x) - (a->x * b->z);
	r.z = (a->x * b->y) - (a->y * b->x);
	return (r);
}