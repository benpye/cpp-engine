#include "window.h"
#include "graphics_device.h"
#include <igraphics_device.h>

#include <SDL2/SDL.h>

#include <string>

Window::Window(int width, int height, bool fullscreen, bool noborder)
{
	Uint32 flags = SDL_WINDOW_OPENGL;
	
	if(fullscreen)
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		
	if(noborder)
		flags |= SDL_WINDOW_BORDERLESS;
	
	window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED, width, height,
							  flags);
							  
	graphicsDevice = new GraphicsDevice(window);
}

Window::~Window()
{
	delete graphicsDevice;
	SDL_DestroyWindow(window);
}

void Window::Update()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		// TODO: Pass events to internal systems
	}
}

void Window::SwapBuffers()
{
	SDL_GL_SwapWindow(window);
}

void Window::SetTitle(std::string title)
{
	SDL_SetWindowTitle(window, title.c_str());
}

std::string Window::GetTitle()
{
	return std::string(SDL_GetWindowTitle(window));
}

void Window::SetSize(int width, int height)
{
	SDL_SetWindowSize(window, width, height);
}

void Window::GetSize(int *width, int *height)
{
	SDL_GetWindowSize(window, width, height);
}

IGraphicsDevice *Window::GetGraphicsDevice()
{
	return graphicsDevice;
}

void Window::SetVSync(bool enabled)
{
	if(enabled)
	{
		// Try late swap tearing first
		if(SDL_GL_SetSwapInterval(-1) == -1)
			SDL_GL_SetSwapInterval(1);
	}
	else
		SDL_GL_SetSwapInterval(0);
}

bool Window::GetVSync()
{
	return (SDL_GL_GetSwapInterval() == 1);
}

void Window::SetFullscreen(bool fullscreen)
{
	SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

bool Window::GetFullscreen()
{
	return (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP) == SDL_WINDOW_FULLSCREEN_DESKTOP;
}

void Window::SetBorder(bool border)
{
	if(GetFullscreen())
		return;
		
	SDL_SetWindowBordered(window, border ? SDL_TRUE : SDL_FALSE);
}

bool Window::GetBorder()
{
	if(GetFullscreen())
		return false;
		
	return (SDL_GetWindowFlags(window) & SDL_WINDOW_BORDERLESS) == SDL_WINDOW_BORDERLESS;
}