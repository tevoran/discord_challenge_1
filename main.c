#include "dc.h"


int main()
{
	float rot_radian=0.0;
	dc_init();
	dc_using_shaders();
	dc_generate_mesh();
	for(int i=0; i<250; i++)
	{
		dc_render_mesh();
		dc_update();
		dc_rotate_mesh(rot_radian);
			rot_radian+=0.03;
		SDL_Delay(15);
	}
	//SDL_Delay(5000);




	//cleanup
	SDL_GL_DeleteContext(gl_context);
	SDL_Quit();
	return 0;
}