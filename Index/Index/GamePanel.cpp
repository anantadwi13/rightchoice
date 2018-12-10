//tampilan muka game utama
#include "GamePanel.h"

BEGIN_EVENT_TABLE(GamePanel, wxPanel)
	EVT_BUTTON(1001, GamePanel::OnBackButtonClick)
	EVT_LEFT_DOWN(GamePanel::OnAnswer)
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

	wxString s;
	wxFont f = wxFont(15, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxColour c;
	wxPen p;
	wxBrush b;

	//variable loader
	//gaugebar
	statIntelektual = new GaugeBar(SwitchFrame::width / 5 + 60, SwitchFrame::height / 10 - 20, 150, 300);
	statKesehatan = new GaugeBar(SwitchFrame::width / 2 + 114, SwitchFrame::height / 10 - 20, 150, 300);
	statHubungan = new GaugeBar(SwitchFrame::width / 5 + 60, SwitchFrame::height / 10 + 60, 150, 300);
	statFinansial = new GaugeBar(SwitchFrame::width / 2 + 114, SwitchFrame::height / 10 + 60, 150, 300);
	
	//card
	card = new Card(SwitchFrame::width / 2 - 150, SwitchFrame::height * 3 / 5 - 150, wxT("img//fig_dosen.png"));
	
	//problem string
	problem = new Label(0, SwitchFrame::height * 3 / 5 - 240, SwitchFrame::width);
	s = wxT("Ini problem yang harus kamu selesaikan dalam waktu kurang dari "
		"seminggu. Dan dihari Senin kau harus\nmendemokannya. Apakah kamu siap?");
	problem->setString(s);
	problem->setFont(f);
	c = *wxBLACK;
	problem->setFill(c);
	p = *wxWHITE_PEN;
	b = *wxWHITE_BRUSH;
	problem->setPen(p);
	problem->setBrush(b);
	
	//answer string
	leftAnswer = new Label(15, SwitchFrame::height * 3 / 5 - 150, 430);
	s = wxT("Sepertinya kami bisa, pak Doseno");
	leftAnswer->setString(s);
	leftAnswer->setFont(f);
	c = *wxRED;
	leftAnswer->setFill(c);
	p = *wxBLUE_PEN;
	b = *wxWHITE_BRUSH;
	leftAnswer->setPen(p);
	leftAnswer->setBrush(b);
	rightAnswer = new Label(SwitchFrame::width / 2 + 195, SwitchFrame::height * 3 / 5 - 150, 415);
	s = wxT("Sepertinya tidak bisa, pak Doseno");
	rightAnswer->setString(s);
	rightAnswer->setFont(f);
	c = *wxBLUE;
	rightAnswer->setFill(c);
	p = *wxRED_PEN;
	b = *wxWHITE_BRUSH;
	rightAnswer->setPen(p);
	rightAnswer->setBrush(b);
	
	//skor, nama, jabatan
	skor = new Label(0, SwitchFrame::height - 100, SwitchFrame::width);
	s = wxT("Pak Doseno - Dosen\n""2 hari dalam perkuliahan");
	skor->setString(s);
	skor->setFont(f);
	c = *wxWHITE;
	skor->setFill(c);
	p = *wxBLUE_PEN;
	b = *wxBLUE_BRUSH;
	skor->setPen(p);
	skor->setBrush(b);

	//statIntelektual->setWidth(50);
}
GamePanel::~GamePanel()
{
	this->btn->Clear();
	this->img->Clear();
	delete this->btn;
	delete this->img;
	delete this->card;
	delete this->statIntelektual;
	delete this->statKesehatan;
	delete this->statHubungan;
	delete this->statFinansial;
	delete this->problem;
	delete this->leftAnswer;
	delete this->rightAnswer;
	delete this->skor;
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
	//img1 = new ImageLoader(wxT("img//fig_dosen.png"));
	//this->img->Append(img1);

	//button img back
	ButtonImageLoader *btn1 = new ButtonImageLoader(
		wxT("img//btn_kembali.png"), this, 1001, 0, 0, 0);
	this->btn->Append(btn1);
}
void GamePanel::OnBackButtonClick(wxCommandEvent &event)
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
		/*else
		{
			
		}*/
		tmp = tmp->GetNext();
	}

	card->Draw(pdc);
	statIntelektual->Draw(pdc);
	statKesehatan->Draw(pdc);
	statHubungan->Draw(pdc);
	statFinansial->Draw(pdc);
	problem->Draw(pdc);
	leftAnswer->Draw(pdc);
	rightAnswer->Draw(pdc);
	skor->Draw(pdc);

}
void GamePanel::OnAnswer(wxMouseEvent &event)
{
	wxMessageOutputDebug().Printf("x %d y %d", event.GetX(), event.GetY());
	if (event.GetX()>= 15 && event.GetX() <=445
		&& event.GetY()>= SwitchFrame::height * 3 / 5 - 150 && event.GetY() <= SwitchFrame::height * 3 / 5 - 70)
	{	//left answer
		this->statIntelektual->setWidth(40);
		this->statKesehatan->setWidth(80);
		this->problem->setString(wxT("Minggu ini melelahkan! Ayo longtrip besok!"));
		this->leftAnswer->setString(wxT("Ayo budalkan!"));
		this->rightAnswer->setString(wxT("Yang benar saja, minggu ini minggu FP"));
		this->skor->setString(wxT("Blekping - Teman Proyek\n""5 hari  dalam perkuliahan"));
		this->card->loc = wxT("img//fig_teman_proyek.png");
		wxMessageOutputDebug().Printf(this->card->loc);
		Refresh();
		wxMessageOutputDebug().Printf("bundal");
	}
	else if (event.GetX() >= SwitchFrame::width / 2 + 195 && event.GetX() <= SwitchFrame::width / 2 + 615
		&& event.GetY() >= SwitchFrame::height * 3 / 5 - 150 && event.GetY() <= SwitchFrame::height * 3 / 5 - 70)
	{	//right answer
		this->statHubungan->setWidth(60);
		this->statKesehatan->setWidth(80);
		this->problem->setString(wxT("Besok kakak bisa pulang kerumah?"));
		this->leftAnswer->setString(wxT("Baik bisa bu"));
		this->rightAnswer->setString(wxT("Sebenarnya aku ingin, tapi\ntak bisa bu"));
		this->skor->setString(wxT("Esmeralda - Ibu\n""3 hari  dalam perkuliahan"));
		this->card->loc = wxT("img//fig_ibu.png");
		wxMessageOutputDebug().Printf(this->card->loc);
		Refresh();
		wxMessageOutputDebug().Printf("bundar");
	}
}