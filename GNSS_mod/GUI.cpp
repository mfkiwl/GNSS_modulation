#include <wx/wx.h>
#include <wx/string.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include "MyApp.h"
#include "MainFrame.h"
#include "Calculate.h"

//����App
bool MyApp::OnInit() {
	int  cx = GetSystemMetrics(SM_CXFULLSCREEN);
	int  cy = GetSystemMetrics(SM_CYFULLSCREEN);
	MainFrame * mainFrame = new MainFrame(_T("GNSS�ź�BPSK��BOC�������ܷ���"),cx,cy+30);
	mainFrame->Show(true);
	return true;
}

IMPLEMENT_APP(MyApp)