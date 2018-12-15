#include "Background.h"



Background::Background(int x, int y, wxString loc) : GameObject(x, y), ImageLoader(loc)
{
}

void Background::Draw(wxBufferedDC &dc)
{
	dc.DrawBitmap(*this->bitImage, wxPoint(this->x, this->y), true);
}

Background::~Background()
{
}
