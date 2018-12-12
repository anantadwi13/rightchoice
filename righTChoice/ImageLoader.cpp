#include "ImageLoader.h"

ImageLoader::ImageLoader(wxString loc)
{
	this->loc = loc;
	this->image = new wxImage(this->loc, wxBITMAP_TYPE_ANY);
	this->bitImage = new wxBitmap(*this->image);
}
ImageLoader::~ImageLoader()
{
	delete this->image;
	delete this->bitImage;
}
void ImageLoader::setLoc(wxString loc) {
	this->loc = loc;
	this->image = new wxImage(this->loc, wxBITMAP_TYPE_ANY);
	this->bitImage = new wxBitmap(*this->image);
}