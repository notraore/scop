#include "scop.h"

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

void				create_final_matrix(t_glenv *env)
{
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
}
