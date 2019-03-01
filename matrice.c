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



// t_mat4			create_mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
// {
// 	t_mat4	new;

// 	new.a = a.x;
// 	new.b = a.y;
// 	new.c = a.z;
// 	new.d = a.w;

// 	new.e = b.x;
// 	new.f = b.y;
// 	new.g = b.z;
// 	new.h = b.w;

// 	new.i = c.x;
// 	new.j = c.y;
// 	new.k = c.z;
// 	new.l = c.w;

// 	new.m = d.x;
// 	new.n = d.y;
// 	new.o = d.z;
// 	new.p = d.w;
// 	return(new);
// }

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

// t_vec4		mult_mat4_vec4(t_mat4 matrice, t_vec4 vector)
// {
// 	t_vec4		new;

// 	new.x = matrice.a * vector.x;
// 	new.x += matrice.b * vector.y;
// 	new.x += matrice.c * vector.z;
// 	new.x += matrice.d * vector.w;

// 	new.y = matrice.e * vector.x;
// 	new.y += matrice.f * vector.y;
// 	new.y += matrice.g * vector.z;
// 	new.y += matrice.h * vector.w;

// 	new.z = matrice.i * vector.x;
// 	new.z += matrice.j * vector.y;
// 	new.z += matrice.k * vector.z;
// 	new.z += matrice.l * vector.w;

// 	new.w = matrice.m * vector.x;
// 	new.w += matrice.n * vector.y;
// 	new.w += matrice.o * vector.z;
// 	new.w += matrice.p * vector.w;
// 	return (new);
// }

t_mat4			create_translation_mat4(void)
{
	t_mat4	new;


	new.m[0][0] = 1.0;
	new.m[0][1] = 0.0;
	new.m[0][2] = 0.0;
	new.m[0][3] = 0.0;

	new.m[1][0] = 0.0;
	new.m[1][1] = 1.0;
	new.m[1][2] = 0.0;
	new.m[1][3] = 0.0;

	new.m[2][0] = 0.0;
	new.m[2][1] = 0.0;
	new.m[2][2] = 1.0;
	new.m[2][3] = 0.0;

	new.m[3][0] = 0.0;
	new.m[3][1] = 0.0;
	new.m[3][2] = 0.0;
	new.m[3][3] = 1.0;
	return (new);
}

void			add_translation(t_glenv *e, t_vec3 *vec, t_mat4 *new)
{
	e->newx = 0;
	e->newy = 0;
	e->newz = 0;
	if (vec->x != 0)
	{
		e->newx = vec->x * new->m[0][0];
		e->newy = vec->x * new->m[0][1];
		e->newz = vec->x * new->m[0][2];
	}
	else if (vec->y != 0)
	{
		e->newx = vec->y * new->m[1][0];
		e->newy = vec->y * new->m[1][1];
		e->newz = vec->y * new->m[1][2];
	}
	else if (vec->z != 0)
	{
		e->newx = vec->z * new->m[2][0];
		e->newy = vec->z * new->m[2][1];
		e->newz = vec->z * new->m[2][2];
	}
}

t_mat4			make_translation_mat4(t_glenv *e, t_vec3 *vec)
{
	t_mat4	new;

	new = create_translation_mat4();

	add_translation(e, vec, &new);
	// print_mat4(&new);
	new.m[0][0] = 1.0;
	new.m[0][1] = 0.0;
	new.m[0][2] = 0.0;
	new.m[0][3] = e->newx;
	new.m[1][0] = 0.0;
	new.m[1][1] = 1.0;
	new.m[1][2] = 0.0;
	new.m[1][3] = e->newy;
	new.m[2][0] = 0.0;
	new.m[2][1] = 0.0;
	new.m[2][2] = 1.0;
	new.m[2][3] = e->newz;
	new.m[3][0] = 0.0;
	new.m[3][1] = 0.0;
	new.m[3][2] = 0.0;
	new.m[3][3] = 1.0;
	return (new);
}



// t_mat4			scale_mat4(t_vec3 scale)
// {
// 	t_mat4		new;

// 	new.a = scale.x;
// 	new.b = 0;
// 	new.c = 0;
// 	new.d = 0;

// 	new.e = 0;
// 	new.f = scale.y;
// 	new.g = 0;
// 	new.h = 0;

// 	new.i = 0;
// 	new.j = 0;
// 	new.k = scale.z;
// 	new.l = 0;

// 	new.m = 0;
// 	new.n = 0;
// 	new.o = 0;
// 	new.p = 1;
// 	return(new);
// }