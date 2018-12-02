#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
class MainPanel : public wxPanel
{
public:
	MainPanel(SwitchFrame* parent);
	~MainPanel();
	void OnGameClick(wxCommandEvent& event);
	void OnInstructionClick(wxCommandEvent& event);
	void OnHighscoresClick(wxCommandEvent& event);
	void OnExitClick(wxCommandEvent& event);
	//mirip imagewindow
	void OnPaint(wxPaintEvent &event);
private:
	//mirip imagewindow
	wxBitmap *bgBitmap = nullptr, *logoBitmap = nullptr;
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void loadLogoBitmap();
	void loadBgBitmap();
};