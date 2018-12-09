//tampilan muka game utama
#include "GamePanel.h"

BEGIN_EVENT_TABLE(GamePanel, wxPanel)
	EVT_BUTTON(1001, GamePanel::OnBackButtonClick)
	EVT_PAINT(GamePanel::OnPaint)
END_EVENT_TABLE()

GamePanel::GamePanel(SwitchFrame * parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);

	//load PNGHandler untuk membaca file PNG.
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);

	//instansiasi obj list img dan button img
	this->img = new ImageLoaderList();
	this->btn = new ImageLoaderList();

	//load image dan button image
	this->renderBitmap();

	statIntelektual = new GaugeBar(SwitchFrame::width / 5 + 60, SwitchFrame::height / 10 - 20, 150, 300);
	statKesehatan = new GaugeBar(SwitchFrame::width / 2 + 114, SwitchFrame::height / 10 - 20, 150, 300);
	statHubungan = new GaugeBar(SwitchFrame::width / 5 + 60, SwitchFrame::height / 10 + 60, 150, 300);
	statFinansial = new GaugeBar(SwitchFrame::width / 2 + 114, SwitchFrame::height / 10 + 60, 150, 300);

	statIntelektual->setWidth(50);
}
GamePanel::~GamePanel()
{
	this->btn->Clear();
	this->img->Clear();
	delete this->btn;
	delete this->img;
	delete this->statIntelektual;
	delete this->statKesehatan;
	delete this->statHubungan;
	delete this->statFinansial;
}
void GamePanel::renderBitmap()
{
	//img background
	ImageLoader *img1 = new ImageLoader(wxT("img//bg3.jpg"));
	this->img->Append(img1);

	//img bar otak
	img1 = new ImageLoader(wxT("img//bar_otak.png"));
	this->img->Append(img1);

	//img bar otot
	img1 = new ImageLoader(wxT("img//bar_otot.png"));
	this->img->Append(img1);
	
	//img bar orang
	img1 = new ImageLoader(wxT("img//bar_orang.png"));
	this->img->Append(img1);

	//img bar uang
	img1 = new ImageLoader(wxT("img//bar_uang.png"));
	this->img->Append(img1);

	//img card1
	img1 = new ImageLoader(wxT("img//fig_dosen.png"));
	this->img->Append(img1);

	//button img back
	ButtonImageLoader *btn1 = new ButtonImageLoader(
		wxT("img//btn_kembali.png"), this, 1001, 0, 0, 0);
	this->btn->Append(btn1);
}
void GamePanel::OnBackButtonClick(wxCommandEvent & event)
{
	this->parentFrame->ShowMainPanel();
}
void GamePanel::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this);
	ImageLoaderList::Node* tmp = this->img->GetFirst();

	//variabel gambar
	int posX, posY;

	while (tmp)
	{
		ImageLoader *iml = tmp->GetData();
		if (iml->loc == wxT("img//bg3.jpg"))
			pdc.DrawBitmap(*iml->bitImage, wxPoint(0, 0), true);
		else if (iml->loc == wxT("img//bar_otak.png"))
		{	//draw bar otak
			posX = SwitchFrame::width / 5 - iml->bitImage->GetWidth() / 2;
			posY = SwitchFrame::height / 10 - iml->bitImage->GetHeight() / 2;
			pdc.DrawBitmap(*iml->bitImage, wxPoint(posX, posY), true);
		}
		else if (iml->loc == wxT("img//bar_otot.png"))
		{	//draw bar otot
			posX = SwitchFrame::width / 2 + 54 - iml->bitImage->GetWidth() / 2;
			//posX = SwitchFrame::width * 4 / 5 - iml->bitImage->GetWidth() / 2;
			posY = SwitchFrame::height / 10 - iml->bitImage->GetHeight() / 2;
			pdc.DrawBitmap(*iml->bitImage, wxPoint(posX, posY), true);
		}
		else if (iml->loc == wxT("img//bar_orang.png"))
		{	//draw bar orang
			posX = SwitchFrame::width / 5 - iml->bitImage->GetWidth() / 2;
			posY = SwitchFrame::height / 10 + 80 - iml->bitImage->GetHeight() / 2;
			pdc.DrawBitmap(*iml->bitImage, wxPoint(posX, posY), true);
		}
		else if (iml->loc == wxT("img//bar_uang.png"))
		{	//draw bar uang
			posX = SwitchFrame::width / 2 + 54 - iml->bitImage->GetWidth() / 2;
			//posX = SwitchFrame::width * 4 / 5 - iml->bitImage->GetWidth() / 2;
			posY = SwitchFrame::height / 10 + 80 - iml->bitImage->GetHeight() / 2;
			pdc.DrawBitmap(*iml->bitImage, wxPoint(posX, posY), true);
		}
		else if (iml->loc == wxT("img//fig_dosen.png"))
		{
			posX = SwitchFrame::width / 2 - iml->bitImage->GetWidth() / 2;
			posY = SwitchFrame::height * 3 / 5 - iml->bitImage->GetHeight() / 2;
			pdc.DrawBitmap(*iml->bitImage, wxPoint(posX, posY), true);
		}
		tmp = tmp->GetNext();
	}

	statIntelektual->Draw(pdc);
	statKesehatan->Draw(pdc);
	statHubungan->Draw(pdc);
	statFinansial->Draw(pdc);

	//variable drawing bar dan gauge
	int xrect, yrect, width;

	//problem rect
	xrect = SwitchFrame::width / 2 - 150;
	yrect = SwitchFrame::height * 3 / 5 - 240;
	width = 300;
	pdc.SetPen(*wxRED_PEN);
	pdc.SetBrush(*wxRED_BRUSH);
	//pdc.DrawRectangle(wxPoint(xrect, yrect), wxSize(width, 80));
	//problem string (6 pixel ~ 1 char)
	wxString prob = wxT(
		"Ini problem yang harus kamu selesaikan dalam waktu\nkurang dari "
	"seminggu. Dan dihari Senin kau harus mendemokannya. Apakah kamu siap?");
	//pdc.DrawText(prob, wxPoint(xrect + 10, yrect + 10));
	wxString p = wxT("Ini problem yang harus kamu selesaikan dalam waktu");
	//wxMessageOutputDebug().Printf("p %d", p.Length());
	//p.GetIterForNthChar(2);
	/*pdc.DrawLabel(prob, wxRect(wxPoint(xrect, yrect), wxSize(width, 80)),
		wxALIGN_LEFT | wxALIGN_TOP);*/
	//setfont pada PDC wxdc class

	//footer current score
	pdc.SetPen(*wxBLUE_PEN);
	pdc.SetBrush(*wxBLUE_BRUSH);
	pdc.DrawRectangle(
		wxPoint(0, SwitchFrame::height - 100),
		wxSize(SwitchFrame::width, 70));
}