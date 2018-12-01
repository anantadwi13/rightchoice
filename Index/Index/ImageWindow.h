#pragma once
#include "wx\wx.h"
#include "ImageFrame.h"
class ImageWindow : public wxWindow
{
public:
	ImageWindow(wxFrame *parent);
	~ImageWindow();
	void OnPaint(wxPaintEvent &event);
private:
	wxBitmap *bgBitmap = nullptr, *logoBitmap = nullptr;
	DECLARE_EVENT_TABLE()
	void loadLogoBitmap();
	void loadBgBitmap();
};