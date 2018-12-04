//tampilan muka instruksi
#include "InstructionPanel.h"

BEGIN_EVENT_TABLE(InstructionPanel, wxPanel)
	EVT_BUTTON(1001, InstructionPanel::OnBackButtonClick)
	EVT_PAINT(InstructionPanel::OnPaint)
END_EVENT_TABLE()
InstructionPanel::InstructionPanel(SwitchFrame * parent) :
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
InstructionPanel::~InstructionPanel()
{
	this->btn->Clear();
	this->img->Clear();
	delete this->btn;
	delete this->img;
}
void InstructionPanel::renderBitmap()
{
	//img background
	ImageLoader *img1 = new ImageLoader(wxT("img//bg.jpg"));
	this->img->Append(img1);

	//button img back
	ButtonImageLoader *btn1 = new ButtonImageLoader(
		wxT("img//btn_kembali.png"), this, 1001, 0, 0, 0);
	this->btn->Append(btn1);
}
void InstructionPanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	ImageLoaderList::Node* tmp = this->img->GetFirst();

	while (tmp)
	{
		ImageLoader *iml = tmp->GetData();
		if (iml->loc == wxT("img//bg.jpg"))
		{
			pdc.DrawBitmap(*iml->bitImage, wxPoint(0, 0), true);
		}
		tmp = tmp->GetNext();
	}
}
void InstructionPanel::OnBackButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMainPanel();
}