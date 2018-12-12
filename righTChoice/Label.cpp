#include "Label.h"

Label::Label(int x, int y, int width) : GameObject(x,y), width(width)
{
}
void Label::Draw(wxBufferedDC &dc)
{
	dc.SetPen(this->pen);
	dc.SetBrush(this->brush);
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(width, 80));

	dc.SetFont(this->font);
	dc.SetTextForeground(this->color);
	dc.DrawLabel(this->string, wxRect(wxPoint(this->x, this->y),
		wxSize(this->width, 80)), wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
}
void Label::setFont(wxFont font)
{
	this->font = font;
}
void Label::setFill(wxColour color)
{
	this->color = color;
}
void Label::setBrush(wxBrush brush)
{
	this->brush = brush;
}
void Label::setPen(wxPen pen)
{
	this->pen = pen;
}
void Label::setString(wxString string)
{
	this->string = string;
}
Label::~Label()
{
}