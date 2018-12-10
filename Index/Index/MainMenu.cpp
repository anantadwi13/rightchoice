//init window game
#include "wx/wxprec.h"
//#include <wx/sound.h>
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
	PlaySound(TEXT("bg.wav"), NULL, SND_FILENAME | SND_ASYNC);
	frame->Show(true);
	//wxSound music(wxT("bg.wav"),true);
	//if (music.IsOk())
	//{
	//	music.Play(wxSOUND_ASYNC | wxSOUND_LOOP);
	//	wxMessageOutputDebug().Printf("main");
	//}
	return true;
}