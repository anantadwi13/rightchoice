#pragma once
#include "GameObject.h"
#include "ImageLoader.h"

class Image : public GameObject, public ImageLoader
{
public:
	Image(int x, int y, wxString loc);
	virtual void Draw(wxBufferedDC &dc);
	~Image();
};

