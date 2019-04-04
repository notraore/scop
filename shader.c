/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:32:59 by notraore          #+#    #+#             */
/*   Updated: 2019/03/27 17:33:25 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char				*parse_shader(char *path)
{
	FILE			*vs;
	int				size_s;
	char			*data;

	vs = fopen(path, "r");
	if (!vs)
		ft_kill("!vs");
	fseek(vs, 0L, SEEK_END);
	size_s = ftell(vs);
	fseek(vs, 0L, SEEK_SET);
	if (!(data = malloc(size_s * sizeof(char))))
		ft_kill("Couldn't allocate memory for shaders.");
	if (!fread(data, 1, size_s, vs))
		ft_kill("error while storing the shader file into string.");
	data[size_s] = '\0';
	fclose(vs);
	return (data);
}

void				vertices_setter(t_glenv *env)
{
	generate_buff_arr(env);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(GLuint) * env->ind_alloc, env->indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(GLfloat) * env->ver_alloc, env->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3,
		GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3,
		GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2,
		GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void				create_shader_prog(t_glenv *env)
{
	env->vs = parse_shader("./vs.shader");
	env->vf = parse_shader("./vf.blend");
	env->vtx_shader = glCreateShader(GL_VERTEX_SHADER);
	if (env->vtx_shader == 0)
		ft_kill("shader not created");
	glShaderSource(env->vtx_shader, 1, (const GLchar *const*)&env->vs, NULL);
	glCompileShader(env->vtx_shader);
	glGetShaderiv(env->vtx_shader, GL_COMPILE_STATUS, &env->compiled);
	if (!check_shader(env->vtx_shader, env->compiled))
		ft_kill("Shader compilation failed");
	env->frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(env->frag_shader, 1, (const GLchar *const*)&env->vf, NULL);
	glCompileShader(env->frag_shader);
	glGetShaderiv(env->frag_shader, GL_COMPILE_STATUS, &env->compiled);
	if (!check_shader(env->frag_shader, env->compiled))
		ft_kill("Shader compilation failed");
	env->program = glCreateProgram();
	if (env->program == 0)
		ft_kill("env->Program error not created");
	glAttachShader(env->program, env->vtx_shader);
	glAttachShader(env->program, env->frag_shader);
	glLinkProgram(env->program);
	glGetProgramiv(env->program, GL_LINK_STATUS, &env->compiled);
	if (!check_program(env->program, env->compiled))
		ft_kill("Program compilation failed");
}
