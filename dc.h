#ifndef DC_H
#define DC_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include <stdio.h>

extern SDL_Window *window;

//SDL_GLContext is an alias for *void
//therefore gl_context is a pointer
//this looks like a bad design decision by the SDL folks
extern SDL_GLContext gl_context;

void dc_init();

#endif