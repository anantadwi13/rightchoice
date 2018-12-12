//init window game
#include "wx/wxprec.h"
#include "SwitchFrame.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
class MyApp : public wxApp {
public:
	virtual bool OnInit();
};
IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)
bool MyApp::OnInit() {
	SwitchFrame *frame = new SwitchFrame("righTChoice");
	wxIcon i(wxT("img//favicon.png"), wxBITMAP_TYPE_PNG);
	frame->SetIcon(i);
	PlaySound(TEXT("bg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	frame->Show(true);
	return true;
}