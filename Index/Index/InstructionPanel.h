#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include "MainPanel.h"

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
	ImageLoaderList *img = nullptr, *btn = nullptr;
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};