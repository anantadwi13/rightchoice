#include "ButtonImageLoader.h"

ButtonImageLoader::ButtonImageLoader
(wxString loc, wxWindow *w, wxWindowID wid, int d) :
	ImageLoader(loc)
{	//membuat bitmap button
	this->bitBtn = new wxBitmapButton(w, wid, *this->bitImage,
		wxPoint(SwitchFrame::width / 2 - this->bitImage->GetWidth() / 2,
			SwitchFrame::height / 2 + d - this->bitImage->GetHeight() / 2),
		wxDefaultSize, wxBORDER_NONE);
}
ButtonImageLoader::ButtonImageLoader
(wxString loc, wxWindow *w, wxWindowID wid,
	int d, int x, int y) :
	ImageLoader(loc)
{	//membuat bitmap button
	this->bitBtn = new wxBitmapButton(w, wid, *this->bitImage,
		wxPoint(x, y + d), wxDefaultSize, wxBORDER_NONE);
}
ButtonImageLoader::~ButtonImageLoader()
{
	ImageLoader::~ImageLoader();
	delete this->bitBtn;
}
