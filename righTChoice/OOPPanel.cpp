//tampilan muka oop explanation
#include "OOPPanel.h"

BEGIN_EVENT_TABLE(OOPPanel, wxPanel)
	EVT_BUTTON(1001, OOPPanel::OnBackButtonClick)
	EVT_PAINT(OOPPanel::OnPaint)
END_EVENT_TABLE()

OOPPanel::OOPPanel(SwitchFrame* parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);

	//load PNGHandler untuk membaca file PNG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);

	//instansiasi obj list img dan button img
	this->img = new ImageLoaderList();
	this->btn = new ImageLoaderList();

	//load image dan button image
	this->renderBitmap();
}
OOPPanel::~OOPPanel()
{
	this->btn->Clear();
	this->img->Clear();
	delete this->btn;
	delete this->img;
}
void OOPPanel::renderBitmap()
{
	//img oop explanation
	ImageLoader *img1 = new ImageLoader(wxT("img//oop.jpg"));
	this->img->Append(img1);

	//button img back
	ButtonImageLoader *btn1 = new ButtonImageLoader(
		wxT("img//btn_kembali.png"), this, 1001, 0, 0, 0);
	this->btn->Append(btn1);
}
void OOPPanel::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this);
	ImageLoaderList::Node* tmp = this->img->GetFirst();

	while (tmp)
	{
		wxMessageOutputDebug().Printf("oop");
		ImageLoader *iml = tmp->GetData();
		if (iml->loc == wxT("img//oop.jpg"))
		{
			pdc.DrawBitmap(*iml->bitImage, wxPoint(0, 0), true);
		}
		tmp = tmp->GetNext();
	}
}
void OOPPanel::OnBackButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMainPanel();
}