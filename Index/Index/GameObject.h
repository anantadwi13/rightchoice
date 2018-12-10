#pragma once
#include "wx/dcbuffer.h"

class GameObject
{
protected:
	int x;
	int y;
public:
	virtual void Draw(wxBufferedDC &dc) = 0;
	GameObject(int x, int y);
	~GameObject();
};
