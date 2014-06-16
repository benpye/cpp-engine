#ifndef I_SHADER_PROGRAM_H
#define I_SHADER_PROGRAM_H

class IShader;

class IShaderProgram
{
public:
	virtual ~IShaderProgram() {}
	virtual void AttachShader(IShader *shader) = 0;
	virtual void Link() = 0;
};

#endif