#include "dc.h"

#define ELEMENTS_PER_VERTEX 5
#define NUM_VERTICES 6

GLfloat vertices[]=
{
	-1.0,	-1.0,	0.1,	0.0,	0.0,
	1.0,	-1.0,	0.1,	0.0,	1.0,
	-1.0,	1.0,	0.1,	1.0,	0.0,

	1.0,	1.0,	0.1,	1.0,	1.0,
	-1.0,	1.0,	0.1,	1.0,	0.0,
	1.0,	-1.0,	0.1,	0.0,	1.0,
};

//7x7 pixel crate texture
#define DRK 0.482, 0.176, 0.063,
#define MED 0.525, 0.216, 0.098,
#define LIT	0.639, 0.310, 0.184,

GLfloat texture[]=
{
	DRK DRK DRK DRK DRK DRK DRK
	DRK MED LIT LIT LIT MED DRK
	DRK LIT MED LIT MED LIT DRK
	DRK LIT LIT MED LIT LIT DRK
	DRK LIT MED LIT MED LIT DRK
	DRK MED LIT LIT LIT MED DRK
	DRK DRK DRK DRK DRK DRK DRK
};

GLuint vao; //vertex array object
GLuint vbo; //vertex buffer object
GLuint ibo; //index buffer object
GLuint to; //texture object

void dc_generate_mesh()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenTextures(1, &to);
	//glGenBuffers(1, &ibo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindTexture(GL_TEXTURE_2D, to);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 7, 7, 0, GL_RGB, GL_FLOAT, texture);

	glVertexAttribPointer(
		0, 
		3, 
		GL_FLOAT, 
		GL_FALSE, 
		ELEMENTS_PER_VERTEX*sizeof(GLfloat),
		(void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1, 
		2, 
		GL_FLOAT, 
		GL_FALSE, 
		ELEMENTS_PER_VERTEX*sizeof(GLfloat),
		(void*)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}

void dc_render_mesh()
{
	glBindTexture(GL_TEXTURE_2D, to);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, NUM_VERTICES);
}