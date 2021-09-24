#include "dc.h"

SDL_Window *window;

//SDL_GLContext is an alias for *void
//therefore gl_context is a pointer
//this looks like a bad design decision by the SDL folks
SDL_GLContext gl_context;

GLuint vertex_shader;
GLuint fragment_shader;
GLuint shader;