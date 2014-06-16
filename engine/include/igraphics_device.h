#ifndef I_GRAPHICS_DEVICE_H
#define I_GRAPHICS_DEVICE_H

class IShader;
class IShaderProgram;

class IGraphicsDevice
{
public:
	virtual ~IGraphicsDevice() {}
	virtual IShader *CreateShader() = 0;
	virtual IShaderProgram *CreateShaderProgram() = 0;
};

#endif