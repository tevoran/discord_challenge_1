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
	gl_context=SDL_GL_CreateContext(window);
		if(gl_context==NULL)
		{
			printf("ERROR: OpenGL context couldn't be created\n");
		}

	if(glewInit()!=GLEW_OK)
	{
		printf("ERROR: GLEW couldn't be initialized\n");
	}

	//activating Z-Buffering
	//standard clear depth is used
	//standard depth range is used
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//rendering full triangles
}
