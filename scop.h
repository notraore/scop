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
	t_vec3				sca_vec;
	t_vec3				rot_vec;
	t_vec3				tra_vec;
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

	/*CAMERA*/
	t_vec3				cam_pos;
	t_vec3				cam_dir;
	t_vec3				cam_tar;
	t_vec3				cam_right;
	t_vec3				cam_up;



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


t_mat4		m4_x_m4(t_mat4 *transform, t_mat4 *rotation);


/* matrice.c */
t_mat4		create_mat4(float homogene);
void		print_mat4(t_mat4 to_print);
void		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector);
t_mat4		translate_mat4(t_vec3 *new_pos);
t_mat4		rescale_mat4(t_vec3 *new_size);





void		make_rescale(t_mat4 *to_scale, t_vec3 *vector);
t_mat4		rescale_mat4(t_vec3 *new_size);

void		mult_mat4_vec3(t_mat4 *to_mult, t_vec3 *vector, t_mat4 *result);

t_mat4		mat4_plus_mat4(t_mat4 *a, t_mat4 *b);

void		plus_mat4_vec3(t_mat4 *to_plus, t_vec3 *vector);

void		mat4_mult_mat4(t_mat4 *a, t_mat4 *b, t_mat4 *result);

/* vector.c */
t_vec3		extract_vec3(t_mat4 *matrix);
t_vec4		create_tvec4(double x, double y, double z, double w);
t_vec3		create_tvec3(double x, double y, double z);
// void		mult_mat4_vec3(t_mat4 *to_mult, t_vec3 *vector);
double		dot_product(t_vec3 *a, t_vec3 *b);

float		magnitude(t_vec3 *a);
t_vec3		v_v_subs(t_vec3 *a, t_vec3 *b);
t_vec3		normalize(t_vec3 *a);
t_vec3		v_v_mult(t_vec3 *a, t_vec3 *b);
// t_mat4		lookat(t_vec3 *pos, t_vec3 *dir, t_vec3 *up);
t_mat4		lookat(t_vec3 *pos, t_vec3 *dir, t_vec3 *up);
t_mat4		mult_mvp(t_mat4 *p, t_mat4 *v, t_mat4 *m);
void		make_cam_trans(t_mat4 *translated, t_vec3 *new_pos);


void		print_vec4(t_vec4 vec);
void		print_vec3(t_vec3 vec);

/*Rotation*/
t_mat4		rotate_mat4(t_mat4 *transform, float degree, t_vec3 *axis);
t_mat4		make_rot_x(t_mat4 *transform, float degree);
t_mat4		make_rot_y(t_mat4 *transform, float degree);
t_mat4		make_rot_z(t_mat4 *transform, float degree);

#endif
