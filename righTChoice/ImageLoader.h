#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"

class ImageLoader
{
public:
	wxString loc;
	wxImage *image = nullptr;
	wxBitmap *bitImage = nullptr;
	ImageLoader(wxString loc);
	~ImageLoader();
	void setLoc(wxString loc);
};