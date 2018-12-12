#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include "MainPanel.h"
#include "wx/dcbuffer.h"

class OOPPanel : public wxPanel
{
public:
	OOPPanel(SwitchFrame* parent);
	~OOPPanel();
	void OnBackButtonClick(wxCommandEvent& event);
	//mirip imagewindow
	void OnPaint(wxPaintEvent &event);
private:
	ImageLoaderList *img = nullptr, *btn = nullptr;
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};

