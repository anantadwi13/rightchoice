#include "ImageFrame.h"
#include "ImageWindow.h"

int ImageFrame::width = 810;
int ImageFrame::height = 480;

ImageFrame::ImageFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->window = new ImageWindow(this);
	this->SetInitialSize(wxSize(this->width, this->height));
}