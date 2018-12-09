#pragma once
#include "wx/dcbuffer.h"

class GaugeBar
{
private:
	int x;
	int y;
	int width;
	int maxWidth;
public:
	GaugeBar(int x, int y, int width, int maxWidth);
	void setWidth(int width);
	int getWidth();
	int getMaxWidth();
	void Draw(wxBufferedDC &dc);
	~GaugeBar();
};

