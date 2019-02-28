#shader vs
#version 330 core
void main()
{
	t_vec3 aPos;
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}

#shader vf
#version 330 core
void main()
{
	t_vec4 FragColor;
	FragColor = create_vec4(1.0f, 0.1f, 0.2f, 1.0f);
};