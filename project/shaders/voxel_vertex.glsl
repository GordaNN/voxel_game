#version 450 core

layout (location = 0) in vec3  in_position;
layout (location = 1) in vec3  in_color;
layout (location = 2) in float in_scale;

out vec3 voxel_color;

void main()
{
    gl_Position  = vec4(in_position, 1.0f);
    gl_PointSize = in_scale;
    voxel_color  = in_color;
}
