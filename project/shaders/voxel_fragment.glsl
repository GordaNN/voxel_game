#version 450 core

in vec3 fragment_color;

void main()
{
    gl_FragColor = vec4(fragment_color, 1.0f);
}
