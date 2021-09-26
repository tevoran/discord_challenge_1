#ifndef DC_H
#define DC_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern SDL_Window *window;

//SDL_GLContext is an alias for *void
//therefore gl_context is a pointer
//this looks like a bad design decision by the SDL folks
extern SDL_GLContext gl_context;

extern GLuint vertex_shader;
extern GLuint fragment_shader;
extern GLuint shader;

void dc_init();
void dc_update();
void dc_using_shaders();
void dc_generate_mesh();
void dc_render_mesh();
void dc_rotate_mesh(float radians);
void dc_mat4_mul(GLfloat const a[4][4], GLfloat const b[4][4], GLfloat result[4][4]);




#endif