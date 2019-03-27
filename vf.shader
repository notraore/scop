#version 330 core
out vec4 FragColor;

smooth in vec3 sclr;
flat in vec3 oclr;
in vec2 TexCoord;

uniform sampler2D ourTexture;

uniform bool greymode;
uniform bool texmode;
uniform bool alphmode;
uniform bool smoothie;

void main(void)
{
	float grey = (0.2125 * oclr.x + 0.1154 * oclr.y + 0.021 * oclr.z);
	float sgrey = (0.2125 * sclr.x + 0.1154 * sclr.y + 0.021 * sclr.z);
	if (smoothie)
		FragColor = vec4(sclr, 1.0f);
	else
		FragColor = vec4(oclr, 1.0f);
	if (greymode)
	{
		if (smoothie)
			FragColor = vec4(sgrey, sgrey, sgrey, 1.0f);
		else
			FragColor = vec4(grey, grey, grey, 1.0f);
	}

	else if (texmode)
		FragColor = texture(ourTexture, TexCoord);
	else if (alphmode)
	{
		if (smoothie)
			FragColor = vec4(sclr, 0.4);
		else
			FragColor = vec4(oclr, 0.4);
	}
}
