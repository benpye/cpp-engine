#ifndef GL_GRAPHICS_DEVICE_H
#define GL_GRAPHICS_DEVICE_H

#include <igraphics_device.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class GraphicsDevice : public IGraphicsDevice
{
public:
	GraphicsDevice(SDL_Window *window);
	~GraphicsDevice();
	
	IShader *CreateShader();
	
private:
	SDL_GLContext context;
};

#endif