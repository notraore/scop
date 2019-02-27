#ifndef SCOP_H
#define SCOP_H

#include "./libft/libft.h"
#include <stdio.h>

// #include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <glfw3.h>
// #include <GLFW/glfw3.h>
#include <OpenGL/gl.h>

typedef struct s_glenv		t_glenv;
typedef struct s_vec3		t_vec3;
typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;

struct			s_glenv
{
	GLFWwindow			*window;
	double				ratio;
	int					width;
	int					height;
};

struct			s_vec3
{
	double		x;
	double		y;
	double		z;
};

struct			s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
};

struct			s_mat4
{
	double		a;
	double		b;
	double		c;
	double		d;

	double		e;
	double		f;
	double		g;
	double		h;

	double		i;
	double		j;
	double		k;
	double		l;

	double		m;
	double		n;
	double		o;
	double		p;
};



/* matrice.c */
t_vec4			create_tvec4(double x, double y, double z, double w);
t_mat4			translation_mat4(t_vec3 a);
t_mat4			scale_mat4(t_vec3 scale);
t_vec4			mult_mat4_vec4(t_mat4 matrice, t_vec4 vector);
void			print_mat4(t_mat4 to_print);


/* vector.c */
t_vec4		create_tvec4(double x, double y, double z, double w);
t_vec3		create_tvec3(double x, double y, double z);
void		print_vec4(t_vec4 vec);
void		print_vec3(t_vec3 vec);
#endif
