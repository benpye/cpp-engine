#ifndef I_SHADER_H
#define I_SHADER_H

#include <string>

enum ShaderType
{
	SHADER_VERTEX,
	SHADER_FRAGMENT,
	SHADER_GEOMETRY,
};

class IShader
{
public:
	virtual ~IShader() {}
	// ID passed is going to be filename  of source code
	// in GL backend this is used to cache shaders, but it can safely be ignored
	// 0 length id should also be ignored
	virtual void AddShader(std::string source, ShaderType type, std::string id = "") = 0;
};

#endif