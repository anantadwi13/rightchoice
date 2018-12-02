#include "SwitchFrame.h"
#include "MainPanel.h"
#include "InstructionPanel.h"
#include "GamePanel.h"

int SwitchFrame::width = 801;
int SwitchFrame::height = 480;

SwitchFrame::SwitchFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
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

	SetSizer(boxSizer);
	ShowMainPanel();
}
void SwitchFrame::ShowMainPanel()
{
	this->mainPanel->Show(true);
	this->gamePanel->Show(false);
	this->instructionPanel->Show(false);
	fitWindowSize();
}
void SwitchFrame::ShowGamePanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(true);
	this->instructionPanel->Show(false);
	fitWindowSize();
}
void SwitchFrame::ShowInstructionPanel()
{
	this->mainPanel->Show(false);
	this->gamePanel->Show(false);
	this->instructionPanel->Show(true);
	fitWindowSize();
}