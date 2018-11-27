#include "ImageWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
BEGIN_EVENT_TABLE(ImageWindow, wxWindow)
	EVT_PAINT(ImageWindow::OnPaint)
END_EVENT_TABLE()
ImageWindow::ImageWindow(wxFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	//load image
	this->loadBgBitmap();
	this->loadLogoBitmap();
}
ImageWindow::~ImageWindow()
{
	delete bgBitmap;
	delete logoBitmap;
}
void ImageWindow::loadBgBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug pertama
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +
		wxT("\\bg.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation,wxBITMAP_TYPE_JPEG);
	bgBitmap = new wxBitmap(image);
}
void ImageWindow::loadLogoBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug pertama
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() +
		wxT("\\logo.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	logoBitmap = new wxBitmap(image);
}
void ImageWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (bgBitmap != nullptr)
	{
		pdc.DrawBitmap(*bgBitmap, wxPoint(0, 0), true);
	}
	if (logoBitmap != nullptr)
	{
		int posX = ImageFrame::width/2 - logoBitmap->GetWidth()/2;
		int posY = ImageFrame::height/4 - logoBitmap->GetHeight()/2;
		pdc.DrawBitmap(*logoBitmap, wxPoint(posX, posY),true);
	}
}