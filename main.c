#include "dc.h"


int main()
{

	dc_init();
	dc_using_shaders();
	dc_generate_mesh();
	for(int i=0; i<10; i++)
	{
		dc_render_mesh();
		dc_update();
	}
	SDL_Delay(5000);




	//cleanup
	SDL_GL_DeleteContext(gl_context);
	SDL_Quit();
	return 0;
}