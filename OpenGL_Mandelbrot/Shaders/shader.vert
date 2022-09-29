#version 330

layout (location = 0) in vec3 pos;


out vec3 position;
uniform vec3 deslocamento;

void main()
{
	gl_Position = vec4(pos, 1.0);
	position = deslocamento+pos/deslocamento.z;
}