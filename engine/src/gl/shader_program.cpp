#include "opengl.h"

#include "shader_program.h"
#include "shader.h"

#include <cstring>
#include <string>
#include <iostream>

ShaderProgram::ShaderProgram()
{
	program = glCreateProgram();
}

void ShaderProgram::AttachShader(IShader* shader)
{
	Shader *glshader = static_cast<Shader *>(shader);
	glAttachShader(program, glshader->GetGLShader());
}

void ShaderProgram::Link()
{
	glLinkProgram(program);
	
	#ifdef DEBUG
	CheckLinked();
	#endif
}

bool ShaderProgram::CheckLinked()
{
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	
	std::cout << "Shader program linked, status: "
	          << (status == GL_TRUE ? "successful" : "failed") << std::endl;
	char buffer[512];
	glGetProgramInfoLog(program, 512, NULL, buffer);
	
	if(strlen(buffer) > 0)
		std::cout << "Shader program link log: " << buffer << std::endl;
	
	if(status == GL_TRUE)
		return true;
	else
	{
		std::cout << "Shader program link failed!" << std::endl;
		return false;
	}
}
