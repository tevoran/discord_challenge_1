#version 450

in vec2 tex_coords_frag;

uniform sampler2D fragment_texture;

out vec4 color;

void main()
{
	color = texture(fragment_texture, tex_coords_frag);
}
