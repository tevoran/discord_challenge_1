#version 450

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 tex_coords;

out vec2 tex_coords_frag;

void main()
{
	tex_coords_frag = tex_coords;
	gl_Position = vec4(pos, 1.0);
}