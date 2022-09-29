#version 330

in vec3 position;

out vec4 colour;

void main()
{
	vec2 aux = vec2(position.x, position.y);
	float i = 0.0;

	while(i < 100.0)
	{
		if(aux.x * aux.x + aux.y * aux.y > 4)
			break;
		aux = vec2(aux.x * aux.x - aux.y * aux.y, 2 * aux.x * aux.y) + vec2(position.x, position.y);
		i += 1.0;
	}

	if(i == 100.0)
	{
		colour = vec4(0.0, 0.0, 0.0, 1.0);
	}
	else
	{
		colour = vec4(cos(i*i), sin(i*i*i), cos(i*i) * sin(i), 1.0);
	}
}