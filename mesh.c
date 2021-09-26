#include "dc.h"

#define ELEMENTS_PER_VERTEX 5
#define NUM_VERTICES 4
#define NUM_INDICES 6

GLfloat rot_mat[4][4]=
{
	1.0,	0.0,	0.0,	0.0,
	0.0,	1.0,	0.0,	0.0,
	0.0,	0.0,	1.0,	0.0,
	0.0,	0.0,	0.0,	1.0,
};

GLfloat vertices[]=
{
	//front
	-0.5,	-0.5,	0.0,	0.0,	0.0,
	0.5,	-0.5,	0.0,	0.0,	1.0,
	-0.5,	0.5,	0.0,	1.0,	0.0,
	0.5,	0.5,	0.0,	1.0,	1.0,

	//back
	-0.5,	-0.5,	0.5,	0.0,	0.0,
	0.5,	-0.5,	0.5,	0.0,	1.0,
	-0.5,	0.5,	0.5,	1.0,	0.0,
	0.5,	0.5,	0.5,	1.0,	1.0,
};

GLuint indices[]=
{
	//front
	0,1,2,
	1,2,3,

	//back
	4,5,6,
	5,6,7,
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
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindTexture(GL_TEXTURE_2D, to);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 7, 7, 0, GL_RGB, GL_FLOAT, texture);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER, 
		sizeof(indices), 
		indices, 
		GL_STATIC_DRAW);


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
	GLint mat_id;
	mat_id=glGetUniformLocation(shader, "rot_mat"); //shader is a global
	glUniformMatrix4fv(mat_id, 1, GL_FALSE, (const GLfloat*)rot_mat);
	glBindTexture(GL_TEXTURE_2D, to);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glDrawElements(
		GL_TRIANGLES, 
		NUM_INDICES, 
		GL_UNSIGNED_INT,
		NULL);
}

void dc_rotate_mesh(float radians)
{
	GLfloat tmp_rot_mat[4][4]=
	{
		cos(radians),	0.0,			sin(radians),	0.0,
		0.0,			1.0,			0.0,			0.0,
		-sin(radians),	0.0,			cos(radians),	0.0,
		0.0,			0.0,			0.0,			1.0,
	};

	for(int x=0; x<4; x++)
	{
		for(int y=0; y<4; y++)
		{
			rot_mat[x][y]=tmp_rot_mat[x][y];
		}
	}
}