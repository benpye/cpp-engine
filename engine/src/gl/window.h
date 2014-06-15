#ifndef GL_WINDOW_H
#define GL_WINDOW_H

#include <iwindow.h>

#include <SDL2/SDL.h>

#include <string>

class IGraphicsDevice;
class GraphicsDevice;

class Window : public IWindow
{
public:
	Window(int width, int height, bool fullscreen, bool noborder);
	~Window();
	
	void Update();
	void SwapBuffers();
	
	void SetTitle(std::string title);
	std::string GetTitle();
	
	void SetSize(int width, int height);
	void GetSize(int *width, int *height);
	
	void SetVSync(bool enabled);
	bool GetVSync();
	
	void SetFullscreen(bool fullscreen);
	bool GetFullscreen();
	
	void SetBorder(bool border);
	bool GetBorder();
	
	IGraphicsDevice *GetGraphicsDevice();
	
private:
	SDL_Window *window;
	GraphicsDevice *graphicsDevice;
};

#endif