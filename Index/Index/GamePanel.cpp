//tampilan muka game utama
#include "GamePanel.h"
BEGIN_EVENT_TABLE(GamePanel, wxPanel)
EVT_BUTTON(1001, GamePanel::OnBackButtonClick)
EVT_PAINT(GamePanel::OnPaint)
END_EVENT_TABLE()
GamePanel::GamePanel(SwitchFrame * parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxRED));
	wxButton* backButton = new wxButton(this, 1001, wxT("Back"),
		wxPoint(/*SwitchFrame::width - backButton->GetMinWidth()*/ 0, 0),
		wxDefaultSize);
}
GamePanel::~GamePanel()
{
}
void GamePanel::OnBackButtonClick(wxCommandEvent & event)
{
	this->parentFrame->ShowMainPanel();
}
void GamePanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	pdc.SetPen(*wxBLACK_PEN);
	pdc.SetBrush(*wxBLUE_BRUSH);
	pdc.DrawCircle(wxPoint(100, 100), 50);
}