#include <iostream>

#include "gl/window.h"

#include <ishader.h>
#include <ishader_program.h>
#include <igraphics_device.h>

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
	
	IShader *vShader = device->CreateShader();
	
	vShader->Load(
	R"(#version 150

in vec2 position;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
})", SHADER_VERTEX);
	
	IShader *pShader = device->CreateShader();

	pShader->Load(R"(#version 150

out vec4 outColor;

void notmain()
{
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
})", SHADER_FRAGMENT);
	
	IShaderProgram *shaderProgram = device->CreateShaderProgram();
	shaderProgram->AttachShader(vShader);
	shaderProgram->AttachShader(pShader);
	shaderProgram->Link();
	
	
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