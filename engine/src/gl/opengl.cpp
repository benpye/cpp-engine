#include "opengl.h"

#include <iostream>

static int g_glVersionMinor = 0;
static int g_glVersionMajor = 0;

// glloadgen c style init
void glWranglerInit()
{
	int loaded = ogl_LoadFunctions();
	
	if(loaded == ogl_LOAD_FAILED)
	{
		// We failed - bail
		std::cout << "Failed to load OpenGL functions" << std::endl;
		exit(1);
	}
	
	std::cout << "OpenGL functions missing: " << loaded - ogl_LOAD_SUCCEEDED
	          << std::endl;
	
	// Cache the version to reduce glGet
	glGetIntegerv(GL_MAJOR_VERSION, &g_glVersionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &g_glVersionMinor);
}

bool glVersionGEQ(int major, int minor)
{
	if(g_glVersionMajor > major)
		return true;
		
	if(g_glVersionMajor < major)
		return false;
		
	if(g_glVersionMinor >= minor)
		return true;
		
	return false;
}