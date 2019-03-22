/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:30:44 by notraore          #+#    #+#             */
/*   Updated: 2019/03/12 09:28:36 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		dot_product(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
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

double		degree_to_radian(double degree_angle)
{
	return (degree_angle * ((float)PI / 180.0));
}

void		print_fps_counter(t_glenv *env)
{
	env->current_time = glfwGetTime();
	env->frames++;
	if (env->current_time - env->last_time >= 0.2f)
	{
		ft_putnbr(env->frames);
		ft_putendl(" FPS");
		env->frames = 0;
		env->last_time += 1.0;
	}
}
