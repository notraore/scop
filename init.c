/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bano <bano@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:01:29 by notraore          #+#    #+#             */
/*   Updated: 2019/03/22 14:59:13 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// "FragColor = vec4(ourColor, 1.0f);\n"
	"FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0f);\n"
"}\n";

void				create_env(t_glenv *env)
{
	if (!(env->window = glfwCreateWindow(980, 980, "Scop - 42", NULL, NULL)))
		ft_kill("Can't create window.");
	glfwMakeContextCurrent(env->window);
	glfwSetFramebufferSizeCallback(env->window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		ft_kill("Failed to initialize GLAD");
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

void				init_variables(t_glenv *env)
{
	env->last_time = glfwGetTime();
	env->new_size = create_tvec3(1, 1, 1);
	env->new_pos = create_tvec3(0, 0, 0);
	env->new_axis = create_tvec3(1, 0, 0);
	env->transform = create_mat4(1.0f);
	env->scaling = 9.0f;
	env->fov = 45.0f;
	env->new_pos.z = -50;
	env->proj = create_mat4(1.0f);
	env->proj = perspective(env->fov, 16 / 9, 1.0f, 100.0f);
	env->nbr = 1;
	env->ind = 0;
	env->autorotate = true;
}

void				env_shader_texture_vertices_var(t_glenv *env)
{
	create_env(env);
	create_shader_prog(env);
	load_texture(env);
	unite_all(env, env->tpressed);
	vertices_setter(env);
	init_variables(env);
}
