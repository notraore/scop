
#include "scop.h"

void				generate_buff_arr(t_glenv *env)
{
	glGenVertexArrays(1, &env->vao);
	glGenBuffers(1, &env->vbo);
	glGenBuffers(1, &env->ebo);
	glBindVertexArray(env->vao);
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
	env->autorotate = true;
	env->greymode = true;
	env->alphmode = false;
	env->smoothiemode = false;
}

void				init_glversion(void)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);
}

void				env_shader_texture_vertices_var(t_glenv *env)
{
	init_variables(env);
	create_env(env);
	create_shader_prog(env);
	separate_texture(env);
	load_texture(env);
	unite_all(env);
	vertices_setter(env);
}

