#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
class InstructionPanel : public wxPanel
{
public:
	InstructionPanel(SwitchFrame* parent);
	~InstructionPanel();
	void OnBackButtonClick(wxCommandEvent& event);
private:
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
};