#include "TableFrame.h"
#include "Calculate.h"
//�����view
TableFrame::TableFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(960, 380))
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* Sizer;
	Sizer = new wxBoxSizer(wxVERTICAL);

	grid = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

	grid->CreateGrid(12, 6);
	grid->EnableEditing(false);
	grid->EnableGridLines(true);
	grid->EnableDragGridSize(true);
	grid->SetMargins(0, 0);

	grid->SetColSize(0, 290);
	grid->SetColSize(1, 117);
	grid->SetColSize(2, 117);
	grid->SetColSize(3, 117);
	grid->SetColSize(4, 117);
	grid->SetColSize(5, 117);
	grid->EnableDragColMove(true);
	grid->EnableDragColSize(true);
	grid->SetColLabelSize(30);
	grid->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

	grid->SetRowSize(0, 24);
	grid->SetRowSize(1, 24);
	grid->SetRowSize(2, 24);
	grid->SetRowSize(3, 24);
	grid->SetRowSize(4, 24);
	grid->SetRowSize(5, 24);
	grid->SetRowSize(6, 24);
	grid->SetRowSize(7, 24);
	grid->SetRowSize(8, 24);
	grid->SetRowSize(9, 24);
	grid->SetRowSize(10, 24);
	grid->SetRowSize(11, 24);
	grid->EnableDragRowSize(true);
	grid->SetRowLabelSize(30);
	grid->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
	grid->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_TOP);
	Sizer->Add(grid, 0, wxALL | wxEXPAND, 5);

	wxString str;
	//����
	grid->SetCellValue(0, 0, _T("����"));
	grid->SetCellValue(0, 1, _T("1.023MHzBPSK"));
	grid->SetCellValue(0, 2, _T("10.23MhzBPSK"));
	grid->SetCellValue(0, 3, _T("Boc(5��2)"));
	grid->SetCellValue(0, 4, _T("Boc(8��4)"));
	grid->SetCellValue(0, 5, _T("Boc(10��5)"));

	//Ƶ�������Ƶ�����ĵ�Ƶƫ
	grid->SetCellValue(1, 0, _T("Ƶ�������Ƶ�����ĵ�Ƶƫ(MHz)"));
	grid->SetCellValue(1, 1, _T("0"));
	grid->SetCellValue(1, 2, _T("0"));
	str.Printf(_T("%lf"), Calculate::boc_frequency_offset(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(1, 3, _T("��") + str);
	str.Printf(_T("%lf"), Calculate::boc_frequency_offset(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(1, 4, _T("��") + str);
	str.Printf(_T("%lf"), Calculate::boc_frequency_offset(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(1, 5, _T("��") + str);

	//������������ܶ�
	grid->SetCellValue(2, 0, _T("������������ܶ�(dBW/Hz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_maxf(1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(2, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_maxf(10 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(2, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_maxf(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(2, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_maxf(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(2, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_maxf(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(2, 5, str);

	//90%���ʵĴ���
	grid->SetCellValue(3, 0, _T("90%���ʵĴ���(MHz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_beta_90(1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(3, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_beta_90(10 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(3, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_beta_90(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(3, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_beta_90(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(3, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_beta_90(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(3, 5, str);

	//������ʧ
	grid->SetCellValue(4, 0, _T("������ʧ(dB)"));
	str.Printf(_T("%lf"), Calculate::bpsk_beta_loss(1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(4, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_beta_loss(10 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(4, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_beta_loss(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(4, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_beta_loss(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(4, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_beta_loss(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(4, 5, str);

	//RMS����
	grid->SetCellValue(5, 0, _T("RMS����(MHz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_brms(1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(5, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_brms(10 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(5, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_brms(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(5, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_brms(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(5, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_brms(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(5, 5, str);

	//��Ч���δ���
	grid->SetCellValue(6, 0, _T("��Ч���δ���(MHz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_brect(1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(6, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_brect(10 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(6, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_brect(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(6, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_brect(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(6, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_brect(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(6, 5, str);

	//�������Ƶ�׸���ϵ��
	grid->SetCellValue(7, 0, _T("�������Ƶ�׸���ϵ��(dB/Hz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_bpsk_kls(1 * 1.023 * 1000000, 24 * 1000000, 1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(7, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_bpsk_kls(10 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(7, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_boc_kls(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000, 5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(7, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_boc_kls(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000, 8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(7, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_boc_kls(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(7, 5, str);

	//��1.023MHzBPSK��Ƶ�׸���ϵ��
	grid->SetCellValue(8, 0, _T("��1.023MHzBPSK��Ƶ�׸���ϵ��(dB/Hz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_bpsk_kls(1 * 1.023 * 1000000, 24 * 1000000, 1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(8, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_bpsk_kls(10 * 1.023 * 1000000, 24 * 1000000, 1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(8, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_bpsk_kls(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000, 1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(8, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_bpsk_kls(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000, 1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(8, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_bpsk_kls(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000, 1 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(8, 5, str);

	//��BOC(10,5)��Ƶ�׸���ϵ��
	grid->SetCellValue(9, 0, _T("��BOC(10��5)��Ƶ�׸���ϵ��(dB/Hz)"));
	str.Printf(_T("%lf"), Calculate::bpsk_boc_kls(1 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(9, 1, str);
	str.Printf(_T("%lf"), Calculate::bpsk_boc_kls(10 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(9, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_boc_kls(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(9, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_boc_kls(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(9, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_boc_kls(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000, 10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(9, 5, str);

	//����غ����������һ�����ʱ��
	grid->SetCellValue(10, 0, _T("����غ����������һ�����ʱ��(ns)"));
	str.Printf(_T("��"));
	grid->SetCellValue(10, 1, str);
	grid->SetCellValue(10, 2, str);
	double delay1 = Calculate::boc_autocorrelation_delay(5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000);
	str.Printf(_T("%lf"), delay1);
	grid->SetCellValue(10, 3, str);
	double delay2 = Calculate::boc_autocorrelation_delay(8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000);
	str.Printf(_T("%lf"), delay2);
	grid->SetCellValue(10, 4, str);
	double delay3 = Calculate::boc_autocorrelation_delay(10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000);
	str.Printf(_T("%lf"), delay3);
	grid->SetCellValue(10, 5, str);

	//����غ�����һ����������ķ���ƽ��֮��
	grid->SetCellValue(11, 0, _T("����غ�����һ����������ķ���ƽ��֮��"));
	str.Printf(_T("��"));
	grid->SetCellValue(11, 1, str);
	grid->SetCellValue(11, 2, str);
	str.Printf(_T("%lf"), Calculate::boc_autocorrelation_amplitude_ratio(delay1, 5 * 1.023 * 1000000, 2 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(11, 3, str);
	str.Printf(_T("%lf"), Calculate::boc_autocorrelation_amplitude_ratio(delay2, 8 * 1.023 * 1000000, 4 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(11, 4, str);
	str.Printf(_T("%lf"), Calculate::boc_autocorrelation_amplitude_ratio(delay3,10 * 1.023 * 1000000, 5 * 1.023 * 1000000, 24 * 1000000));
	grid->SetCellValue(11, 5, str);


	SaveTable();
	this->SetSizer(Sizer);
	this->Layout();

	this->Centre(wxBOTH);
}

void TableFrame::OnQuit(wxCommandEvent & event)
{
	Close(true);
}

//������Ϊcsv�ļ�
void TableFrame::SaveTable()
{
	ofstream outFile;
	int i, j;
	outFile.open("data.csv", ios::out);
	for (i = 0; i <= 11; i++) {
		for (j = 0; j <= 4; j++) {
			outFile << grid->GetCellValue(i, j).mb_str() << ",";
		}
		outFile << grid->GetCellValue(i, 5).mb_str() << endl;
	}
	outFile.close();
}