#include <iostream>

#include "gl/window.h"
#include "gl/graphics_device.h"
#include "gl/shader.h"

#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL failed to initialize: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	IWindow *window = new Window(640, 480, false, true);
	window->SetVSync(true);
	
	IGraphicsDevice *device = window->GetGraphicsDevice();
	
	IShader *shader = device->CreateShader();
	
	shader->AddShader(
	R"(#version 150

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
})", SHADER_VERTEX, "testvs.glsl");

	shader->AddShader(R"(#version 150

out vec4 outColor;

void main()
{
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
})", SHADER_FRAGMENT, "testps.glsl");
	
	IShader *shader2 = device->CreateShader();
	
	shader2->AddShader(
	R"(#version 150

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
})", SHADER_VERTEX, "testvs.glsl");

	shader2->AddShader(R"(#version 150

out vec4 outColor;

void main()
{
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
})", SHADER_FRAGMENT, "testps.glsl");
	
	while(true)
	{
		window->Update();
		//glClearColor(1, 1, 0, 1);
		//glClear(GL_COLOR_BUFFER_BIT);
		window->SwapBuffers();
	}
	
	std::cout << "Hello World!" << std::endl;
	return 0;
}