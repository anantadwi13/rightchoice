//tampilan muka game utama
#include "GamePanel.h"
BEGIN_EVENT_TABLE(GamePanel, wxPanel)
	EVT_BUTTON(1001, GamePanel::OnBackButtonClick)
	EVT_PAINT(GamePanel::OnPaint)
END_EVENT_TABLE()
GamePanel::GamePanel(SwitchFrame * parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	wxButton* backButton = new wxButton(this, 1001, wxT("Back"),
		wxPoint(/*SwitchFrame::width - backButton->GetMinWidth()*/ 0, 0),
		wxDefaultSize);
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->loadBgBit();
}
GamePanel::~GamePanel()
{
	delete bgBit;
}
void GamePanel::loadBgBit()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug pertama
	//wxStandardPaths &stdPaths = wxStandardPaths::Get();
	//wxString fileLocation = stdPaths.GetExecutablePath();
	/*fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\bg.jpg");*/
	wxString fileLocation = wxT("img//bg3.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	bgBit = new wxBitmap(image);
}
void GamePanel::OnBackButtonClick(wxCommandEvent & event)
{
	this->parentFrame->ShowMainPanel();
}
void GamePanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (bgBit != nullptr)
	{
		pdc.DrawBitmap(*bgBit, wxPoint(0, 0), true);
	}
}