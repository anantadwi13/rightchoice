#include "SwitchFrame.h"
#include "MainPanel.h"
#include "InstructionPanel.h"
#include "GamePanel.h"
#include "OOPPanel.h"

int SwitchFrame::width = 1280;
int SwitchFrame::height = 720;

SwitchFrame::SwitchFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize,
		wxDEFAULT_FRAME_STYLE ^ wxMAXIMIZE_BOX ^ wxRESIZE_BORDER)
{
	this->InitComponents();
	this->SetDoubleBuffered(true);
}
void SwitchFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(this->width, this->height));
	this->Layout();
}
void SwitchFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);
	this->mainPanel = new MainPanel(this);
	this->mainPanel->Show(false);
	this->boxSizer->Add(mainPanel, 1, wxEXPAND, 0);

	this->gamePanel = new GamePanel(this);
	this->gamePanel->Show(false);
	this->boxSizer->Add(gamePanel, 1, wxEXPAND, 0);

	this->instructionPanel = new InstructionPanel(this);
	this->instructionPanel->Show(false);
	this->boxSizer->Add(instructionPanel, 1, wxEXPAND, 0);

	this->oopPanel = new OOPPanel(this);
	this->oopPanel->Show(false);
	this->boxSizer->Add(oopPanel, 1, wxEXPAND, 0);

	SetSizer(boxSizer);
	ShowMainPanel();
}
void SwitchFrame::ShowMainPanel()
{
	this->mainPanel->Show(true);
	this->gamePanel->Show(false);
	this->instructionPanel->Show(false);
	this->oopPanel->Show(false);
	fitWindowSize();
}
void SwitchFrame::ShowGamePanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(true);
	this->instructionPanel->Show(false);
	this->oopPanel->Show(false);
	fitWindowSize();
}
void SwitchFrame::ShowInstructionPanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->instructionPanel->Show(true);
	this->oopPanel->Show(false);
	fitWindowSize();
}
void SwitchFrame::ShowOOPPanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->instructionPanel->Show(false);
	this->oopPanel->Show(true);
	fitWindowSize();
}