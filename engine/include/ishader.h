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
	virtual void Load(std::string source, ShaderType type) = 0;
};

#endif