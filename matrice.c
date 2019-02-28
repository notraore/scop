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

t_mat4			create_mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
	t_mat4	new;

	new.a = a.x;
	new.b = a.y;
	new.c = a.z;
	new.d = a.w;

	new.e = b.x;
	new.f = b.y;
	new.g = b.z;
	new.h = b.w;

	new.i = c.x;
	new.j = c.y;
	new.k = c.z;
	new.l = c.w;

	new.m = d.x;
	new.n = d.y;
	new.o = d.z;
	new.p = d.w;
	return(new);
}

void		print_mat4(t_mat4 to_print)
{
	ft_putstr("[");
	ft_putnbr(to_print.a);
	ft_putstr(" ");
	ft_putnbr(to_print.b);
	ft_putstr(" ");
	ft_putnbr(to_print.c);
	ft_putstr(" ");
	ft_putnbr(to_print.d);
	ft_putendl("]");
	ft_putstr("[");
	ft_putnbr(to_print.e);
	ft_putstr(" ");
	ft_putnbr(to_print.f);
	ft_putstr(" ");
	ft_putnbr(to_print.g);
	ft_putstr(" ");
	ft_putnbr(to_print.h);
	ft_putendl("]");
	ft_putstr("[");
	ft_putnbr(to_print.i);
	ft_putstr(" ");
	ft_putnbr(to_print.j);
	ft_putstr(" ");
	ft_putnbr(to_print.k);
	ft_putstr(" ");
	ft_putnbr(to_print.l);
	ft_putendl("]");
	ft_putstr("[");
	ft_putnbr(to_print.m);
	ft_putstr(" ");
	ft_putnbr(to_print.n);
	ft_putstr(" ");
	ft_putnbr(to_print.o);
	ft_putstr(" ");
	ft_putnbr(to_print.p);
	ft_putendl("]");
}

t_vec4		mult_mat4_vec4(t_mat4 matrice, t_vec4 vector)
{
	t_vec4		new;

	new.x = matrice.a * vector.x;
	new.x += matrice.b * vector.y;
	new.x += matrice.c * vector.z;
	new.x += matrice.d * vector.w;

	new.y = matrice.e * vector.x;
	new.y += matrice.f * vector.y;
	new.y += matrice.g * vector.z;
	new.y += matrice.h * vector.w;

	new.z = matrice.i * vector.x;
	new.z += matrice.j * vector.y;
	new.z += matrice.k * vector.z;
	new.z += matrice.l * vector.w;

	new.w = matrice.m * vector.x;
	new.w += matrice.n * vector.y;
	new.w += matrice.o * vector.z;
	new.w += matrice.p * vector.w;
	return (new);
}

t_mat4			translation_mat4(t_vec3 a)
{
	t_mat4	new;

	new.a = 1;
	new.b = 0;
	new.c = 0;
	new.d = a.x;

	new.e = 0;
	new.f = 1;
	new.g = 0;
	new.h = a.y;

	new.i = 0;
	new.j = 0;
	new.k = 1;
	new.l = a.z;

	new.m = 0;
	new.n = 0;
	new.o = 0;
	new.p = 1;
	return(new);
}

t_mat4			scale_mat4(t_vec3 scale)
{
	t_mat4		new;

	new.a = scale.x;
	new.b = 0;
	new.c = 0;
	new.d = 0;

	new.e = 0;
	new.f = scale.y;
	new.g = 0;
	new.h = 0;

	new.i = 0;
	new.j = 0;
	new.k = scale.z;
	new.l = 0;

	new.m = 0;
	new.n = 0;
	new.o = 0;
	new.p = 1;
	return(new);
}