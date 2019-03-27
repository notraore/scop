#ifndef SCOP_H
#define SCOP_H
#define PI 3.1415926

#include "./libft/libft.h"
#include <stdio.h>

#define GLFW_INCLUDE_NONE
#include <glfw3.h>
#include <glad.h>
#include <math.h>
#include <time.h>

#include <OpenGL/gl.h>


#include <stdbool.h>


typedef struct s_vec3		t_vec3;
typedef struct s_glenv		t_glenv;

typedef struct s_shader		t_shader;

typedef struct s_vec4		t_vec4;
typedef struct s_mat4		t_mat4;
typedef struct s_header		t_header;
typedef struct s_dib		t_dib;

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

typedef struct	s_bmp_header
{
	char		type[2];
	unsigned	size;
	short		reserved1;
	short		reserved2;
	unsigned	data_offset;
}				t_bmp_header;

typedef struct	s_bmp_dib_header
{
	unsigned	header_size;
	int			image_width;
	int			image_height;
	short		color_planes;
	short		bits_per_pixel;
	unsigned	compression_method;
	unsigned	image_size;
	int			horizontal_resolution;
	int			vertical_resolution;
	int			colors;
	int			important_colors;
}				t_bmp_dib_header;

struct			s_header
{
	unsigned short int	h_type;
	unsigned int		h_size;
	unsigned short int	h_reserved1;
	unsigned int		h_reserved2;
	unsigned int		h_offset;
};

struct			s_dib
{
	unsigned int		bmp_size;
	int 				bmp_width;
	int					bmp_height;
	unsigned short int	bmp_planes;
	unsigned short int	bmp_bits;
	unsigned int		bmp_compression;
	unsigned int		bmp_imagesize;
	int					bmp_xresolution;
	int					bmp_yresolution;
	unsigned int		bmp_ncolours;
	unsigned int		bmp_importantcolours;
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
	int					vt;
	bool				four;

	float				vertices[200000];
	float				v_v[200000];
	float				v_uv[200000];
	float				uv_new[200000];
	float				v_vn[200000];

	unsigned int		indices[200000];
	unsigned int		textures[200000];
	unsigned int		normales[200000];
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

	GLuint				greyloc;
	GLuint				texloc;
	GLuint				smoothieloc;
	GLuint				alphmodeloc;

	bool				greymode;
	bool				texmode;
	bool				alphmode;
	bool				smoothiemode;

	bool				autorotate;
	bool				framed;
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
/*
**main.c
*/
int					store_faces(t_glenv *env);
int					parse_obj(t_glenv *env, char *srcpath);

/*
**input_key.c
*/
void				input_key(t_glenv *env);
void				input_key2(t_glenv *env);
void				input_key3(t_glenv *env);

/*
**parse_bmp.c
*/
int					test_file(FILE *file, unsigned char *header);
unsigned char		*read_bmp(FILE *file, unsigned char *header, t_glenv *env);
unsigned char		*parse_bmp(char const *pathname, t_glenv *env);
/*
**functions.c
*/
void				reset_model(t_glenv *env);
void				end_program(t_glenv *env);
void				framebuffer_size_callback(GLFWwindow *window, int width, int height);
void				auto_roty(t_glenv *env);
double				degree_to_radian(double degree_angle);
/*
**frames_counter.c
*/
void				print_fps_counter(t_glenv *env);
void				win_update(void *f(float), GLFWwindow *win);
/*
**checker.c
*/
int					check_shader(GLuint shader, GLint compiled);
int					check_program(GLuint program, GLint compiled);

/*
**shader.c
*/
void				vertices_setter(t_glenv *env);
void				create_shader_prog(t_glenv *env);
/*
**textures.c
*/

void				apply_texture(t_glenv *env);
void				separate_texture(t_glenv *env);
void				load_texture(t_glenv *env);
/*
**render_model.c
*/
void				apply_grey_shader(t_glenv *env);
int					unite_all(t_glenv *env);
void				render(t_glenv *env);
/*
**matrix.c
*/
t_mat4				perspective(float fovy, float aspect, float near, float far);
void				reset_matrix(t_glenv *env);
void				create_final_matrix(t_glenv *env);

/*
**matrices.c
*/
void				make_rescale(t_mat4 *to_scale, t_vec3 *vector);
t_mat4				create_mat4(float homogene);
t_mat4				make_translation(t_vec3 *src);
t_mat4				m4_x_m4(t_mat4 *a, t_mat4 *b);
t_mat4				matrix_scale(float value);
/*
**init.c
*/
void				generate_buff_arr(t_glenv *env);
void				create_env(t_glenv *env);
void				init_variables(t_glenv *env);
void				init_glversion(void);
void				env_shader_texture_vertices_var(t_glenv *env);

/*
**vector.c
*/
t_vec3				create_tvec3(double x, double y, double z);
float				magnitude(t_vec3 *a);
t_vec3				normalize(t_vec3 *a);
t_vec3				v_v_subs(t_vec3 *a, t_vec3 *b);
t_vec3				v_v_mult(t_vec3 *a, t_vec3 *b);

/*
**rotation.c
*/
t_mat4		make_rot_x(float degree);
t_mat4		make_rot_y(float degree);
t_mat4		make_rot_z(float degree);
#endif
