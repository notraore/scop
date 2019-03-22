/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:44:14 by arive-de          #+#    #+#             */
/*   Updated: 2019/03/22 15:44:16 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# define PI 3.1415926
# include "./libft/libft.h"
# include <stdio.h>
# define GLFW_INCLUDE_NONE
# include <glfw3.h>
# include <glad.h>
# include <math.h>
# include <time.h>
# include "stb_image.h"
# include <OpenGL/gl.h>
# include <stdbool.h>

typedef struct s_vec3		t_vec3;
typedef struct s_glenv		t_glenv;
typedef struct s_shader		t_shader;
typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;

struct		s_vec3
{
	float		x;
	float		y;
	float		z;
};

struct		s_mat4
{
	float		m[4][4];
};

struct		s_glenv
{
	GLFWwindow			*window;
	GLuint				program;
	GLuint				vertex_shader;
	GLuint				fragment_shader;
	GLint				compiled;
	unsigned int		vao;
	unsigned int		vbo;
	unsigned int		ebo;
	double				current_time;
	double				last_time;
	int					frames;
	char				*line;
	char				**split;
	int					fd;
	unsigned int		empty;
	int					face_nbr;
	int					vtx_nbr;
	int					vt;
	bool				four;
	float				vertices[200000];
	float				v_v[200000];
	float				v_uv[200000];
	float				v_vn[200000];
	unsigned int		indices[200000];
	unsigned int		textures[200000];
	unsigned int		normales[200000];
	unsigned int		indices_nbr;
	unsigned int		texture;
	int					tex_width;
	int					tex_height;
	int					nr_channels;
	unsigned char		*data;
	int					nbr;
	int					ind;
	unsigned int		transform_loc;
	unsigned int		id;
	t_vec3				sca_vec;
	t_vec3				rot_vec;
	t_vec3				tra_vec;
	t_mat4				transform;
	t_mat4				proj;
	t_mat4				scale;
	t_mat4				trans;
	t_mat4				rotate[3];
	float				rotx;
	float				roty;
	float				rotz;
	float				scaling;
	t_vec3				new_pos;
	t_vec3				new_size;
	t_vec3				new_rot;
	t_vec3				new_axis;
	float				degree;
	float				fov;
	bool				tpressed;
	bool				autorotate;
	bool				framed;
};

struct		s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
};

struct		s_shader
{
	char		*vs_str;
	char		*vf_str;
};

t_mat4		m4_x_m4(t_mat4 *transform, t_mat4 *rotation);

/*
 ** textures.c
*/
void		load_texture(t_glenv *env);

/*
 ** input_key.c
*/

void		input_key(t_glenv *env);

/*
 ** check.c
*/

int			check_shader(GLuint shader, GLint compiled);
int			check_program(GLuint program, GLint compiled);

/*
 ** init.c
*/

void		create_env(t_glenv *env);
void		create_shader_prog(t_glenv *env);
void		init_variables(t_glenv *env);
void		env_shader_texture_vertices_var(t_glenv *env);

/*
 ** utils.c
*/

double		dot_product(t_vec3 *a, t_vec3 *b);
t_vec3		v_v_subs(t_vec3 *a, t_vec3 *b);
t_vec3		v_v_mult(t_vec3 *a, t_vec3 *b);
double		degree_to_radian(double degree_angle);
void		print_fps_counter(t_glenv *env);

/*
 ** vertex_parser.c
*/

int			parse_vertex(t_glenv *env);
int			parse_obj(t_glenv *env, char *srcpath);

/*
 ** faces_parser.c
*/

int			stock_decrem(t_glenv *env, int nb);
int			parse_faces2(t_glenv *env, char **tab, int i);
int			parse_faces(t_glenv *env, int i);
int			store_faces(t_glenv *env);

/*
 ** matrice.c
*/

t_mat4		create_mat4(float homogene);
void		print_mat4(t_mat4 to_print);
void		mult_mat4_vec4(t_mat4 *to_mult, t_vec4 *vector);
t_mat4		translate_mat4(t_vec3 *new_pos);
t_mat4		rescale_mat4(t_vec3 *new_size);
t_mat4		matrix_scale(float value);

/*
 ** main.c
*/

int			unite_all(t_glenv *env, bool tpressed);
void		framebuffer_size_callback(GLFWwindow *window, \
									int width, int height);
void		vertices_setter(t_glenv *env);
void		make_rescale(t_mat4 *to_scale, t_vec3 *vector);
t_mat4		rescale_mat4(t_vec3 *new_size);
void		mult_mat4_vec3(t_mat4 *to_mult, t_vec3 *vector, t_mat4 *result);
t_mat4		mat4_plus_mat4(t_mat4 *a, t_mat4 *b);
void		plus_mat4_vec3(t_mat4 *to_plus, t_vec3 *vector);
void		mat4_mult_mat4(t_mat4 *a, t_mat4 *b, t_mat4 *result);

/*
 ** vector.c
*/

t_vec3		extract_vec3(t_mat4 *matrix);
t_vec4		create_tvec4(double x, double y, double z, double w);
t_vec3		create_tvec3(double x, double y, double z);
double		dot_product(t_vec3 *a, t_vec3 *b);
float		magnitude(t_vec3 *a);
t_vec3		v_v_subs(t_vec3 *a, t_vec3 *b);
t_vec3		normalize(t_vec3 *a);
t_vec3		v_v_mult(t_vec3 *a, t_vec3 *b);
t_mat4		lookat(t_vec3 *pos, t_vec3 *dir, t_vec3 *up);
t_mat4		mult_mvp(t_mat4 *p, t_mat4 *v, t_mat4 *m);
void		make_cam_trans(t_mat4 *translated, t_vec3 *new_pos);
void		print_vec4(t_vec4 vec);
void		print_vec3(t_vec3 vec);

/*
 ** rotation.c
*/

t_mat4		rotate_mat4(t_mat4 *transform, float degree, t_vec3 *axis);
t_mat4		make_rot_x(float degree);
t_mat4		make_rot_y(float degree);
t_mat4		make_rot_z(float degree);
t_mat4		make_translation(t_vec3 *src);

#endif
