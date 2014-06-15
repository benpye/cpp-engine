#ifndef I_WINDOW_H
#define I_WINDOW_H

#include <string>

class IGraphicsDevice;

class IWindow
{
public:
	virtual ~IWindow() {}
	
	virtual void Update() = 0;
	virtual void SwapBuffers() = 0;
	
	virtual void SetTitle(std::string title) = 0;
	virtual std::string GetTitle() = 0;
	
	virtual void SetSize(int width, int height) = 0;
	virtual void GetSize(int *width, int *height) = 0;
	
	virtual void SetVSync(bool enabled) = 0;
	virtual bool GetVSync() = 0;
	
	virtual void SetFullscreen(bool fullscreen) = 0;
	virtual bool GetFullscreen() = 0;
	
	virtual void SetBorder(bool border) = 0;
	virtual bool GetBorder() = 0;
	
	virtual IGraphicsDevice *GetGraphicsDevice() = 0;
};

#endif