#version 450

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 tex_coords;

uniform mat4 rot_mat;
uniform mat4 pos_mat;
uniform mat4 proj_mat;

out vec2 tex_coords_frag;
out float z;

void main()
{
	tex_coords_frag = tex_coords;
	vec4 pos = proj_mat * pos_mat * rot_mat * vec4(pos, 1.0);
	gl_Position = pos;
	z = pos.w;
}	