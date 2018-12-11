#pragma once
#include "GameObject.h"

class GaugeBar : public GameObject
{
private:
	int width;
	int maxWidth;
public:
	GaugeBar(int x, int y, int width, int maxWidth);
	void setWidth(int width);
	int getWidth();
	int getMaxWidth();
	virtual void Draw(wxBufferedDC &dc);
	~GaugeBar();
};

