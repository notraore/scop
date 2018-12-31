/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:22:43 by notraore          #+#    #+#             */
/*   Updated: 2018/12/05 17:22:44 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
#define SCOP_H

#include "../libft/libft.h"
#ifdef WIN32
#include <GL/glew.h>
#else
#define GL3_PROTOTYPES 1
#include <OpenGL/gl3.h>
#endif
// #include <../glfw/include/GLFW/glfw3.h>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_opengl.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
typedef struct	s_vertex		t_vertex;
typedef struct	s_face			t_face;

struct			s_vertex
{
	int							id;
	double						x;
	double						y;
	double						z;
	struct s_vertex				*next;
};

struct			s_face
{
	int			id;
	double		x;
	double		y;
	double		z;
	double		facen;
	bool		four;
};

void		ft_kill(char *str);

#endif
