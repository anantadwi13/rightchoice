#pragma once
#include "wx\wx.h"
#include "SwitchFrame.h"
#include "MainPanel.h"
#include "GaugeBar.h"
#include "Label.h"
#include "Image.h"
#include "Kartu.h"
#include "KartuDB.h"
#include "ScoreDB.h"
#include "Figur.h"

WX_DECLARE_OBJARRAY(int, IntegerArray);
WX_DECLARE_OBJARRAY(Figur, FigurArray);

class GamePanel : public wxPanel
{
public:
	GamePanel(SwitchFrame* parent);
	~GamePanel();
	void OnPaint(wxPaintEvent &event);
	void OnBackButtonClick(wxCommandEvent& event);
	void OnAnswer(wxMouseEvent &event);
	void resetGame();
	bool checkStat();
	Kartu getKartuRandom();
private:
	//mirip imagewindow
	ImageLoaderList *img = nullptr, *btn = nullptr;

	Image *card;
	Image *bg;
	Label *problem;
	Label *skor;	//dan jabatan
	Label *leftAnswer;
	Label *rightAnswer;
	GaugeBar *statIntelektual;
	GaugeBar *statKesehatan;
	GaugeBar *statHubungan;
	GaugeBar *statFinansial;
	FigurArray figure;
	
	int gameover = 0;
	int statDay;

	KartuDB *kartuDB;
	ScoreDB *scoreDB;
	Kartu cardNow;
	KartuArray cards;
	IntegerArray randA;
	IntegerArray randB;
	int flagRand = 0;

	SwitchFrame *parentFrame;
	DECLARE_EVENT_TABLE()
	void renderBitmap();
};