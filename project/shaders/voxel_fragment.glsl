#version 450 core

in vec3 fragment_color;

out vec4 pixel_color;

void main()
{
    pixel_color = vec4(fragment_color, 1.0f);
}
