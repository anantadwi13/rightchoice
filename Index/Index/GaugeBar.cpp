#include "GaugeBar.h"

GaugeBar::GaugeBar(int x, int y, int width, int maxWidth)
	: x(x), y(y), width(width), maxWidth(maxWidth)
{
}

void GaugeBar::Draw(wxBufferedDC &dc) 
{
	dc.SetPen(*wxGREY_PEN);
	dc.SetBrush(*wxGREY_BRUSH);
	dc.DrawRectangle(wxPoint(x, y), wxSize(maxWidth, 40));
	
	dc.SetPen(*wxGREEN_PEN);
	dc.SetBrush(*wxGREEN_BRUSH);
	dc.DrawRectangle(wxPoint(x, y), wxSize(width, 40));
}

void GaugeBar::setWidth(int width) {
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
