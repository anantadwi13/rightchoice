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
	wxButton* backButton = new wxButton(this, 1001, wxT("Back"),
		wxPoint(0,0),wxDefaultSize);
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->loadBgBitm();
}
InstructionPanel::~InstructionPanel()
{
	delete bgBitm;
}
void InstructionPanel::loadBgBitm()
{
	wxString fileLocation = wxT("img//bg.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	bgBitm = new wxBitmap(image);
}
void InstructionPanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (bgBitm != nullptr)
	{
		pdc.DrawBitmap(*bgBitm, wxPoint(0, 0), true);
	}
}
void InstructionPanel::OnBackButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMainPanel();
}