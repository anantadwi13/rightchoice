#pragma once
#include "wx/wx.h"
//#include <wx/mediactrl.h>
class MainPanel;
class GamePanel;
class InstructionPanel;
class SwitchFrame : public wxFrame {
private:
	wxBoxSizer* boxSizer;
	MainPanel* mainPanel;
	GamePanel* gamePanel;
	InstructionPanel* instructionPanel;
	void fitWindowSize();
	//wxMediaCtrl *music = nullptr;
	//DECLARE_EVENT_TABLE()
public:
	//void BacksoundPlay(wxMediaEvent& event);
	//mirip imageframe
	static int width;
	static int height;
	SwitchFrame(const wxString &title);
	void InitComponents();
	void ShowMainPanel();
	void ShowGamePanel();
	void ShowInstructionPanel();
};