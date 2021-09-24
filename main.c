#include "dc.h"


int main()
{

	dc_init();

	SDL_Delay(2000);




	//cleanup
	SDL_GL_DeleteContext(gl_context);
	SDL_Quit();
	return 0;
}