#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
//��񴰿�
class TableFrame : public wxFrame
{
public:
	wxGrid* grid;
	//�����
	TableFrame(const wxString & title);
	//�˳�����
	void OnQuit(wxCommandEvent & event);
	//��������
	void SaveTable();
};