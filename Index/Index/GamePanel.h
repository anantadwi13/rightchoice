#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include "MainPanel.h"

class GamePanel : public wxPanel
{
public:
	GamePanel(SwitchFrame* parent);
	~GamePanel();
	void OnPaint(wxPaintEvent &event);
	void OnBackButtonClick(wxCommandEvent& event);
private:
	//mirip imagewindow
	ImageLoaderList *img = nullptr, *btn = nullptr;
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};