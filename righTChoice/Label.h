#pragma once
#include "GameObject.h"

class Label : public GameObject
{
private:
	int width;
	wxString string;
	wxFont font;
	wxColour color;
	wxPen pen;
	wxBrush brush;
public:
	Label(int x, int y, int width);
	void setFont(wxFont font);
	void setFill(wxColour color);
	void setString(wxString string);
	void setBrush(wxBrush brush);
	void setPen(wxPen pen);
	virtual void Draw(wxBufferedDC &dc);
	~Label();
};

