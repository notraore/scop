/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/14 11:32:37 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STB_IMAGE_IMPLEMENTATION
#include "scop.h"

static const char *vs =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTexCoord;\n"

"smooth out vec3 sclr;\n"
"flat out vec3 oclr;\n"
"out vec2 TexCoord;\n"

"uniform mat4 mvp;\n"

"void main()\n"
"{\n"
	"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * mvp;\n"
	"oclr = aColor;\n"
	"sclr = aColor;\n"
	"TexCoord = aTexCoord;\n"
"}\n";

static const char *vf =
"#version 330 core\n"
"out vec4 FragColor;\n"

"smooth in vec3 sclr;\n"
"flat in vec3 oclr;\n"
"in vec2 TexCoord;\n"

"uniform sampler2D ourTexture;\n"

"uniform bool greymode;\n"
"uniform bool texmode;\n"
"uniform bool alphmode;\n"
"uniform bool smoothie;\n"

"void main(void)\n"
"{\n"
	"float grey = (0.2125 * oclr.x + 0.1154 * oclr.y + 0.021 * oclr.z);\n"
	"float sgrey = (0.2125 * sclr.x + 0.1154 * sclr.y + 0.021 * sclr.z);\n"
	"if (smoothie)\n"
		"FragColor = vec4(sclr, 1.0f);\n"
	"else\n"
		"FragColor = vec4(oclr, 1.0f);\n"
	"if (greymode)\n"
	"{\n"
		"if (smoothie)\n"
			"FragColor = vec4(sgrey, sgrey, sgrey, 1.0f);\n"
		"else\n"
			"FragColor = vec4(grey, grey, grey, 1.0f);\n"
	"}\n"

	"else if (texmode)\n"
		"FragColor = texture(ourTexture, TexCoord);\n"
	"else if (alphmode)\n"
	"{\n"
		"if (smoothie)\n"
			"FragColor = vec4(sclr, 0.4);\n"
		"else\n"
			"FragColor = vec4(oclr, 0.4);\n"
	"}\n"
"}\n";


void				print_fps_counter(t_glenv *env)
{
	env->current_time = glfwGetTime();
	env->frames++;
	if (env->current_time - env->last_time >= 0.2f)
	{
		ft_putnbr(env->frames);
		ft_putendl(" FPS");
		env->frames = 0;
		env->last_time += 1.0;
	}
}

void				end_program(t_glenv *env)
{
	glDeleteVertexArrays(1, &env->vao);
	glDeleteBuffers(1, &env->vbo);
	glfwDestroyWindow(env->window);
	glfwTerminate();
}

void				framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

void				apply_texture(t_glenv *env)
{
	int				index;

	index = 0;
	while (index < env->indices_nbr * 8)
	{
			env->vertices[index + 6] = 0.0f;
			env->vertices[index + 7] = 0.0f;
			index += 8;
			env->vertices[index + 6] = 0.0f;
			env->vertices[index + 7] = 1.0f;
			index += 8;
			env->vertices[index + 6] = 1.0f;
			env->vertices[index + 7] = 1.0f;
			index += 8;
			env->vertices[index + 6] = 1.0;
			env->vertices[index + 7] = 0.0;
			index += 8;
	}
}

void				apply_grey_shader(t_glenv *env)
{
	float		random;
	int			index;

	random = 0.5;
	index = 0;
	while (index < env->vtx_nbr * 8)
	{
		env->vertices[index + 3] = (((float)rand() / (float)(RAND_MAX)) / 1);
		env->vertices[index + 4] = (((float)rand() / (float)(RAND_MAX)) / 1);
		env->vertices[index + 5] = (((float)rand() / (float)(RAND_MAX)) / 1);
		index += 8;
	}
}

int					unite_all(t_glenv *env, bool tpressed)
{
	int			index;
	int			face_i;
	int			tex_i;
	int			clr;
	float		random;

	clr = 0;
	srand((unsigned int)time(NULL));

	index = 0;
	face_i = 0;
	tex_i = 0;
	random = 0;
	while (index < env->vtx_nbr * 8)
	{
		env->vertices[index] = (env->v_v[face_i]);
		env->vertices[index + 1] = (env->v_v[face_i + 1]);
		env->vertices[index + 2] = (env->v_v[face_i + 2]);
		index += 8;
		face_i += 3;
	}
	apply_grey_shader(env);
	((void)tpressed);
	apply_texture(env);
	return (0);
}

void				toggle_framed(t_glenv *env)
{
	if (env->framed == true)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void				reset_model(t_glenv *env)
{
	env->scaling = 9.0f;
	env->rotx = 0.0f;
	env->roty = 0.0f;
	env->rotz = 0.0f;
	env->new_pos.x = 0.0f;
	env->new_pos.y = 0.0f;
	env->new_pos.z = -50.0f;
	env->fov = 45.0f;
}

void				input_key(t_glenv *env)
{
	if (glfwGetKey(env->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->window, true);
	else if (glfwGetKey(env->window, GLFW_KEY_E) == GLFW_PRESS)
		env->new_pos.y += 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_Q) == GLFW_PRESS)
		env->new_pos.y -= 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_D) == GLFW_PRESS)
		env->new_pos.x -= 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_A) == GLFW_PRESS)
		env->new_pos.x += 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_W) == GLFW_PRESS)
		env->new_pos.z += 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_S) == GLFW_PRESS)
		env->new_pos.z -= 0.2f;
	else if (glfwGetKey(env->window, GLFW_KEY_I) == GLFW_PRESS)
			env->rotx += 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_O) == GLFW_PRESS)
			env->roty += 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_P) == GLFW_PRESS)
			env->rotz += 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_X) == GLFW_PRESS)
		env->scaling += 0.1;
	else if (glfwGetKey(env->window, GLFW_KEY_Z) == GLFW_PRESS)
		env->scaling -= 0.1;
	else if (glfwGetKey(env->window, GLFW_KEY_T) == GLFW_PRESS)
	{
		if (env->texmode == true)
		{
			env->texmode = false;
		}
	}
	else if (glfwGetKey(env->window, GLFW_KEY_Y) == GLFW_PRESS)
	{
		if (env->texmode == false)
		{
			env->texmode = true;
			env->greymode = false;
			env->alphmode = false;
		}
	}

	else if (glfwGetKey(env->window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (env->autorotate == false)
			env->autorotate = true;
		else
			env->autorotate = false;
	}

	else if (glfwGetKey(env->window, GLFW_KEY_L) == GLFW_PRESS)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (glfwGetKey(env->window, GLFW_KEY_K) == GLFW_PRESS)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else if (glfwGetKey(env->window, GLFW_KEY_SEMICOLON) == GLFW_PRESS)
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

	else if (glfwGetKey(env->window, GLFW_KEY_U) == GLFW_PRESS)
		reset_model(env);

	else if (glfwGetKey(env->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		env->greymode = false;
	else if (glfwGetKey(env->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		env->greymode = true;

	else if (glfwGetKey(env->window, GLFW_KEY_M) == GLFW_PRESS)
	{
		env->alphmode = false;
		if (env->greymode == true)
			env->greymode = false;
	}
	else if (glfwGetKey(env->window, GLFW_KEY_N) == GLFW_PRESS)
		env->alphmode = true;
	else if (glfwGetKey(env->window, GLFW_KEY_UP) == GLFW_PRESS)
		env->smoothiemode = true;
	else if (glfwGetKey(env->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		env->smoothiemode = false;

}

void				win_update(void *f(float), GLFWwindow *win)
{
	double last;
	double now;
	double delta;

	delta = 0.01f;
	last = glfwGetTime();
	(*f)(delta);
	glfwSwapBuffers(win);
	glfwPollEvents();
	now = glfwGetTime();
	delta = (now - last) * 10.0f;
}

void				auto_roty(t_glenv *env)
{
	env->roty += 0.2f;
}

int					check_shader(GLuint shader, GLint compiled)
{
	GLint	info_len;
	char	*info_log;

	info_len = 0;
	if (!compiled)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_len);
		if (info_len > 1)
		{
			info_log = malloc(sizeof(char) * info_len);
			glGetShaderInfoLog(shader, info_len, NULL, info_log);
			ft_putendl("Error compiling shader:");
			ft_putendl(info_log);
			free(info_log);
		}
		glDeleteShader(shader);
		return (0);
	}
	return (1);
}

int					check_program(GLuint program, GLint compiled)
{
	GLint info_len;
	char 	*info_log2;

	info_len = 0;
	if (!compiled)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_len);
		if (info_len > 1)
		{
			info_log2 = malloc(sizeof(char) * info_len);
			glGetProgramInfoLog(program, info_len, NULL, info_log2);
			ft_putendl("Error linking program:");
			ft_putendl(info_log2);
			free(info_log2);
		}
		glDeleteProgram(program);
		return (0);
	}
	return (1);
}

void				generate_buff_arr(t_glenv *env)
{
	glGenVertexArrays(1, &env->vao);
	glGenBuffers(1, &env->vbo);
	glGenBuffers(1, &env->ebo);
	glBindVertexArray(env->vao);
}

void				vertices_setter(t_glenv *env)
{
	generate_buff_arr(env);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(env->indices), env->indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(env->vertices), env->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void				init_glversion(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);
}

void				create_shader_prog(t_glenv *env)
{
	env->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	if (env->vertex_shader == 0)
		ft_kill("shader not created");
	glShaderSource(env->vertex_shader, 1, &vs, NULL);
	glCompileShader(env->vertex_shader);
	glGetShaderiv(env->vertex_shader, GL_COMPILE_STATUS, &env->compiled);
	if (!check_shader(env->vertex_shader, env->compiled))
		ft_kill("Shader compilation failed");
	env->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(env->fragment_shader, 1, &vf, NULL);
	glCompileShader(env->fragment_shader);
	glGetShaderiv(env->fragment_shader, GL_COMPILE_STATUS, &env->compiled);
	if (!check_shader(env->fragment_shader, env->compiled))
		ft_kill("Shader compilation failed");
	env->program = glCreateProgram();
	if (env->program == 0)
		ft_kill("env->Program error not created");
	glAttachShader(env->program, env->vertex_shader);
	glAttachShader(env->program, env->fragment_shader);
	glLinkProgram(env->program);
	glGetProgramiv(env->program, GL_LINK_STATUS, &env->compiled);
	if (!check_program(env->program, env->compiled))
		ft_kill("Program compilation failed");
}

void				create_env(t_glenv *env)
{
	if (!(env->window = glfwCreateWindow(980, 980, "Scop - 42", NULL, NULL)))
		ft_kill("Can't create window.");
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		ft_kill("Failed to initialize GLAD");
}

int					store_faces(t_glenv *env)
{
	int i;
	int tmp;
	char **tab;

	i = 1;
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		if (pos_atoi(env->split[i], &env->indices[env->ind]))
		{
			env->indices[env->ind] -= 1;
		}
		else
		{
			if (ft_isdigit(env->split[1][0]) && (ft_count_c(env->split[i], '/') == 1 || ft_count_c(env->split[i], '/') == 2))
			{
				tab = ft_strsplit(env->split[i], '/');

				if (tab_len(tab) != 2 && tab_len(tab) != 3)
				{
					free(tab);
					return (0);
				}
				if (tab_len(tab) == 2 && pos_atoi(tab[0], &env->indices[env->ind]) && pos_atoi(tab[1], &env->textures[env->ind]))
				{
					env->indices[env->ind] -= 1;
					env->textures[env->ind] -=1;
					if (!ft_isdigit(env->split[1][ft_strlen(env->split[1]) - 1]))
					{
						free(tab);
						return (0);
					}
				}
				else if (tab_len(tab) == 3 && pos_atoi(tab[0], &env->indices[env->ind]) && pos_atoi(tab[1], &env->textures[env->ind]) && pos_atoi(tab[2], &env->normales[env->ind]))
				{
					env->indices[env->ind] -= 1;
					env->textures[env->ind] -= 1;
					env->normales[env->ind] -= 1;
					if (!ft_isdigit(env->split[2][ft_strlen(env->split[2]) - 1]))
					{
						free(tab);
						return (0);
					}
				}
				else
				{
					free(tab);
					return 0;
				}
				free(tab);
			}
			else
				return (0);				
		}
		env->ind++;
		i++;
	}
	i = 1;
	if (env->four == true)
	{
		tmp = env->ind + 3;
		while (env->ind < tmp)
		{
			env->indices[env->ind] = ft_atoi(env->split[i]) - 1;
			env->ind++;
			i++;
			if (i == 2)
				i = 3;
		}
		env->indices_nbr += 3;
	}
	env->indices_nbr += 3;
	return (1);
}

void				separate_texture(t_glenv *env)
{
	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	env->data = (char *)stbi_load("texture/crate.jpg", &env->tex_width, &env->tex_height, &env->nrChannels, 0);
}

void				load_texture(t_glenv *env)
{
	
	if (env->data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, env->tex_width, env->tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, env->data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		ft_putendl("Failed to load the texture.");
	stbi_image_free(env->data);
}

int					parse_obj(t_glenv *env, char *srcpath)
{
	int 	v;
	int 	vn;

	v = 0;
	vn = 0;
	env->vtx_nbr = 0;
	// srand((unsigned int)time(NULL));

	// float nbr = 255;
	env->fd = open(srcpath, O_RDONLY);
	if (env->fd == -1)
		ft_kill("Open error");
	while (get_next_line(env->fd, &env->line))
	{
		env->split = ft_strsplit(env->line, ' ');
		if (env->line[0] == 'v' && env->line[1] == ' ')
		{
			if (!ft_atof(env->split[1], &env->v_v[env->vtx_nbr]) || !ft_atof(env->split[2], &env->v_v[env->vtx_nbr + 1]) || !ft_atof(env->split[3], &env->v_v[env->vtx_nbr + 2]))
			{
				return (0);
			}

			// printf("v0 = %f || v1 = %f || v2 = %f\n", env->v_v[v], env->v_v[v + 1], env->v_v[v + 2]);
			env->vtx_nbr += 3;
		}
		else if (env->line[0] == 'v' && env->line[1] == 't' && env->line[2] == ' ')
		{
			if (!ft_atof(env->split[1], &env->v_uv[env->vt]) || !ft_atof(env->split[2], &env->v_uv[env->vt + 1]))
			{
				return (0);
			}
			// printf("split0 = %s || split2 = %s\n", env->split[1], env->split[2]);
			// printf("v0 = %f || v1 = %f || v2 = %f\n", env->v_uv[vt], env->v_uv[vt + 1], env->v_uv[vt + 2]);
			env->vt += 2;
		}
		else if (env->line[0] == 'f')
		{
			if (tab_len(env->split) > 5)
			{

				return (0);
			}
			if (env->split[4])
				env->four = true;
			else
				env->four = false;
			if (!store_faces(env))
			{
				return (0);
			}
			env->face_nbr++;
		}
		else if (env->line[0] == 's')
		{
			if (tab_len(env->split) > 2)
				return (0);
			if (ft_strcmp(env->split[1], "1") == 0)
			{

			}
			else if (ft_strcmp(env->split[1], "off") == 0)
			{

			}
			else
			{
				return (0);
			}
		}
		free_tab(env->split);
	}
	return (1);
}

double	degree_to_radian(double degree_angle)
{
	return (degree_angle * ((float)PI / 180.0));
}

t_mat4				perspective(float fovy, float aspect, float near, float far)
{
	t_mat4		perspected;
	float		half;

	half = tanf(degree_to_radian(fovy) / 2.0f);
	perspected = create_mat4(0.0f);
	perspected.m[0][0] = 1.0f / (aspect * half);
	perspected.m[1][1] = 1.0f / (half);
	perspected.m[2][2] = -(far + near) / (far - near) * -1;
	perspected.m[2][3] = -1.5;
	perspected.m[3][2] = (2.0f * far * near) / (far - near) * -1;
	return (perspected);
}

void				reset_matrix(t_glenv *env)
{
	env->transform = create_mat4(1.0f);
	env->scale = create_mat4(1.0f);
	env->rotate[0] = create_mat4(1.0f);
	env->rotate[1] = create_mat4(1.0f);
	env->rotate[2] = create_mat4(1.0f);
}

void				render(t_glenv *env)
{
	reset_matrix(env);
	env->rotate[0] = make_rot_x(env->rotx);
	env->rotate[1] = make_rot_y(env->roty);
	env->rotate[2] = make_rot_z(env->rotz);
	env->trans = make_translation(&env->new_pos);
	env->scale = matrix_scale(env->scaling);
	env->transform = m4_x_m4(&env->transform, &env->proj);
	env->transform = m4_x_m4(&env->transform, &env->trans);
	env->transform = m4_x_m4(&env->transform, &env->rotate[0]);
	env->transform = m4_x_m4(&env->transform, &env->rotate[1]);
	env->transform = m4_x_m4(&env->transform, &env->rotate[2]);
	env->transform = m4_x_m4(&env->transform, &env->scale);
	if (env->autorotate)
		auto_roty(env);
	env->transformLoc = glGetUniformLocation(env->program, "mvp");
	env->greyloc = glGetUniformLocation(env->program, "greymode");
	env->texloc = glGetUniformLocation(env->program, "texmode");
	env->alphmodeloc = glGetUniformLocation(env->program, "alphmode");
	env->smoothieloc = glGetUniformLocation(env->program, "smoothie");
	glUseProgram(env->program);
	glUniformMatrix4fv(env->transformLoc, 1, GL_FALSE, &env->transform.m[0][0]);
	glUniform1i(env->greyloc, env->greymode);
	glUniform1i(env->texloc, env->texmode);
	glUniform1i(env->alphmodeloc, env->alphmode);
	glUniform1i(env->smoothieloc, env->smoothiemode);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glBindVertexArray(env->vao);
	glDrawElements(GL_TRIANGLES, env->indices_nbr, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(env->window);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void				init_variables(t_glenv *env)
{
	env->last_time = glfwGetTime();
	env->new_size = create_tvec3(1, 1, 1);
	env->new_pos = create_tvec3(0 , 0, 0);
	env->new_axis = create_tvec3(1, 0, 0);
	env->transform = create_mat4(1.0f);
	env->scaling = 9.0f;
	env->fov = 45.0f;
	env->new_pos.z = -50;
	env->proj = create_mat4(1.0f);
	env->proj = perspective(env->fov, 16 / 9, 1.0f, 100.0f);
	env->nbr = 1;
	env->ind = 0;
	env->mult = 1;
	env->autorotate = true;
	env->greymode = true;
	env->alphmode = false;
	env->smoothiemode = false;
}

int					main(int argc, char **argv)
{
	t_glenv		env;
	int			i;

	i = 0;
	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	init_glversion();
	ft_bzero(&env, sizeof(env));
	if (argc == 2)
		if (!parse_obj(&env, argv[1]))
			ft_kill("Error parser.");
	i = env.vtx_nbr * 3;
	env_shader_texture_vertices_var(&env);
	while (!glfwWindowShouldClose(env.window))
	{
		input_key(&env);
		print_fps_counter(&env);
		glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render(&env);
		glfwPollEvents();
	}
	end_program(&env);
	return (0);
}
