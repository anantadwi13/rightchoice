//tampilan muka menu utama
#include "MainPanel.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
BEGIN_EVENT_TABLE(MainPanel, wxPanel)
	EVT_BUTTON(1001, MainPanel::OnGameClick)
	EVT_BUTTON(1002, MainPanel::OnInstructionClick)
	EVT_PAINT(MainPanel::OnPaint)
END_EVENT_TABLE()
MainPanel::MainPanel(SwitchFrame * parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load JPEGHandler untuk membaca file PNG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	/*wxBitmap* tes = new wxBitmap(150, 60, -1);
	wxBitmapButton* gamebtn = new wxBitmapButton(this, 1001,tes,
		wxPoint(SwitchFrame::width / 2 - tes->GetWidth() / 2, SwitchFrame::height / 2 - tes->GetHeight() / 2),
		wxSize(150,60),wxBU_AUTODRAW,wxDefaultValidator,wxT("Mulai"));*/
	wxButton* gameButton = new wxButton(this, 1001, wxT("Mulai"),
		wxPoint(SwitchFrame::width / 2 /*- gameButton->GetMinWidth() / 2*/, SwitchFrame::height / 2 /*- gameButton->GetMinHeight() / 2*/),
		wxDefaultSize);
	wxButton* instructionButton = new wxButton(this, 1002, wxT("Instruksi"),
		wxPoint(SwitchFrame::width / 2 /*- gameButton->GetMinWidth() / 2*/, SwitchFrame::height / 2 + 50 /*- gameButton->GetMinHeight() / 2*/),
		wxDefaultSize);
	//load image
	this->loadBgBitmap();
	this->loadLogoBitmap();
}
MainPanel::~MainPanel()
{
	delete bgBitmap;
	delete logoBitmap;
}
void MainPanel::loadBgBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug pertama
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\bg.jpg");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);
	bgBitmap = new wxBitmap(image);
}
void MainPanel::loadLogoBitmap()
{
	//jika menggunakan relative path
	//letakkan file potato.jpg pada folder Debug pertama
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\logo.png");
	wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	logoBitmap = new wxBitmap(image);
}
void MainPanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (bgBitmap != nullptr)
	{
		pdc.DrawBitmap(*bgBitmap, wxPoint(0, 0), true);
	}
	if (logoBitmap != nullptr)
	{
		int posX = SwitchFrame::width / 2 - logoBitmap->GetWidth() / 2;
		int posY = SwitchFrame::height / 4 - logoBitmap->GetHeight() / 2;
		pdc.DrawBitmap(*logoBitmap, wxPoint(posX, posY), true);
	}
}
void MainPanel::OnGameClick(wxCommandEvent & event)
{
	parentFrame->ShowGamePanel();
}
void MainPanel::OnInstructionClick(wxCommandEvent & event)
{
	parentFrame->ShowInstructionPanel();
}