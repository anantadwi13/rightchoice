#include "Card.h"

Card::Card(int x, int y, wxString loc) : GameObject(x,y), ImageLoader(loc)
{
}
void Card::Draw(wxBufferedDC &dc)
{
	dc.DrawBitmap(*this->bitImage, wxPoint(this->x, this->y), true);
}
Card::~Card()
{
}
