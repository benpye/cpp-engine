// Used to abstract the OpenGL wrangler used. In the future may have a Regal
// option for debugging.

// Also contains some misc functions

#ifndef GL_OPENGL_H
#define GL_OPENGL_H

#include "gl_core_4_4.hpp"

void glWranglerInit();
bool glVersionGEQ(int major, int minor);

#endif