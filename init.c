
#include "scop.h"

void				env_shader_texture_vertices_var(t_glenv *env)
{
	init_variables(env);
	create_env(env);
	create_shader_prog(env);
	separate_texture(env);
	load_texture(env);
	unite_all(env, env->tpressed);
	vertices_setter(env);
}