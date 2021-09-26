#include "dc.h"

void dc_update()
{
	SDL_GL_SwapWindow(window);
	glClearColor(0.0,0.0,0.0,1.0); //RGBA
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void dc_mat4_mul(GLfloat const a[4][4], GLfloat const b[4][4], GLfloat result[4][4])
{
	for(int x=0; x<4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			result[x][y]=a[x][0]*b[0][y]
						+a[x][1]*b[1][y]
						+a[x][2]*b[2][y]
						+a[x][3]*b[3][y];
		}
	}
}