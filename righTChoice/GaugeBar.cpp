#include "GaugeBar.h"

GaugeBar::GaugeBar(int x, int y, int width, int maxWidth)
	: GameObject(x,y), width(width), maxWidth(maxWidth)
{
}

void GaugeBar::Draw(wxBufferedDC &dc) 
{
	dc.SetPen(*wxGREY_PEN);
	dc.SetBrush(*wxGREY_BRUSH);
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(maxWidth, 40));
	
	dc.SetPen(*wxGREEN_PEN);
	dc.SetBrush(*wxGREEN_BRUSH);
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(width, 40));
}

void GaugeBar::setWidth(int width) {
	if (width < 0)
		width = 0;
	else if (width > this->maxWidth)
		width = maxWidth;
	this->width = width;
}
int GaugeBar::getWidth() {
	return this->width;
}

int GaugeBar::getMaxWidth() {
	return this->maxWidth;
}

GaugeBar::~GaugeBar()
{
}
