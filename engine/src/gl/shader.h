#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <ishader.h>

#include <string>

class Shader : public IShader
{
public:
	void Load(std::string source, ShaderType type);
	GLuint GetGLShader();
	
private:
	bool CheckCompiled();
	GLuint shader;
};

#endif