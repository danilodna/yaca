#version 330 core
out vec4 FragColor;

in vec3 outColor;

void main()
{
    FragColor = outColor;
}