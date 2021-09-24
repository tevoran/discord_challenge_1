#include "dc.h"

void dc_init()
{
	SDL_Init(
		SDL_INIT_TIMER |
		SDL_INIT_VIDEO |
		SDL_INIT_EVENTS);

	window=SDL_CreateWindow(
		"T3V's cool challenge entry",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600,
		600,
		SDL_WINDOW_OPENGL);
		//if windows wasn't successfully created then give out and error
		if(window==NULL)
		{
			printf("ERROR: SDL couldn't create a window\n");
		}

	if(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4)!=0)
	{
		printf("ERROR: OpenGL 4.5 is not supported\n");
	}

	if(SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5)!=0)
	{
		printf("ERROR: OpenGL 4.5 is not supported\n");
	}

	//SDL_GLContext is an alias for *void
	//therefore glcontext is a pointer
	//this looks like a bad design decision by the SDL folks
	SDL_GLContext glcontext=SDL_GL_CreateContext(window);
		if(glcontext==NULL)
		{
			printf("ERROR: OpenGL context couldn't be created\n");
		}

	if(glewInit()!=GLEW_OK)
	{
		printf("ERROR: GLEW couldn't be initialized\n");
	}

	glClearColor(0.5,0.6,0.1,1.0); //RGBA
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}
