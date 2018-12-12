#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include <wx/listimpl.cpp> 
#include "ImageLoader.h"
#include "ButtonImageLoader.h"
#include "ScoreDB.h"
#include "wx/dcbuffer.h"

WX_DECLARE_LIST(ImageLoader, ImageLoaderList);

class MainPanel : public wxPanel
{
public:
	MainPanel(SwitchFrame* parent);
	~MainPanel();
	void OnGameClick(wxCommandEvent& event);
	void OnInstructionClick(wxCommandEvent& event);
	void OnHighscoresClick(wxCommandEvent& event);
	void OnAboutClick(wxCommandEvent& event);
	void OnExitClick(wxCommandEvent& event);
	void OnOOPClick(wxCommandEvent& event);
	//mirip imagewindow
	void OnPaint(wxPaintEvent &event);
private:
	//mirip imagewindow
	ImageLoaderList *img = nullptr,*btn = nullptr;
	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};