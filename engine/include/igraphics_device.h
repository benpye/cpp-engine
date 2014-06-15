#ifndef I_GRAPHICS_DEVICE_H
#define I_GRAPHICS_DEVICE_H

class IShader;

class IGraphicsDevice
{
public:
	virtual ~IGraphicsDevice() {}
	virtual IShader *CreateShader() = 0;
};

#endif