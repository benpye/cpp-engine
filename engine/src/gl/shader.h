#ifndef GL_SHADER_H
#define GL_SHADER_H

#include <ishader.h>

#include <string>
#include <vector>
#include <unordered_map>

class Shader : public IShader
{
public:
	Shader();
	void AddShader(std::string source, ShaderType type, std::string id);
	//~Shader();
	//static void FromFile(std::string vsname, std::string psname);
	
private:
	static GLuint GetShaderFromCache(std::string id);
	static void AddShaderToCache(GLuint shader, std::string id);
	static bool ShaderCheckCompiled(GLuint shader, std::string id);
	static std::unordered_map<std::string, GLuint> shaderCache;

	GLuint program;
};

#endif