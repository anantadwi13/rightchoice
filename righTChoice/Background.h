#pragma once
#include "GameObject.h"
#include "ImageLoader.h"

class Background : public GameObject, public ImageLoader
{
public:
	Background(int x, int y, wxString loc);
	virtual void Draw(wxBufferedDC &dc);
	~Background();
};

