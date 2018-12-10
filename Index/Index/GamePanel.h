#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include "MainPanel.h"
#include "GaugeBar.h"
#include "Label.h"
#include "Card.h"

class GamePanel : public wxPanel
{
public:
	GamePanel(SwitchFrame* parent);
	~GamePanel();
	void OnPaint(wxPaintEvent &event);
	void OnBackButtonClick(wxCommandEvent& event);
	void OnAnswer(wxMouseEvent &event);
private:
	//mirip imagewindow
	ImageLoaderList *img = nullptr, *btn = nullptr;
	Card *card;
	Label *problem;
	Label *skor;	//dan jabatan
	Label *leftAnswer;
	Label *rightAnswer;
	GaugeBar *statIntelektual;
	GaugeBar *statKesehatan;
	GaugeBar *statHubungan;
	GaugeBar *statFinansial;

	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};