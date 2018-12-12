#pragma once
#include "wx/wx.h"

class MainPanel;
class GamePanel;
class InstructionPanel;
class OOPPanel;
class SwitchFrame : public wxFrame {
private:
	wxBoxSizer* boxSizer;
	MainPanel* mainPanel;
	GamePanel* gamePanel;
	InstructionPanel* instructionPanel;
	OOPPanel* oopPanel;
	void fitWindowSize();
public:
	//mirip imageframe
	static int width;
	static int height;
	SwitchFrame(const wxString &title);
	void InitComponents();
	void ShowMainPanel();
	void ShowGamePanel();
	void ShowInstructionPanel();
	void ShowOOPPanel();
};