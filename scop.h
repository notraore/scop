#ifndef SCOP_H
#define SCOP_H
#define PI 3.1415926

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
	float		x;
	float		y;
	float		z;
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
	t_mat4				transform;

	t_mat4				scale;
	t_mat4				trans;
	t_mat4				rotate;

	t_vec3				new_pos;
	t_vec3				new_size;
	t_vec3				new_rot;
	t_vec3				new_axis;
	float				degree;
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
t_mat4		create_mat4(float homogene);
void		print_mat4(t_mat4 to_print);
void		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector);
t_mat4		translate_mat4(t_vec3 *new_pos);
// void		v_rotate_mat4(t_mat4 *transform, float degree, t_vec3 *axis, t_vec3 *pos);
// t_mat4		v_rotate_mat4(t_mat4 *transform, float degree, t_vec3 *axis);
void		make_rescale(t_mat4 *to_scale, t_vec3 *vector);
t_mat4		rescale_mat4(t_vec3 *new_size);
t_mat4		mat4_mult_mat4(t_mat4 *a, t_mat4 *b);
t_mat4		mat4_plus_mat4(t_mat4 *a, t_mat4 *b);

/* vector.c */
t_vec3		extract_vec3(t_mat4 *matrix);
t_vec4		create_tvec4(double x, double y, double z, double w);
t_vec3		create_tvec3(double x, double y, double z);
void		mult_mat4_vec3(t_mat4 *to_mult, t_vec3 *vector);

void		print_vec4(t_vec4 vec);
void		print_vec3(t_vec3 vec);

/*Rotation*/
t_mat4		rotate_mat4(float degree, t_vec3 *axis);
t_mat4		make_rot_x(float degree);
t_mat4		make_rot_y(float degree);
t_mat4		make_rot_z(float degree);

#endif
