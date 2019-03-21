#include "MyApp.h"
#include "MainFrame.h"
#include "Calculate.h"
#include <regex>
#include "TableFrame.h"

using namespace std;

/*
*
* ��д������ 
*
*/


void MainFrame::EVENT_CONNECT() {
	signal_1_in_fs_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_fs_input_e), NULL, this);
	signal_1_in_fc_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_fc_input_e), NULL, this);
	signal_1_in_tco_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_tco_input_e), NULL, this);
	signal_1_in_beta_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_beta_input_e), NULL, this);
	signal_1_in_betat_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_betat_input_e), NULL, this);
	signal_1_in_d_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_d_input_e), NULL, this);
	signal_1_in_signal_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_1_in_signal_input_e), NULL, this);
	//�����2
	signal_2_in_fs_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_fs_input_e), NULL, this);
	signal_2_in_fc_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_fc_input_e), NULL, this);
	signal_2_in_tco_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_tco_input_e), NULL, this);
	signal_2_in_beta_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_beta_input_e), NULL, this);
	signal_1_in_betat_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_betat_input_e), NULL, this);
	signal_2_in_d_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_d_input_e), NULL, this);
	signal_2_in_signal_input->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(MainFrame::signal_2_in_signal_input_e), NULL, this);

	//��ť��1
	signal_1_calculate_lamda->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_1_calculate_lamda_e), NULL, this);
	signal_1_calculate_brms->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_1_calculate_brms_e), NULL, this);
	signal_1_calculate_kls->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_1_calculate_kls_e), NULL, this);
	signal_1_calculate_brect->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_1_calculate_brect_e), NULL, this);

	//��ť��2
	signal_2_calculate_lamda->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_2_calculate_lamda_e), NULL, this);
	signal_2_calculate_brms->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_2_calculate_brms_e), NULL, this);
	signal_2_calculate_kls->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_2_calculate_kls_e), NULL, this);
	signal_2_calculate_brect->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::signal_2_calculate_brect_e), NULL, this);

	//��ť��3
	imageType1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::imageType1_e), NULL, this);
	imageType41->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::imageType41_e), NULL, this);
	imageType2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::imageType2_e), NULL, this);
	imageType3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::imageType3_e), NULL, this);
	imageType4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::imageType4_e), NULL, this);
	imageSave->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::imageSave_e), NULL, this);
	initDataset->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::initDataset_e), NULL, this);

	//tt
	imagePanel->Connect(wxEVT_PAINT, wxPaintEventHandler(MainFrame::Paint), NULL, this);
}



//�ź�һ����fs
void MainFrame::signal_1_in_fs_input_e(wxCommandEvent& event) {
	SetStatusText("BOC���Ƶ����ز�Ƶ�ʣ���λΪMHz���˴������ӦΪ1.023MHz�ı���");
}
//�ź�һ����fc
void MainFrame::signal_1_in_fc_input_e(wxCommandEvent& event) {
	SetStatusText("BOC��BPSK���Ƶ���Ƶ�����ʣ���λΪMHz���˴������ӦΪ1.023MHz�ı���");
}
//�ź�һ����tco
void MainFrame::signal_1_in_tco_input_e(wxCommandEvent& event) {
	SetStatusText("��������ػ���ʱ�䣬��λΪms����������Ϊ5ms��20ms");
}
//�ź�һ����beta
void MainFrame::signal_1_in_beta_input_e(wxCommandEvent& event) {
	SetStatusText("���ջ�������λΪMHz����������Ϊ24MHz");
}
//�ź�һ����betat
void MainFrame::signal_1_in_betat_input_e(wxCommandEvent& event) {
	SetStatusText("�����������λΪMHz����������Ϊ24MHz��30MHz");
}
//�ź�һ����d
void MainFrame::signal_1_in_d_input_e(wxCommandEvent& event) {
	SetStatusText("��ǰ���ͺ󱾵���������λΪns���ʵ�������Ϊ��BPSK:50ns,BOC(5,2):80ns,BOC(8,4):50ns,BOC(10,5):40ns");
}
//�ź�һ����signal
void MainFrame::signal_1_in_signal_input_e(wxCommandEvent& event) {
	SetStatusText("�����ź�1�������źţ���ʽӦΪ10101�Ķ���������");
}

//�źŶ�����fs
void MainFrame::signal_2_in_fs_input_e(wxCommandEvent& event) {
	SetStatusText("BOC���Ƶ����ز�Ƶ�ʣ���λΪMHz���˴������ӦΪ1.023MHz�ı���");
}
//�źŶ�����fc
void MainFrame::signal_2_in_fc_input_e(wxCommandEvent& event) {
	SetStatusText("BOC��BPSK���Ƶ���Ƶ�����ʣ���λΪMHz���˴������ӦΪ1.023MHz�ı���");
}
//�źŶ�����tco
void MainFrame::signal_2_in_tco_input_e(wxCommandEvent& event) {
	SetStatusText("��������ػ���ʱ�䣬��λΪms����������Ϊ5ms��20ms");
}
//�źŶ�����beta
void MainFrame::signal_2_in_beta_input_e(wxCommandEvent& event) {
	SetStatusText("���ջ�������λΪMHz����������Ϊ24MHz");
}
//�źŶ�����betat
void MainFrame::signal_2_in_betat_input_e(wxCommandEvent& event) {
	SetStatusText("�����������λΪMHz����������Ϊ24MHz��30MHz");
}
//�źŶ�����d
void MainFrame::signal_2_in_d_input_e(wxCommandEvent& event) {
	SetStatusText("��ǰ���ͺ󱾵���������λΪns���ʵ�������Ϊ��BPSK:50ns,BOC(5,2):80ns,BOC(8,4):50ns,BOC(10,5):40ns");
}
//�źŶ�����signal
void MainFrame::signal_2_in_signal_input_e(wxCommandEvent& event) {
	SetStatusText("�����ź�1�������źţ���ʽӦΪ10101�Ķ���������");
}

//�ź�һ�����
void MainFrame::signal_1_calculate_lamda_e(wxCommandEvent& event) {
	SetStatusText("���޺��ʣ�๦�ʣ���Ҫ������ջ�����");
	//��ȡ�����ź����͡�
	wxString type = signal_1_choice->GetValue();
	wxString lamda;
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	//�ж��ź�����
	if (type.Contains(_T("BOC"))) {
		//�������
		string fs = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());
		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r)) {
			//�����
			lamda.Printf(_T("%lf"), Calculate::boc_lamda(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//���æ�������ֵ
			signal_1_out_lamda_output->SetValue(lamda);
		}
		else {
			//δ�����ȷ����
			signal_1_out_lamda_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type.Contains(_T("BPSK"))) {
		//�������
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());
		if (regex_match(fc, r) && regex_match(beta, r)) {
			//�����
			lamda.Printf(_T("%lf"), Calculate::bpsk_lamda(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//���æ�������ֵ
			signal_1_out_lamda_output->SetValue(lamda);
		}
		else {
			//δ�����ȷ����
			signal_1_out_lamda_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		//nothing to do
		signal_1_out_lamda_output->SetValue(_T("δѡ���ź�����"));
	}
}
//�ź�һ����brms
void MainFrame::signal_1_calculate_brms_e(wxCommandEvent& event) {
	SetStatusText("���޺�ľ�������RMS��������λΪMHz����Ҫ������ջ�����");
	wxString type = signal_1_choice->GetValue();
	wxString brms;
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	//�ж��ź�����
	if (type.Contains(_T("BOC"))) {
		//�������
		string fs = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());
		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r)) {
			//����brms
			brms.Printf(_T("%lf"), Calculate::boc_brms(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//����brms������ֵ
			signal_1_out_brms_output->SetValue(brms);
		}
		else {
			//δ�����ȷ����
			signal_1_out_brms_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type.Contains(_T("BPSK"))) {
		//�������
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());
		if (regex_match(fc, r) && regex_match(beta, r)) {
			//�����
			brms.Printf(_T("%lf"), Calculate::bpsk_brms(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//���æ�������ֵ
			signal_1_out_brms_output->SetValue(brms);
		}
		else {
			//δ�����ȷ����
			signal_1_out_brms_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		//nothing to do
		signal_1_out_brms_output->SetValue(_T("δѡ���ź�����"));
	}
}
//�ź�һ����kls
void MainFrame::signal_1_calculate_kls_e(wxCommandEvent& event) {
	SetStatusText("Ƶ�׸���ϵ������λΪdB/Hz����Ҫ��������źŵĽ��մ��������źŵķ������ͽ��մ��������ź�һΪ�����źţ��źŶ�Ϊ�����ź�");
	wxString type_self = signal_1_choice->GetValue();
	wxString type_another = signal_2_choice->GetValue();
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	wxString kls;
	if (type_self.Contains(_T("BOC")) && type_another.Contains(_T("BOC"))) {

		string fs = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());

		string fs_a = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc_a = string(signal_2_in_fc_input->GetValue().mb_str());
		string betat = string(signal_2_in_betat_input->GetValue().mb_str());

		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r) && regex_match(fs_a, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::boc_boc_kls(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fs_a)*1.023 * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_1_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_1_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type_self.Contains(_T("BOC")) && type_another.Contains(_T("BPSK"))) {
		string fs = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());

		string fc_a = string(signal_2_in_fc_input->GetValue().mb_str());
		string betat = string(signal_2_in_betat_input->GetValue().mb_str());

		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::boc_bpsk_kls(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_1_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_1_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}

	}
	else if (type_self.Contains(_T("BPSK")) && type_another.Contains(_T("BOC"))) {
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());

		string fs_a = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc_a = string(signal_2_in_fc_input->GetValue().mb_str());
		string betat = string(signal_2_in_betat_input->GetValue().mb_str());

		if (regex_match(fc, r) && regex_match(beta, r) && regex_match(fs_a, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::bpsk_boc_kls(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fs_a)*1.023 * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_1_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_1_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type_self.Contains(_T("BPSK")) && type_another.Contains(_T("BPSK"))) {
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());

		string fc_a = string(signal_2_in_fc_input->GetValue().mb_str());
		string betat = string(signal_2_in_betat_input->GetValue().mb_str());

		if (regex_match(fc, r) && regex_match(beta, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::bpsk_bpsk_kls(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_1_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_1_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		signal_1_out_kls_output->SetValue(_T("δѡ���ź�����"));
	}
}
//�ź�һ����brect
void MainFrame::signal_1_calculate_brect_e(wxCommandEvent& event) {
	SetStatusText("���޺����Ч���δ�����λΪMHz����Ҫ������ջ�����");
	//��ȡ�����ź����͡�
	wxString type = signal_1_choice->GetValue();
	wxString brect;
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	//�ж��ź�����
	if (type.Contains(_T("BOC"))) {
		//�������
		string fs = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());
		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r)) {
			//����brect
			brect.Printf(_T("%lf"), Calculate::boc_brect(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//����brect������ֵ
			signal_1_out_brect_output->SetValue(brect);
		}
		else {
			//δ�����ȷ����
			signal_1_out_brect_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type.Contains(_T("BPSK"))) {
		//�������
		string fc = string(signal_1_in_fc_input->GetValue().mb_str());
		string beta = string(signal_1_in_beta_input->GetValue().mb_str());
		if (regex_match(fc, r) && regex_match(beta, r)) {
			//����brect
			brect.Printf(_T("%lf"), Calculate::bpsk_brect(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//����brect������ֵ
			signal_1_out_brect_output->SetValue(brect);
		}
		else {
			//δ�����ȷ����
			signal_1_out_brect_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		//nothing to do
		signal_1_out_brect_output->SetValue(_T("δѡ���ź�����"));
	}
}

//�źŶ������
void MainFrame::signal_2_calculate_lamda_e(wxCommandEvent& event) {
	SetStatusText("���޺��ʣ�๦�ʣ���Ҫ������ջ�����");
	wxString type = signal_2_choice->GetValue();
	wxString lamda;
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	//�ж��ź�����
	if (type.Contains(_T("BOC"))) {
		//�������
		string fs = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());
		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r)) {
			//�����
			lamda.Printf(_T("%lf"), Calculate::boc_lamda(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//���æ�������ֵ
			signal_2_out_lamda_output->SetValue(lamda);
		}
		else {
			//δ�����ȷ����
			signal_2_out_lamda_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type.Contains(_T("BPSK"))) {
		//�������
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());
		if (regex_match(fc, r) && regex_match(beta, r)) {
			//�����
			lamda.Printf(_T("%lf"), Calculate::bpsk_lamda(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//���æ�������ֵ
			signal_2_out_lamda_output->SetValue(lamda);
		}
		else {
			//δ�����ȷ����
			signal_2_out_lamda_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		//nothing to do
		signal_1_out_lamda_output->SetValue(_T("δѡ���ź�����"));
	}
}
//�źŶ�����brms
void MainFrame::signal_2_calculate_brms_e(wxCommandEvent& event) {
	SetStatusText("���޺�ľ�������RMS��������λΪMHz����Ҫ������ջ�����");
	wxString type = signal_2_choice->GetValue();
	wxString brms;
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	//�ж��ź�����
	if (type.Contains(_T("BOC"))) {
		//�������
		string fs = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());
		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r)) {
			//����brms
			brms.Printf(_T("%lf"), Calculate::boc_brms(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//����brms������ֵ
			signal_2_out_brms_output->SetValue(brms);
		}
		else {
			//δ�����ȷ����
			signal_2_out_brms_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type.Contains(_T("BPSK"))) {
		//�������
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());
		if (regex_match(fc, r) && regex_match(beta, r)) {
			//�����
			brms.Printf(_T("%lf"), Calculate::bpsk_brms(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//���æ�������ֵ
			signal_2_out_brms_output->SetValue(brms);
		}
		else {
			//δ�����ȷ����
			signal_2_out_brms_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		//nothing to do
		signal_1_out_brms_output->SetValue(_T("δѡ���ź�����"));
	}
}
//�źŶ�����kls
void MainFrame::signal_2_calculate_kls_e(wxCommandEvent& event) {
	SetStatusText("Ƶ�׸���ϵ������λΪdB/Hz����Ҫ��������źŵĽ��մ��������źŵķ������ͽ��մ��������źŶ�Ϊ�����źţ��ź�һΪ�����ź�");
	wxString type_self = signal_2_choice->GetValue();
	wxString type_another = signal_1_choice->GetValue();
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	wxString kls;
	if (type_self.Contains(_T("BOC")) && type_another.Contains(_T("BOC"))) {

		string fs = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());

		string fs_a = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc_a = string(signal_1_in_fc_input->GetValue().mb_str());
		string betat = string(signal_1_in_betat_input->GetValue().mb_str());

		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r) && regex_match(fs_a, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::boc_boc_kls(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fs_a)*1.023 * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_2_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_2_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type_self.Contains(_T("BOC")) && type_another.Contains(_T("BPSK"))) {
		string fs = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());

		string fc_a = string(signal_1_in_fc_input->GetValue().mb_str());
		string betat = string(signal_1_in_betat_input->GetValue().mb_str());

		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::boc_bpsk_kls(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_2_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_2_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}

	}
	else if (type_self.Contains(_T("BPSK")) && type_another.Contains(_T("BOC"))) {
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());

		string fs_a = string(signal_1_in_fs_input->GetValue().mb_str());
		string fc_a = string(signal_1_in_fc_input->GetValue().mb_str());
		string betat = string(signal_1_in_betat_input->GetValue().mb_str());

		if (regex_match(fc, r) && regex_match(beta, r) && regex_match(fs_a, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::bpsk_boc_kls(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fs_a)*1.023 * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_2_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_2_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type_self.Contains(_T("BPSK")) && type_another.Contains(_T("BPSK"))) {
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());

		string fc_a = string(signal_1_in_fc_input->GetValue().mb_str());
		string betat = string(signal_1_in_betat_input->GetValue().mb_str());

		if (regex_match(fc, r) && regex_match(beta, r) && regex_match(fc_a, r) && regex_match(betat, r)) {
			//����brms
			kls.Printf(_T("%lf"), Calculate::bpsk_bpsk_kls(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000, Calculate::stringToNum<double>(fc_a)*1.023 * 1000000, Calculate::stringToNum<double>(betat) * 1000000));
			//����brms������ֵ
			signal_2_out_kls_output->SetValue(kls);
		}
		else {
			//δ�����ȷ����
			signal_2_out_kls_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		signal_2_out_kls_output->SetValue(_T("δѡ���ź�����"));
	}
}
//�źŶ�����brect
void MainFrame::signal_2_calculate_brect_e(wxCommandEvent& event) {
	SetStatusText("���޺����Ч���δ�����λΪMHz����Ҫ������ջ�����");
	//��ȡ�����ź����͡�
	wxString type = signal_2_choice->GetValue();
	wxString brect;
	std::regex r("([1-9]+[0-9]*|0)(\\.[\\d]+)?");
	//�ж��ź�����
	if (type.Contains(_T("BOC"))) {
		//�������
		string fs = string(signal_2_in_fs_input->GetValue().mb_str());
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());
		if (regex_match(fs, r) && regex_match(fc, r) && regex_match(beta, r)) {
			//����brect
			brect.Printf(_T("%lf"), Calculate::boc_brect(Calculate::stringToNum<double>(fs)*1.023 * 1000000, Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//����brect������ֵ
			signal_2_out_brect_output->SetValue(brect);
		}
		else {
			//δ�����ȷ����
			signal_2_out_brect_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else if (type.Contains(_T("BPSK"))) {
		//�������
		string fc = string(signal_2_in_fc_input->GetValue().mb_str());
		string beta = string(signal_2_in_beta_input->GetValue().mb_str());
		if (regex_match(fc, r) && regex_match(beta, r)) {
			//����brect
			brect.Printf(_T("%lf"), Calculate::bpsk_brect(Calculate::stringToNum<double>(fc)*1.023 * 1000000, Calculate::stringToNum<double>(beta) * 1000000));
			//����brect������ֵ
			signal_2_out_brect_output->SetValue(brect);
		}
		else {
			//δ�����ȷ����
			signal_2_out_brect_output->SetValue(_T("����ȱ�ٻ����"));
		}
	}
	else {
		//nothing to do
		signal_1_out_brect_output->SetValue(_T("δѡ���ź�����"));
	}
}

//����ʱ����
void MainFrame::imageType1_e(wxCommandEvent& event) {
	SetStatusText("����ʱ����");
	ImageType = TIME_DOMAIN;
	imageType3->SetLabel(_T("��������"));
	imagePanel->Refresh();
}
//����Ƶ����
void MainFrame::imageType41_e(wxCommandEvent& event) {
	SetStatusText("����Ƶ����");
	ImageType = FREQUENCY_DOMAIN;
	imageType3->SetLabel(_T("��������"));
	imagePanel->Refresh();
}
//��������غ�������
void MainFrame::imageType2_e(wxCommandEvent& event) {
	SetStatusText("���ɹ�һ������غ������Σ���Ҫ������ջ�����");
	ImageType = AUTOCORRELATION;
	imageType3->SetLabel(_T("��������"));
	imagePanel->Refresh();
}
//�������������
void MainFrame::imageType3_e(wxCommandEvent& event) {
	wxString str = imageType3->GetLabel();
	if (str.Contains(_T("�л�x��Ϊ��"))) {
		SetStatusText("����  ����پ��������-��ǰ�ͺ󱾵�����  ���Σ���Ҫ������ջ�����ͼ�������ػ���ʱ�䣬��ʱ�����Ĭ��Ϊ30db-Hz");
		ImageType = TRACKING_ERROR;
		imageType3->SetLabel(_T("�л�x��ΪC/N0"));
	}
	else if (str.Contains(_T("�л�x��ΪC/N0"))) {
		SetStatusText("����  ����پ��������-�����ź������  ���Σ���Ҫ������ջ�������������ػ���ʱ�䡢��ǰ�ͺ󱾵�����");
		ImageType = TRACKING_ERROR_CN0;
		imageType3->SetLabel(_T("�л�x��Ϊ��"));
	}
	else {
		ImageType = TRACKING_ERROR;
		SetStatusText("����  ����پ��������-��ǰ�ͺ󱾵�����  ���Σ���Ҫ������ջ�����ͼ�������ػ���ʱ�䣬��ʱ�����Ĭ��Ϊ30db-Hz");
		imageType3->SetLabel(_T("�л�x��ΪC/N0"));
	}
	imagePanel->Refresh();
}

//���ɶྶ����Ӱ�첨��
void MainFrame::imageType4_e(wxCommandEvent& event) {
	SetStatusText("���ɶྶ�����粨�Σ���Ҫ������ջ�������ǰ�ͺ󱾵�����");
	ImageType = MULTIPATH_ERROR;
	imageType3->SetLabel(_T("��������"));
	imagePanel->Refresh();
}
//���沨��
void MainFrame::imageSave_e(wxCommandEvent& event) {
	MainFrame::SaveImage();
	SetStatusText("���沨�γɹ�");
}
//���ɱ��
void MainFrame::initDataset_e(wxCommandEvent& event) {
	TableFrame * tableFrame = new TableFrame(_T("����GPS�����ź�����"));
	tableFrame->Show(true);
	SetStatusText("���ɲ�������ɹ�");
}

//������ͼ�¼�
void MainFrame::Paint(wxPaintEvent& event) {
	wxPaintDC dc(this->imagePanel);
	wxPaintDC *DC = &dc;

	switch (ImageType)
	{
	case TIME_DOMAIN:
		draw_time_domain(DC);
		break;
	case FREQUENCY_DOMAIN:
		draw_frequency_domain(DC);
		break;
	case AUTOCORRELATION:
		draw_autocorrelation(DC);
		break;
	case TRACKING_ERROR:
		draw_tracking_error_delta(DC);
		break;
	case MULTIPATH_ERROR:
		draw_multipath_error(DC);
		break;
	case TRACKING_ERROR_CN0:
		draw_tracking_error_CN0(DC);
		break;
	default:
		draw_time_domain(DC);
		break;
	}
}
