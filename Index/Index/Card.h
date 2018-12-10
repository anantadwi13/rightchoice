#pragma once
#include "GameObject.h"
#include "ImageLoader.h"

class Card : public GameObject, public ImageLoader
{
public:
	Card(int x, int y, wxString loc);
	virtual void Draw(wxBufferedDC &dc);
	~Card();
};

