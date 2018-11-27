#pragma once
#include "wx\wx.h"
class ImageWindow;
class ImageFrame : public wxFrame
{
private:
	ImageWindow *window;
public:
	ImageFrame(const wxString &title);
	static int width;
	static int height;
};