#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
class GamePanel : public wxPanel
{
public:
	GamePanel(SwitchFrame* parent);
	~GamePanel();
	void OnPaint(wxPaintEvent &event);
	void OnBackButtonClick(wxCommandEvent& event);
private:
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
};