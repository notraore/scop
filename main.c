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

"uniform mat4 transform;\n"

"void main()\n"
"{\n"
	"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * transform;\n"
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
		env->new_pos.y += 0.02;
	else if (glfwGetKey(env->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		env->new_pos.y -= 0.02;
	else if (glfwGetKey(env->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		env->new_pos.x -= 0.02;
	else if (glfwGetKey(env->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		env->new_pos.x += 0.02;
	else if (glfwGetKey(env->window, GLFW_KEY_W) == GLFW_PRESS)
		env->new_pos.z += 0.02;
	else if (glfwGetKey(env->window, GLFW_KEY_S) == GLFW_PRESS)
		env->new_pos.z -= 0.02;
	else if (glfwGetKey(env->window, GLFW_KEY_X) == GLFW_PRESS)
	{
		env->new_size.x += 0.02;
		env->new_size.y += 0.02;
		env->new_size.z += 0.02;
	}
	else if (glfwGetKey(env->window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		env->new_size.x -= 0.02;
		env->new_size.y -= 0.02;
		env->new_size.z -= 0.02;
	}
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
	if (!(env->window = glfwCreateWindow(980, 980, "Scop - 42", NULL, NULL)))
		ft_kill("Can't create window.");
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		ft_kill("Failed to initialize GLAD");
}

void				store_faces(t_glenv *env)
{
	int i;
	int tmp;

	i = 1;
	tmp = env->ind + 3;
	while (env->ind < tmp)
	{
		env->indices[env->ind] = ft_atoi(env->split[i]) - 1;
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

void				parse_obj(t_glenv *env, char *srcpath)
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
			env->vertices[i] = ft_atof(env->split[1]);
			env->vertices[i + 1] = ft_atof(env->split[2]);
			env->vertices[i + 2] = ft_atof(env->split[3]);
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
			store_faces(env);
			env->face_nbr++;
		}
		free_tab(env->split);
	}
	// printf("face nbr = %d\n", env->face_nbr);
	// printf("vertex nbr = %d\n", env->vtx_nbr);
	// printf("indice nbr = %d\n", env->indices_nbr);
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
		parse_obj(&env, argv[1]);
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
	env.new_pos.x = 0;
	env.new_pos.y = 0;
	env.new_pos.z = 0;
	env.new_size.x = 1;
	env.new_size.y = 1;
	env.new_size.z = 1;
	env.new_axis.x = 1;
	env.new_axis.y = 0;
	env.new_axis.z = 0;
	env.new_rot.x = 0;
	env.new_rot.y = 0;
	env.new_rot.z = 0;
	while (!glfwWindowShouldClose(env.window))
	{
		input_key(&env);
		print_fps_counter(&env);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		env.transform = create_mat4(1.0f);
		env.scale = create_mat4(1.0f);
		env.trans = create_mat4(1.0f);
		env.rotate = create_mat4(1.0f);
		env.trans = translate_mat4(&env.trans, &env.new_pos);
		env.scale = rescale_mat4(&env.scale, &env.new_size);
		env.rotate = rotate_mat4(&env.rotate, 1.5708f, &env.new_axis, &env.new_rot);
		// env.rotate = rotate_mat4(&env.rotate, (float)glfwGetTime(), &env.new_rot);

		print_mat4(env.transform);
		env.transform = mat4_plus_mat4(&env.scale, &env.trans);
		env.transform = mat4_plus_mat4(&env.transform, &env.rotate);
		glUseProgram(env.program);
		// env.new_size.x += 0.0001;
		// env.new_size.y += 0.0001;
		// env.new_size.z += 0.0001;
		env.transformLoc = glGetUniformLocation(env.program, "transform");
		glUniformMatrix4fv(env.transformLoc, 1, GL_FALSE, &env.transform.m[0][0]);
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
