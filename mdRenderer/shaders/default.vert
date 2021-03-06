#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;


out vec2 TexCoords;
out vec3 FragPos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;


void main()
{
	FragPos = aPos.xyz; 
	TexCoords = aTexCoords;

	gl_Position = projection * view * model * vec4(FragPos, 1.0);
}