//tampilan muka menu utama
#include "MainPanel.h"
#define h 65
WX_DEFINE_LIST(ImageLoaderList);
BEGIN_EVENT_TABLE(MainPanel, wxPanel)
	EVT_BUTTON(1001, MainPanel::OnGameClick)
	EVT_BUTTON(1002, MainPanel::OnInstructionClick)
	EVT_BUTTON(1003, MainPanel::OnHighscoresClick)
	EVT_BUTTON(1004, MainPanel::OnAboutClick)
	EVT_BUTTON(1005, MainPanel::OnExitClick)
	EVT_PAINT(MainPanel::OnPaint)
END_EVENT_TABLE()
MainPanel::MainPanel(SwitchFrame * parent) :
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
}
MainPanel::~MainPanel()
{
	this->btn->Clear();
	this->img->Clear();
	delete this->btn;
	delete this->img;
}
void MainPanel::renderBitmap()
{	/*wxMessageOutputDebug().Printf("Relative path of image is at %s", fileLocation);*/
	//img background
	ImageLoader *img1 = new ImageLoader(wxT("img//bg1.jpg"));
	this->img->Append(img1);
	
	//img logo
	img1 = new ImageLoader(wxT("img//logo.png"));
	this->img->Append(img1);

	//button img mulai
	ButtonImageLoader *btn1 = new ButtonImageLoader(
		wxT("img//btn_mulai.png"), this, 1001, 0 * h);
	this->btn->Append(btn1);

	//button img instruksi
	btn1 = new ButtonImageLoader(
		wxT("img//btn_instruksi.png"), this, 1002, 1 * h);
	this->btn->Append(btn1);

	//button img highscores
	btn1 = new ButtonImageLoader(
		wxT("img//btn_skor.png"), this, 1003, 2 * h);
	this->btn->Append(btn1);

	//button img about
	btn1 = new ButtonImageLoader(
		wxT("img//btn_tentang.png"), this, 1004, 3 * h);
	this->btn->Append(btn1);

	//button img keluar
	btn1 = new ButtonImageLoader(
		wxT("img//btn_keluar.png"), this, 1005, 4 * h);
	this->btn->Append(btn1);
}
void MainPanel::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	ImageLoaderList::Node* tmp = this->img->GetFirst();
	
	//gambar image selain button
	while (tmp)
	{
		ImageLoader *iml = tmp->GetData();
		if (iml->loc == wxT("img//bg1.jpg"))
			pdc.DrawBitmap(*iml->bitImage, wxPoint(0, 0), true);
		if (iml->loc == wxT("img//logo.png"))
		{
			int posX = SwitchFrame::width / 2 - iml->bitImage->GetWidth() / 2;
			int posY = SwitchFrame::height / 4 - iml->bitImage->GetHeight() / 2;
			pdc.DrawBitmap(*iml->bitImage, wxPoint(posX, posY), true);
		}
		tmp = tmp->GetNext();
	}
}
void MainPanel::OnGameClick(wxCommandEvent & event)
{
	parentFrame->ShowGamePanel();
}
void MainPanel::OnInstructionClick(wxCommandEvent & event)
{
	parentFrame->ShowInstructionPanel();
}
void MainPanel::OnHighscoresClick(wxCommandEvent & event)
{
	ScoreDB scoreDB;
	ScoreArray scores = scoreDB.getAllScores(5);

	wxString scoreText = "";

	for (unsigned int i = 0; i < scores.Count(); i++)
	{
		scoreText += "#"+to_string(i+1)+"\nSkor       : "+to_string(scores[i].getScore())+ "\nTanggal : " + scores[i].getDate()+"\n";
	}

	wxMessageBox(wxString::Format
	(
		"Highscores\n\n"
		+ scoreText
	),
		"Highscores righTChoice",
		wxOK,
		this);
}
void MainPanel::OnAboutClick(wxCommandEvent & event)
{
	wxMessageBox(wxString::Format
	(
		"About Game\n\n"
		"Version 1.0\n"
		"Developed by Ananta Dwi Prasetya dan Rangga Kusuma Dinata\n"
		"Inspired by Lapse\nMusic by Built by Titan ft Srvcina - The Darkness"
	),
		"About righTChoice",
		wxOK,
		this);
}
void MainPanel::OnExitClick(wxCommandEvent & event)
{
	parentFrame->Close(true);
}