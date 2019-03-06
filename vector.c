/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/02/27 11:30:44 by notraore         ###   ########.fr       */
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

t_vec4		create_tvec4(double x, double y, double z, double w)
{
	t_vec4	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = w;
	return (new);
}

void		print_vec4(t_vec4 vec)
{
	ft_putstr("[");
	ft_putnbr(vec.x);
	ft_putstr(" ");
	ft_putnbr(vec.y);
	ft_putstr(" ");
	ft_putnbr(vec.z);
	ft_putstr(" ");
	ft_putnbr(vec.w);
	ft_putendl("]");
}

void		print_vec3(t_vec3 vec)
{
	printf("[%f ", vec.x);
	printf("%f ", vec.y);
	printf("%f]\n", vec.z);
}

float		magnitude(t_vec3 *a)
{
	return (sqrtf(a->x * a->x + a->y * a->y + a->z * a->z));
}

t_vec3	normalize(t_vec3 *a)
{
	t_vec3	normalized;
	float		magn;

	magn = magnitude(a);
	normalized.x = a->x / magn;
	normalized.y = a->y / magn;
	normalized.z = a->z / magn;
	return (normalized);
}

t_vec3	v_v_subs(t_vec3 *a, t_vec3 *b)
{
	t_vec3	r;

	r.x = a->x - b->x;
	r.y = a->y - b->y;
	r.z = a->z - b->z;
	return (r);
}