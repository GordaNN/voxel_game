#version 450 core

layout (points) in;
layout(triangle_strip, max_vertices = 9) out;

in vec3 voxel_color[];

out vec3 fragment_color;

uniform mat4 matrix_mvp;
uniform vec3 camera_position;

void main() {
    /* Save color */
    fragment_color = voxel_color[0];
    
    /* Calculate delta of primitive's vertexes */
    const vec3 delta = vec3(float(camera_position.x - gl_in[0].gl_Position.x < 0.0f),
                            float(camera_position.y - gl_in[0].gl_Position.y < 0.0f),
                            float(camera_position.z - gl_in[0].gl_Position.z < 0.0f));


    /* Calculate, transform and draw primitive primitive */

    /* Vertex 0 */
    gl_Position = matrix_mvp * (vec4(0.5f - delta.z, delta.y - 0.5f, delta.x - 0.5f, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    EmitVertex();

    /* Vertex 1 */
    const vec4 vertex_1 = matrix_mvp * (vec4(0.5f - delta.x, delta.y - 0.5f, 0.5f - delta.z, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    gl_Position = vertex_1;
    EmitVertex();

    /* Vertex 2 */
    gl_Position = matrix_mvp * (vec4(0.5f - delta.z, 0.5f - delta.y, delta.x - 0.5f, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    EmitVertex();

    /* Vertex 3 */
    const vec4 vertex_3 = matrix_mvp * (vec4(0.5f - delta.x, 0.5f - delta.y, 0.5f - delta.z, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    gl_Position = vertex_3;
    EmitVertex();

    /* Vertex 4 */
    gl_Position = matrix_mvp * (vec4(delta.x - 0.5f, 0.5f - delta.y, delta.z - 0.5f, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    EmitVertex();

    /* Vertex 3 */
    gl_Position = vertex_3;
    EmitVertex();

    /* Vertex 5 */
    gl_Position = matrix_mvp * (vec4(delta.z - 0.5f, 0.5f - delta.y, 0.5f - delta.x, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    EmitVertex();

    /* Vertex 1 */
    gl_Position = vertex_1;
    EmitVertex();

    /* Vertex 6 */
    gl_Position = matrix_mvp * (vec4(delta.z - 0.5f, delta.y - 0.5f, 0.5f - delta.x, 0.0f) * gl_in[0].gl_PointSize + gl_in[0].gl_Position);
    EmitVertex();

    EndPrimitive();
}
