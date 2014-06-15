#include "opengl.h"

#include "shader.h"

#include <cstring>
#include <string>
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, GLuint> Shader::shaderCache;

Shader::Shader()
{
	program = glCreateProgram();
}

void Shader::AddShader(std::string source, ShaderType type, std::string id)
{
	GLuint shader = 0;

	if(id.length() > 0)
		shader = GetShaderFromCache(id);
	
	// Not in cache or no id, attempt compile
	if(shader == 0)
	{
		const char *tempstr = source.c_str();
		
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
		
		glShaderSource(shader, 1, &tempstr, nullptr);
		glCompileShader(shader);
		
		if(!ShaderCheckCompiled(shader, id))
			return;
			
		if(id.length() > 0)
			AddShaderToCache(shader, id);
	}
	
	glAttachShader(program, shader);
}

GLuint Shader::GetShaderFromCache(std::string id)
{
	auto cacheIterator = shaderCache.find(id);
	if(cacheIterator != shaderCache.end())
	{
		std::cout << "Using shader from cache" << std::endl;
		return cacheIterator->second;
	}
	
	return 0;
}

void Shader::AddShaderToCache(GLuint shader, std::string id)
{
	shaderCache[id] = shader;
}

bool Shader::ShaderCheckCompiled(GLuint shader, std::string id)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	
	std::cout << "Shader ID: " << id << " compiled, status: "
	          << (status == GL_TRUE ? "successful" : "failed") << std::endl;
	
	#if DEBUG
	char buffer[512];
	glGetShaderInfoLog(shader, 512, NULL, buffer);
	
	if(strlen(buffer) > 0)
		std::cout << "Shader compilation log: " << buffer << std::endl;
	#endif
	
	if(status == GL_TRUE)
		return true;
	else
	{
		std::cout << "Shader compilation failed!" << std::endl;
		return false;
	}
}