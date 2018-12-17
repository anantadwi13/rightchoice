#include "Image.h"

Image::Image(int x, int y, wxString loc) : GameObject(x,y), ImageLoader(loc)
{
}
void Image::Draw(wxBufferedDC &dc)
{
	dc.DrawBitmap(*this->bitImage, wxPoint(this->x, this->y), true);
}
Image::~Image()
{
}
