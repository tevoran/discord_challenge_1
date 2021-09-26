#include "dc.h"

void dc_update()
{
	SDL_GL_SwapWindow(window);
	glClearColor(0.0,0.0,0.0,1.0); //RGBA
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}