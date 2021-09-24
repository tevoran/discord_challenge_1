#include "dc.h"

void dc_update()
{
	glClearColor(0.5,0.6,0.1,1.0); //RGBA
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}