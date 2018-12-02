#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
class InstructionPanel : public wxPanel
{
public:
	InstructionPanel(SwitchFrame* parent);
	~InstructionPanel();
	void OnBackButtonClick(wxCommandEvent& event);
	//mirip imagewindow
	void OnPaint(wxPaintEvent &event);
private:
	//mirip imagewindow
	wxBitmap *bgBitm = nullptr;
	void loadBgBitm();
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
};