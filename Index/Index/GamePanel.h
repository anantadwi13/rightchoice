#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include "MainPanel.h"
#include "GaugeBar.h"

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

	GaugeBar *statIntelektual;
	GaugeBar *statKesehatan;
	GaugeBar *statHubungan;
	GaugeBar *statFinansial;

	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};