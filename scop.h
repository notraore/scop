#ifndef SCOP_H
#define SCOP_H

#include "./libft/libft.h"
#include <stdio.h>

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <glfw3.h>
// #include <GLFW/glfw3.h>
#include <OpenGL/gl.h>

typedef struct s_glenv		t_glenv;
typedef struct s_vtx		t_vtx;

struct			s_glenv
{
	GLFWwindow			*window;
	double				ratio;
	int					width;
	int					height;
};

struct			s_vtx
{
	double		x;
	double		y;
	double		z;
};

#endif
