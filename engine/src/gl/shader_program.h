#ifndef GL_SHADER_PROGRAM_H
#define GL_SHADER_PROGRAM_H

#include <ishader_program.h>

class ShaderProgram : public IShaderProgram
{
public:
	ShaderProgram();

	void AttachShader(IShader* shader);
	void Link();
	
private:
	bool CheckLinked();
	GLuint program;
};

#endif
