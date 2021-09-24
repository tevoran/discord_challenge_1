#include "dc.h"


void dc_using_shaders()
{
	GLenum error;

	char *shader_buffer=NULL;
	FILE *shader_file=NULL;
	unsigned int shader_size;

	//vertex shader
	shader_file=fopen("vertex.glsl","r");
	if(shader_file==NULL)
	{
		printf("ERROR: vertex shader couldn't be found\n");
	}

	fseek(shader_file, 0, SEEK_END);
	shader_size=ftell(shader_file);
	shader_size++;
	fseek(shader_file, 0, SEEK_SET);

	shader_buffer=malloc(shader_size);
	fread(shader_buffer, shader_size, 1, shader_file);
	shader_buffer[shader_size]='\0';

	vertex_shader=glCreateShader(GL_VERTEX_SHADER);
	if(vertex_shader==GL_INVALID_ENUM)
	{
		printf("ERROR: OpenGL couldn't create a vertex shader\n");
	}

	const GLchar *vertex_shader_ref_ptr=shader_buffer;
	glShaderSource(vertex_shader, 1, &vertex_shader_ref_ptr, NULL);
	error=glGetError();
	if(error!=GL_NO_ERROR)
	{
		printf("ERROR: OpenGL couldn't get the vertex shader source code\n");
	}

	glCompileShader(vertex_shader);

	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &error);
	if(error!=GL_TRUE)
	{
		printf("ERROR: error while compiling vertex_shader\n");

			//determining error
			GLint max_length=0;
			glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &max_length);
			
			
			GLchar *error_msg=malloc(max_length);
			glGetShaderInfoLog(vertex_shader,max_length,&max_length,error_msg);
			printf("OPENGL ERROR MSG:\n %s\n",error_msg);
			free(error_msg);
	}

	free(shader_buffer);
	fclose(shader_file);

	//fragment shader
	shader_file=fopen("fragment.glsl","r");
	if(shader_file==NULL)
	{
		printf("ERROR: fragment shader couldn't be found\n");
	}

	fseek(shader_file, 0, SEEK_END);
	shader_size=ftell(shader_file);
	shader_size++;
	fseek(shader_file, 0, SEEK_SET);

	shader_buffer=malloc(shader_size);
	fread(shader_buffer, shader_size, 1, shader_file);
	shader_buffer[shader_size]='\0';

	fragment_shader=glCreateShader(GL_FRAGMENT_SHADER);
	if(fragment_shader==GL_INVALID_ENUM)
	{
		printf("ERROR: OpenGL couldn't create a fragment shader\n");
	}

	const GLchar *fragment_shader_ref_ptr=shader_buffer;
	glShaderSource(fragment_shader, 1, &fragment_shader_ref_ptr, NULL);
	error=glGetError();
	if(error!=GL_NO_ERROR)
	{
		printf("ERROR: OpenGL couldn't get the fragment shader source code\n");
	}

	glCompileShader(fragment_shader);

	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &error);
	if(error!=GL_TRUE)
	{
		printf("ERROR: error while compiling fragment shader\n");

			//determining error
			GLint max_length=0;
			glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &max_length);
			
			
			GLchar *error_msg=malloc(max_length);
			glGetShaderInfoLog(fragment_shader,max_length,&max_length,error_msg);
			printf("OPENGL ERROR MSG:\n %s\n",error_msg);
			free(error_msg);
	}

	free(shader_buffer);
	fclose(shader_file);

	//creating the whole and unified shader
	shader=glCreateProgram();
	glAttachShader(shader, vertex_shader);
		error=glGetError();
		if(error!=GL_NO_ERROR)
		{
			printf("ERROR: couldn't attach vertex_shader\n");
		}
	glAttachShader(shader, fragment_shader);
		error=glGetError();
		if(error!=GL_NO_ERROR)
		{
			printf("ERROR: couldn't attach fragment_shader\n");
		}

	glLinkProgram(shader);
	glUseProgram(shader);


}