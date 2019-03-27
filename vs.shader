#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

smooth out vec3 sclr;
flat out vec3 oclr;
out vec2 TexCoord;

uniform mat4 mvp;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * mvp;
	oclr = aColor;
	sclr = aColor;
	TexCoord = aTexCoord;
}
