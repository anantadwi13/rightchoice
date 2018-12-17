//tampilan muka game utama
#include "GamePanel.h"
#include <wx/arrimpl.cpp>
#include<math.h>
#include<ctime>
#include"ScoreDB.h"

using namespace std;

WX_DEFINE_OBJARRAY(IntegerArray);
WX_DEFINE_OBJARRAY(FigurArray);

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

	this->kartuDB = new KartuDB();
	this->scoreDB = new ScoreDB();
	this->cards = kartuDB->getAllCards();

	for (unsigned int i = 0; i < cards.Count(); i++) {
		this->randA.Add(i);
	}
	srand(time(NULL));

	cardNow = getKartuRandom();
	statDay = 1;

	//variable loader
	//gaugebar
	statIntelektual = new GaugeBar(SwitchFrame::width / 5 + 60, SwitchFrame::height / 10 - 20, 150, 300);
	statKesehatan = new GaugeBar(SwitchFrame::width / 2 + 114, SwitchFrame::height / 10 - 20, 150, 300);
	statHubungan = new GaugeBar(SwitchFrame::width / 5 + 60, SwitchFrame::height / 10 + 60, 150, 300);
	statFinansial = new GaugeBar(SwitchFrame::width / 2 + 114, SwitchFrame::height / 10 + 60, 150, 300);

	this->figure.Add(new Figur("Dosen","img//fig_dosen.png","img//bg3.jpg"));
	this->figure.Add(new Figur("Ibu","img//fig_ibu.png", "img//bg2.jpg"));
	this->figure.Add(new Figur("Ibu Kantin","img//fig_ibu_kantin.png", "img//bg6.jpg"));
	this->figure.Add(new Figur("Kating Aktivis","img//fig_kating_aktivis.png", "img//bg7.jpg"));
	this->figure.Add(new Figur("Kating Rajin","img//fig_kating_rajin.png", "img//bg5.jpg"));
	this->figure.Add(new Figur("Teman Angkatan","img//fig_teman_angkatan.png", "img//bg4.jpg"));
	this->figure.Add(new Figur("Teman Proyek","img//fig_teman_proyek.png", "img//bg8.jpg"));

	//card
	card = new Image(SwitchFrame::width / 2 - 150, SwitchFrame::height * 3 / 5 - 150, this->figure[cardNow.getType()].getFile());
	bg = new Image(0, 0, this->figure[cardNow.getType()].getBackgroundFile());


	//problem string
	problem = new Label(0, SwitchFrame::height * 3 / 5 - 240, SwitchFrame::width);
	s = cardNow.getProblem();
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
	s = cardNow.getLeftAnswer();
	leftAnswer->setString(s);
	leftAnswer->setFont(f);
	c = *wxRED;
	leftAnswer->setFill(c);
	p = *wxBLUE_PEN;
	b = *wxWHITE_BRUSH;
	leftAnswer->setPen(p);
	leftAnswer->setBrush(b);
	rightAnswer = new Label(SwitchFrame::width / 2 + 195, SwitchFrame::height * 3 / 5 - 150, 415);
	s = cardNow.getRightAnswer();
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
	s = this->figure[cardNow.getType()].getNama() + "\n" + to_string(statDay) + " hari  dalam perkuliahan";
	skor->setString(s);
	skor->setFont(f);
	c = *wxWHITE;
	skor->setFill(c);
	p = *wxBLUE_PEN;
	b = *wxBLUE_BRUSH;
	skor->setPen(p);
	skor->setBrush(b);
}
void GamePanel::resetGame() {
	this->statDay = 1;
	this->statIntelektual->setWidth(150);
	this->statKesehatan->setWidth(150);
	this->statHubungan->setWidth(150);
	this->statFinansial->setWidth(150);

	cardNow = getKartuRandom();

	this->problem->setString(cardNow.getProblem());
	this->leftAnswer->setString(cardNow.getLeftAnswer());
	this->rightAnswer->setString(cardNow.getRightAnswer());
	wxString skorstring = this->figure[cardNow.getType()].getNama() + "\n" + to_string(statDay) + " hari  dalam perkuliahan";
	this->skor->setString(skorstring);
	this->bg->setLoc(this->figure[cardNow.getType()].getBackgroundFile());
	this->card->setLoc(this->figure[cardNow.getType()].getFile());
}
Kartu GamePanel::getKartuRandom() {
	int random, index;

	if (flagRand==0)
	{
		random = rand() % randA.Count();
		index = randA[random];
		randA.RemoveAt(random, 1);
		randB.Add(index);
		if (randA.Count() <= 0)
			flagRand = 1;
	}
	else {
		random = rand() % randB.Count();
		index = randB[random];
		randB.RemoveAt(random, 1);
		randA.Add(index);
		if (randB.Count() <= 0)
			flagRand = 0;
	}
	return cards[index];
}
GamePanel::~GamePanel()
{
	this->btn->Clear();
	this->img->Clear();
	delete this->kartuDB;
	delete this->scoreDB;
	delete this->btn;
	delete this->img;
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
	//img bar otak
	ImageLoader *img1 = new ImageLoader(wxT("img//bar_otak.png"));
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

	//button img back
	ButtonImageLoader *btn1 = new ButtonImageLoader(
		wxT("img//btn_kembali.png"), this, 1001, 0, 0, 0);
	this->btn->Append(btn1);
}
void GamePanel::OnBackButtonClick(wxCommandEvent &event)
{
	if (!gameover)
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		if (this->statDay > 1)
			this->scoreDB->insert("Player", this->statDay, dt);
	}
	resetGame();
	this->gameover = 0;
	this->parentFrame->ShowMainPanel();
}
void GamePanel::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this);
	ImageLoaderList::Node* tmp = this->img->GetFirst();

	//variabel gambar
	int posX, posY;

	bg->Draw(pdc);

	while (tmp)
	{
		ImageLoader *iml = tmp->GetData();
		if (iml->loc == wxT("img//bar_otak.png"))
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
bool GamePanel::checkStat() {
	wxString gameovertext = "";
	if (this->statIntelektual->getWidth() <= 0) {
		gameovertext = "Sepertinya keaktifanmu dan ketertinggalanmu selama ini tak saling berimbang menurut dosen. Tapi,\nkali ini yang terakhir kamu melakukannya di perkuliahan ini.";
		this->card->setLoc("img//death_low_intelektual.png");
	}
	else if (this->statIntelektual->getWidth() >= this->statIntelektual->getMaxWidth()) {
		gameovertext = "Pemikiranmu memang genius, tapi kelihatannya kamu butuh konseling serius. Ada titipan orangtuamu\nuntuk merujukmu ke rehabilitasi psikologis saat ini juga.Perkuliahanmu sementara ditunda.";
		this->card->setLoc("img//death_high_intelektual.png");
	}
	else if (this->statKesehatan->getWidth() <= 0) {
		gameovertext = "Tiba-tiba kamu terlihat memburuk dan sangat tidak sehat sekarang ini. Kamu terjatuh di tangga kampus\ndan pingsan.Kamu didiagnosa dengan keputusan yang memberatkanmu meneruskan perkuliahanmu saat ini.";
		this->card->setLoc("img//death_low_kesehatan.png");
	}
	else if (this->statKesehatan->getWidth() >= this->statKesehatan->getMaxWidth()) {
		gameovertext = "Hebat sekali! Kamu lolos menjadi public figure karena penampilanmu yang menarik. Temanmu tahu tubuh\nfit - mu pasti memberikan bonusnya suatu hari.Salah satu temanmu berhasil mendaftarkanmu.Terkadang\nlebih baik meminta maaf daripada meminta izin bukan ?";
		this->card->setLoc("img//death_high_kesehatan.png");
	}
	else if (this->statHubungan->getWidth() <= 0) {
		gameovertext = "Orang sekitarmu tak yakin kamu orang yang bisa dipercaya saat ini. Maksud mereka, kamu yang membuat\ndirimu sendiri menjadi orang yang asing di sekitar mereka.Dunia perkuliahanmu tak pernah sesulit\nini untuk dijalani kembali.";
		this->card->setLoc("img//death_low_hubungan.png");
	}
	else if (this->statHubungan->getWidth() >= this->statHubungan->getMaxWidth()) {
		gameovertext = "Setelah menjalani proyek aplikasi, dipercaya menjadi penanggung jawab kepanitiaan, mengikuti\nkegiatan rutin komunitas, berturut - turut tanpa henti, kamu tak mampu memegang kontrol atas dunia\nperkuliahanmu lagi.";
		this->card->setLoc("img//death_high_hubungan.png");
	}
	else if (this->statFinansial->getWidth() <= 0) {
		gameovertext = "Atas berbagai pertimbangan, dosen menyayangkan kamu mundur dari perkuliahan ini karena masalah\nfinansial hidup.Jika seandainya saja kamu mampu mengusahakan beasiswa.";
		this->card->setLoc("img//death_low_financial.png");
	}
	else if (this->statFinansial->getWidth() >= this->statFinansial->getMaxWidth()) {
		gameovertext = "Ini keputusan yang gila, tapi kamu dan temanmu mampu membuat startup UNICORN dengan modal yang kau\npunya saat ini. Namun, kamu harus membayarnya dengan meninggalkan perkuliahanmu sekarang juga untuk\nlebih fokus.";
		this->card->setLoc("img//death_high_financial.png");
	}
	else {
		return false;
	}
	this->gameover = 1;
	this->problem->setString(gameovertext);
	this->leftAnswer->setString("");
	this->rightAnswer->setString("");
	this->skor->setString("Permainan Berakhir\n" + to_string(statDay) + " hari  dalam perkuliahan");
	this->bg->setLoc("img//bg9.jpg");

	Refresh();

	time_t now = time(0);
	char* dt = ctime(&now);
	if (this->statDay > 1)
		this->scoreDB->insert("Player", this->statDay, dt);

	return true;
}
void GamePanel::OnAnswer(wxMouseEvent &event)
{
	wxMessageOutputDebug().Printf("x %d y %d", event.GetX(), event.GetY());
	if (!gameover) {
		if (event.GetX() >= 15 && event.GetX() <= 445
			&& event.GetY() >= SwitchFrame::height * 3 / 5 - 150 && event.GetY() <= SwitchFrame::height * 3 / 5 - 70)
		{	//left answer
			this->statIntelektual->setWidth(this->statIntelektual->getWidth() - cardNow.getLeftValue()->getIntelektual());
			this->statKesehatan->setWidth(this->statKesehatan->getWidth() - cardNow.getLeftValue()->getKesehatan());
			this->statHubungan->setWidth(this->statHubungan->getWidth() - cardNow.getLeftValue()->getHubungan());
			this->statFinansial->setWidth(this->statFinansial->getWidth() - cardNow.getLeftValue()->getFinansial());
			statDay += cardNow.getLeftDay();

			if (checkStat())
				return;

			this->cardNow = getKartuRandom();

			this->problem->setString(cardNow.getProblem());
			this->leftAnswer->setString(cardNow.getLeftAnswer());
			this->rightAnswer->setString(cardNow.getRightAnswer());
			wxString skorstring = this->figure[cardNow.getType()].getNama() + "\n" + to_string(statDay) + " hari  dalam perkuliahan";
			this->skor->setString(skorstring);
			this->bg->setLoc(this->figure[cardNow.getType()].getBackgroundFile());
			this->card->setLoc(this->figure[cardNow.getType()].getFile());
			wxMessageOutputDebug().Printf(this->card->loc);
			Refresh();
			wxMessageOutputDebug().Printf("bundal");
		}
		else if (event.GetX() >= SwitchFrame::width / 2 + 195 && event.GetX() <= SwitchFrame::width / 2 + 615
			&& event.GetY() >= SwitchFrame::height * 3 / 5 - 150 && event.GetY() <= SwitchFrame::height * 3 / 5 - 70)
		{	//right answer
			this->statIntelektual->setWidth(this->statIntelektual->getWidth() - cardNow.getRightValue()->getIntelektual());
			this->statKesehatan->setWidth(this->statKesehatan->getWidth() - cardNow.getRightValue()->getKesehatan());
			this->statHubungan->setWidth(this->statHubungan->getWidth() - cardNow.getRightValue()->getHubungan());
			this->statFinansial->setWidth(this->statFinansial->getWidth() - cardNow.getRightValue()->getFinansial());
			statDay += cardNow.getRightDay();

			if (checkStat())
				return;

			this->cardNow = getKartuRandom();

			this->problem->setString(cardNow.getProblem());
			this->leftAnswer->setString(cardNow.getLeftAnswer());
			this->rightAnswer->setString(cardNow.getRightAnswer());
			wxString skorstring = this->figure[cardNow.getType()].getNama() + "\n" + to_string(statDay) + " hari  dalam perkuliahan";
			this->skor->setString(skorstring);
			this->bg->setLoc(this->figure[cardNow.getType()].getBackgroundFile());
			this->card->setLoc(this->figure[cardNow.getType()].getFile());
			wxMessageOutputDebug().Printf(this->card->loc);
			Refresh();
			wxMessageOutputDebug().Printf("bundar");
		}
	}
}