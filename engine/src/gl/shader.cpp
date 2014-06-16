#include "opengl.h"

#include "shader.h"

#include <cstring>
#include <string>
#include <iostream>

void Shader::Load(std::string source, ShaderType type)
{
	switch(type)
	{
		case SHADER_VERTEX:
			shader = glCreateShader(GL_VERTEX_SHADER);
			break;
		case SHADER_FRAGMENT:
			shader = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		case SHADER_GEOMETRY:
			shader = glCreateShader(GL_GEOMETRY_SHADER);
			break;
		default:
			std::cout << "Unknown shader type " << type << std::endl;
			return;
	}
	
	const char *tempstr = source.c_str();
		
	glShaderSource(shader, 1, &tempstr, nullptr);
	glCompileShader(shader);
	
	#if DEBUG
	CheckCompiled();
	#endif
}

bool Shader::CheckCompiled()
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	
	std::cout << "Shader compiled, status: "
	          << (status == GL_TRUE ? "successful" : "failed") << std::endl;
	char buffer[512];
	glGetShaderInfoLog(shader, 512, NULL, buffer);
	
	if(strlen(buffer) > 0)
		std::cout << "Shader compilation log: " << buffer << std::endl;
	
	if(status == GL_TRUE)
		return true;
	else
	{
		std::cout << "Shader compilation failed!" << std::endl;
		return false;
	}
}

GLuint Shader::GetGLShader()
{
	return shader;
}