#ifndef SCOP_H
#define SCOP_H

#include "./libft/libft.h"
#include <stdio.h>

// #include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <glfw3.h>
#include <glad.h>
#include <math.h>
#include "stb_image.h"
// #include "glad/khrplatform.h"
// #include <GLFW/glfw3.h>

#include <OpenGL/gl.h>
#include <stdbool.h>

typedef struct s_vec3		t_vec3;
typedef struct s_glenv		t_glenv;

typedef struct s_shader		t_shader;

typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;

struct			s_vec3
{
	double		x;
	double		y;
	double		z;
};

struct			s_mat4
{
	float		m[4][4];
};

struct			s_glenv
{
	GLFWwindow			*window;
	/*SHADERS CREATION*/
	GLuint				program;
	GLuint				vertex_shader;
	GLuint				fragment_shader;
	GLint				compiled;

	/*VERTEX ARRAY AND VERTEX BUFFER*/
	unsigned int		vao;
	unsigned int		vbo;
	unsigned int		ebo;

	/*FPS COUNTER*/
	double				current_time;
	double				last_time;
	int					frames;

	/*Parsing file*/
	char				*line;
	char				**split;
	int					fd;
	/*File Info*/
	int					face_nbr;
	int					vtx_nbr;
	bool				four;

	float				vertices[200000];
	unsigned int		indices[200000];
	int					indices_nbr;

	/*TEXTURE*/
	unsigned int		texture;
	int					tex_width;
	int					tex_height;
	int					nrChannels;
	unsigned char		*data;
	int					nbr;
	int					ind;


	/*TRANSLATION*/
	unsigned int		transformLoc;
	unsigned int		id;
	/*Translation vector*/
	t_mat4				mat;
	float				newx;
	float				newy;
	float				newz;
	t_vec3				vector;
};

struct			s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
};

struct			s_shader
{
	char		*vs_str;
	char		*vf_str;
};




/* matrice.c */
t_mat4			create_translation_mat4(void);
t_mat4			translation_mat4(t_vec3 *vec);
void			print_mat4(t_mat4 to_print);
void			add_translation(t_glenv *e, t_vec3 *vec, t_mat4 *new);
t_mat4			make_translation_mat4(t_glenv *e, t_vec3 *vec);


/* vector.c */
t_vec4		create_tvec4(double x, double y, double z, double w);
t_vec3		create_tvec3(double x, double y, double z);
void		print_vec4(t_vec4 vec);
void		print_vec3(t_vec3 vec);
#endif
