#pragma once
#include "wx\wx.h"
#include "ImageLoader.h"

class ButtonImageLoader : public ImageLoader
{
public:
	wxBitmapButton *bitBtn = nullptr;
	ButtonImageLoader(wxString, wxWindow*, wxWindowID, int);
	ButtonImageLoader(wxString, wxWindow*, wxWindowID, int, int, int);
	~ButtonImageLoader();
};
