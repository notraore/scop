/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/03 00:05:36 by bano             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STB_IMAGE_IMPLEMENTATION
#include "scop.h"

static const char *vs =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"layout (location = 2) in vec2 aTexCoord;\n"

"out vec3 ourColor;\n"
"out vec2 TexCoord;\n"

"uniform mat4 mvp;\n"

"void main()\n"
"{\n"
	"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * mvp;\n"
	// "gl_Position = mvp * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"ourColor = aColor;\n"
	"TexCoord = aTexCoord;\n"
"}\n";

static const char *vf =
"#version 330 core\n"
"out vec4 FragColor;\n"

"in vec3 ourColor;\n"
"in vec2 TexCoord;\n"

"uniform sampler2D ourTexture;\n"

"void main()\n"
"{\n"
	"FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0f);\n"
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
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void				input_key(t_glenv *env)
{
	if (glfwGetKey(env->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->window, true);
	else if (glfwGetKey(env->window, GLFW_KEY_UP) == GLFW_PRESS)
		env->new_pos.y += 0.002f;
	else if (glfwGetKey(env->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		env->new_pos.y -= 0.002f;
	else if (glfwGetKey(env->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		env->new_pos.x -= 0.002f;
	else if (glfwGetKey(env->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		env->new_pos.x += 0.002f;
	else if (glfwGetKey(env->window, GLFW_KEY_W) == GLFW_PRESS)
		env->new_pos.z += 0.002f;
	else if (glfwGetKey(env->window, GLFW_KEY_S) == GLFW_PRESS)
		env->new_pos.z -= 0.002f;



	else if (glfwGetKey(env->window, GLFW_KEY_I) == GLFW_PRESS)
			env->rotx = 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_O) == GLFW_PRESS)
			env->roty = 1.0f;
	else if (glfwGetKey(env->window, GLFW_KEY_P) == GLFW_PRESS)
			env->rotz = 1.0f;



	else if (glfwGetKey(env->window, GLFW_KEY_X) == GLFW_PRESS)
		env->scaling += 1;
	else if (glfwGetKey(env->window, GLFW_KEY_Z) == GLFW_PRESS)
		env->scaling -= 1;



	if (glfwGetKey(env->window, GLFW_KEY_I) == GLFW_RELEASE)
			env->rotx = 0.0f;
	if (glfwGetKey(env->window, GLFW_KEY_O) == GLFW_RELEASE)
			env->roty = 0.0f;
	if (glfwGetKey(env->window, GLFW_KEY_P) == GLFW_RELEASE)
			env->rotz = 0.0f;
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
	if (!(env->window = glfwCreateWindow(980, 700, "Scop - 42", NULL, NULL)))
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
	char **str;

	i = 1;
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		if (pos_atoi(env->split[i], &env->indices[env->ind])) {
			env->indices[env->ind] -= 1;
		}
		else
		{
			if (ft_isdigit(env->split[1][0]) && (ft_count_c(env->split[i], '/') == 1 || ft_count_c(env->split[i], '/') == 2))
			{
				str = ft_strsplit(env->split[i], '/');

				if (tab_len(str) != 2 && tab_len(str) != 3)
					return (0);
				if (tab_len(str) == 2 && pos_atoi(str[0], &env->indices[env->ind]) && pos_atoi(str[1], &env->textures[env->ind]))
				{
					env->indices[env->ind] -= 1;
					env->textures[env->ind] -=1;
					if (!ft_isdigit(env->split[1][ft_strlen(env->split[1]) - 1]))
						return (0);
				}
				else if (tab_len(str) == 3 && pos_atoi(str[0], &env->indices[env->ind]) && pos_atoi(str[1], &env->textures[env->ind]) && pos_atoi(str[2], &env->normales[env->ind]))
				{
					env->indices[env->ind] -= 1;
					env->textures[env->ind] -= 1;
					env->normales[env->ind] -= 1;
					if (!ft_isdigit(env->split[2][ft_strlen(env->split[2]) - 1]))
						return (0);
				}
				else
					return 0;
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

void				load_texture(t_glenv *env)
{
	glGenTextures(1, &env->texture);
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	env->data = stbi_load("texture/wall.jpg", &env->tex_width, &env->tex_height, &env->nrChannels, 0);
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
	int 	i;
	float color[9] = {
		1.0f, 0.0f, 0.0f,	// bottom right
		0.0f, 1.0f, 0.0f,	// bottom left
		0.0f, 0.0f, 1.0f};

	float tex_coords[8] = {
		1.0, 1.0,
		1.0, 0.0,
		0.0, 0.0,
		0.0, 1.0,
	};

	i = 0;
	env->fd = open(srcpath, O_RDONLY);
	if (env->fd == -1)
		ft_kill("Open error");
	while (get_next_line(env->fd, &env->line))
	{
		env->split = ft_strsplit(env->line, ' ');
		if (env->line[0] == 'v')
		{
			if (!ft_atof(env->split[1], &env->vertices[i]) || !ft_atof(env->split[2], &env->vertices[i + 1]) || !ft_atof(env->split[3], &env->vertices[i + 2]))
				return (0);

			/*Shader Color*/
			env->vertices[i + 3] = color[i % 9];
			env->vertices[i + 4] = color[(i + 1) % 9];
			env->vertices[i + 5] = color[(i + 2) % 9];
			/*Texture*/
			env->vertices[i + 6] = tex_coords[(i) % 8];
			env->vertices[i + 7] = tex_coords[(i + 1) % 8];
			// printf("i = %d\n", (i + 2) % 9);
			// printf("v.x = %f || v.y = %f || v.z = %f ||  clrv.z = %f ||  clrv.z = %f ||  clrv.z = %f\n", env->vertices[i], env->vertices[i + 1], env->vertices[i + 2], env->vertices[i + 3], env->vertices[i + 4], env->vertices[i + 5]);
			env->vtx_nbr++;
			// store_color(env);
			i += 8;
		}
		else if (env->line[0] == 'f')
		{	
			if (env->split[4])
				env->four = true;
			else
				env->four = false;
			if (!store_faces(env))
				return (0);
			env->face_nbr++;
		}
		free_tab(env->split);
	}
	// printf("face nbr = %d\n", env->face_nbr);
	// printf("vertex nbr = %d\n", env->vtx_nbr);
	// printf("indice nbr = %d\n", env->indices_nbr);
	return (1);
}

double	degree_to_radian(double degree_angle)
{
	double		radian_angle;

	radian_angle = degree_angle * (2.0 * PI / 360.0);
	return (radian_angle);
}

t_mat4				perspective(float fovy, float aspect, float near, float far)
{
	t_mat4		perspected;
	
	float		rad;
	float		half;

	rad = degree_to_radian(fovy);
	// rad = fovy;
	half = tan(rad / 2);


	perspected = create_mat4(0.0f);

	perspected.m[0][0] = (2 * near) / (aspect * half);
	// perspected.m[0][1] = 0;
	// perspected.m[0][2] = 0;
	// perspected.m[0][3] = 0;

	// perspected.m[1][0] = 0;
	perspected.m[1][1] = 1 / (half);
	// perspected.m[1][2] = 0;
	// perspected.m[1][3] = 0;

	// perspected.m[2][0] = 0;
	// perspected.m[2][1] = 0;
	perspected.m[2][2] = -(far + near) / (far - near);
	perspected.m[2][3] = -1.0;

	// perspected.m[3][0] = 0;
	// perspected.m[3][1] = 0;
	perspected.m[3][2] = - (2 * far * near) / (far - near);
	return (perspected);
}

int					main(int argc, char **argv)
{
	t_glenv		env;
	int				i;

	if (!glfwInit())
		ft_kill("Can't init GLFW.");
	init_glversion();
	ft_bzero(&env, sizeof(env));
	env.nbr = 1;
	env.ind = 0;
	if (argc == 2)
		if (!parse_obj(&env, argv[1]))
			ft_kill("Error Parser.");
	i = 0;
	while (i < env.vtx_nbr * 3)
	{
		i += 3;
	}
	create_env(&env);
	create_shader_prog(&env);
	load_texture(&env);
	vertices_setter(&env);
	env.last_time = glfwGetTime();

	env.new_size = create_tvec3(1, 1, 1);
	env.new_axis = create_tvec3(1, 0, 0);
	env.transform = create_mat4(1.0f);
	/****************************/
	t_mat4		full_transform;
	// t_mat4		mvp;
	/****************************/
	// t_mat4		proj;
	// t_mat4		view;

	/****************************/
	// t_vec3		pos = create_tvec3(0.0f, 0.0f, -3.0f);
	// t_vec3		dir = create_tvec3(0.0f, 0.0f, 0.0f);
	// t_vec3		up = create_tvec3(0.0f, 1.0f, 0.0f);

	// t_vec3		ex_trans;
	/****************************/

	// t_mat4		rot_x = create_mat4(1.0f);
	// t_mat4		rot_y;
	// t_mat4		rot_z;
	full_transform = create_mat4(1.0f);
	env.scale = create_mat4(1.0f);
	env.trans = create_mat4(1.0f);
	env.rotate[0] = create_mat4(1.0f);
	env.rotate[1] = create_mat4(1.0f);
	env.rotate[2] = create_mat4(1.0f);
	env.scaling = 1;

	while (!glfwWindowShouldClose(env.window))
	{
		input_key(&env);
		print_fps_counter(&env);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/******************************/
		/******************************/
		// view = lookat(&pos, &dir, &up);
		env.rotate[0] = make_rot_x(env.rotx);
		env.rotate[1] = make_rot_y(env.roty);
		env.rotate[2] = make_rot_z(env.rotz);

		env.scale = matrix_scale(env.scaling);
		full_transform = m4_x_m4(&full_transform, &env.scale);
		full_transform = m4_x_m4(&full_transform, &env.rotate[0]);
		full_transform = m4_x_m4(&full_transform, &env.rotate[1]);
		full_transform = m4_x_m4(&full_transform, &env.rotate[2]);
		// full_transform = m4_x_m4(&full_transform, &env.scale);
		// proj = perspective(degree_to_radian(45.0f), 980.0f / 700.0f, 1.0f, 10000.0f);
		// env.scale = matrix_scale(&env.new_size);
		printf("rotx = %f\n", env.rotx);
		print_mat4(full_transform);
		printf("\n");
		glUseProgram(env.program);
		env.transformLoc = glGetUniformLocation(env.program, "mvp");
		glUniformMatrix4fv(env.transformLoc, 1, GL_FALSE, &full_transform.m[0][0]);


		glBindVertexArray(env.vao);
		glDrawElements(GL_TRIANGLES, env.indices_nbr, GL_UNSIGNED_INT, 0);
		// glDrawArrays(GL_TRIANGLES, 0, env.indices_nbr);
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glfwSwapBuffers(env.window);
		glfwPollEvents();
	}
	end_program(&env);
	return (0);
}
