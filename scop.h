#ifndef SCOP_H
#define SCOP_H

#include "./libft/libft.h"
#include <stdio.h>

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>

typedef struct s_glenv t_glenv;

struct			s_glenv
{
	GLFWwindow			*window;
	double				ratio;
	int					width;
	int					height;
};

#endif
