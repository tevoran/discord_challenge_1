#version 450

in vec2 tex_coords_frag;
in float z;

uniform sampler2D fragment_texture;

out vec4 color;

void main()
{
	//vec4(z,z,z,1.0);//
	color = texture(fragment_texture, tex_coords_frag);
}
