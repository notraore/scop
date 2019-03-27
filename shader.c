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