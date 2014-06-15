// OpenGL include needs to be before everything
#include "opengl.h"

#include "graphics_device.h"
#include "shader.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <iostream>

void APIENTRY oglDebugCallback(GLenum source, GLenum type, GLuint id,
GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
	std::cout << "OpenGL debug message" << std::endl;
	std::cout << "    Source: ";
	
	switch(source)
	{
		case GL_DEBUG_SOURCE_API:
			std::cout << "API";
			break;
		case GL_DEBUG_SOURCE_APPLICATION:
			std::cout << "APPLICATION";
			break;
		case GL_DEBUG_SOURCE_OTHER:
			std::cout << "OTHER";
			break;
		case GL_DEBUG_SOURCE_SHADER_COMPILER:
			std::cout << "SHADER COMPILER";
			break;
		case GL_DEBUG_SOURCE_THIRD_PARTY:
			std::cout << "THIRD PARTY";
			break;
		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
			std::cout << "WINDOW SYSTEM";
			break;
	}
	
	std::cout << std::endl;
	std::cout << "    Type: ";
	
	switch(type)
	{
		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
			std::cout << "DEPRECATED BEHAVIOR";
			break;
		case GL_DEBUG_TYPE_ERROR:
			std::cout << "ERROR";
			break;
		case GL_DEBUG_TYPE_MARKER:
			std::cout << "MARKER";
			break;
		case GL_DEBUG_TYPE_OTHER:
			std::cout << "OTHER";
			break;
		case GL_DEBUG_TYPE_PERFORMANCE:
			std::cout << "PERFORMANCE";
			break;
		case GL_DEBUG_TYPE_POP_GROUP:
			std::cout << "POP GROUP";
			break;
		case GL_DEBUG_TYPE_PORTABILITY:
			std::cout << "PORTABILITY";
			break;
		case GL_DEBUG_TYPE_PUSH_GROUP:
			std::cout << "PUSH GROUP";
			break;
		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
			std::cout << "UNDEFINED BEHAVIOR";
			break;
	}
	
	std::cout << std::endl;
	std::cout << "    ID: " << id << std::endl;
	std::cout << "    Severity: ";
	
	switch(severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
			std::cout << "HIGH";
			break;
		case GL_DEBUG_SEVERITY_LOW:
			std::cout << "LOW";
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			std::cout << "MEDIUM";
			break;
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			std::cout << "NOTIFICATION";
			break;
	}
	
	std::cout << std::endl;
	std::cout << "    Message: " << message << std::endl;
}

GraphicsDevice::GraphicsDevice(SDL_Window *window)
{
	// Enable double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	#ifdef DEBUG
	// In debug builds enable debug context giving us logging
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	#endif
	
	context = SDL_GL_CreateContext(window);
	
	glWranglerInit();
	
	std::cout << "OpenGL: " << glGetString(GL_VERSION) << ", GLSL: "
	          << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	
	#if DEBUG
	if(glVersionGEQ(4, 3))
	{
		std::cout << "Enabling OpenGL debug logging" << std::endl;
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		// Enable all messages
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, 0, GL_TRUE);
		glDebugMessageCallback(oglDebugCallback, nullptr);
	}
	#endif
}

GraphicsDevice::~GraphicsDevice()
{
	SDL_GL_DeleteContext(context);
}

IShader *GraphicsDevice::CreateShader()
{
	return new Shader();
}