//tampilan muka instruksi
#include "InstructionPanel.h"
BEGIN_EVENT_TABLE(InstructionPanel, wxPanel)
EVT_BUTTON(1001, InstructionPanel::OnBackButtonClick)
END_EVENT_TABLE()
InstructionPanel::InstructionPanel(SwitchFrame * parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxBLUE));
	wxButton* backButton = new wxButton(this, 1001, wxT("Back"),
		wxPoint(0,0),wxDefaultSize);
}
InstructionPanel::~InstructionPanel()
{
}
void InstructionPanel::OnBackButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMainPanel();
}