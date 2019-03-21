#include <wx/wx.h>
#include <wx/string.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>

#include <wx/frame.h>



#define TIME_DOMAIN 1
#define FREQUENCY_DOMAIN 2
#define AUTOCORRELATION 3
#define TRACKING_ERROR 4
#define TRACKING_ERROR_CN0 6
#define MULTIPATH_ERROR 5
/*
*
* ��дģ��
*
*/

class MainFrame : public wxFrame
{
public:
	//���캯��
	MainFrame(const wxString & title, int wid, int hei);
	//���а��¼�
	void EVENT_CONNECT();
	//��ʼ���ڴ�С����
	int width;
	int height;
	//�¼�����
	//�ź�һfs�����¼�
	void signal_1_in_fs_input_e(wxCommandEvent& event);
	//�ź�һfc�����¼�
	void signal_1_in_fc_input_e(wxCommandEvent& event);
	//�ź�һ��ػ���ʱ�������¼�
	void signal_1_in_tco_input_e(wxCommandEvent& event);
	//�ź�һ���ջ����������¼�
	void signal_1_in_beta_input_e(wxCommandEvent& event);
	//�ź�һ��������������¼�
	void signal_1_in_betat_input_e(wxCommandEvent& event);
	//�ź�һ��ǰ�ͺ󱾵����������¼�
	void signal_1_in_d_input_e(wxCommandEvent& event);
	//�ź�һ�ź���Ԫ�����¼�
	void signal_1_in_signal_input_e(wxCommandEvent& event);

	//�źŶ�fs�����¼�
	void signal_2_in_fs_input_e(wxCommandEvent& event);
	//�źŶ�fc�����¼�
	void signal_2_in_fc_input_e(wxCommandEvent& event);
	//�źŶ���ػ���ʱ�������¼�
	void signal_2_in_tco_input_e(wxCommandEvent& event);
	//�źŶ����ջ����������¼�
	void signal_2_in_beta_input_e(wxCommandEvent& event);
	//�źŶ���������������¼�
	void signal_2_in_betat_input_e(wxCommandEvent& event);
	//�źŶ���ǰ�ͺ󱾵����������¼�
	void signal_2_in_d_input_e(wxCommandEvent& event);
	//�źŶ��ź���Ԫ�����¼�
	void signal_2_in_signal_input_e(wxCommandEvent& event);
	
	//�ź�һ����ʣ�๦�ʼ����¼�
	void signal_1_calculate_lamda_e(wxCommandEvent& event);
	//�ź�һ���޺��������������¼�
	void signal_1_calculate_brms_e(wxCommandEvent& event);
	//�ź�һƵ�׸���ϵ�������¼�
	void signal_1_calculate_kls_e(wxCommandEvent& event);
	//�ź�һ���޺��Ч���δ�������¼�
	void signal_1_calculate_brect_e(wxCommandEvent& event);

	//�źŶ�����ʣ�๦�ʼ����¼�
	void signal_2_calculate_lamda_e(wxCommandEvent& event);
	//�źŶ����޺��������������¼�
	void signal_2_calculate_brms_e(wxCommandEvent& event);
	//�źŶ�Ƶ�׸���ϵ�������¼�
	void signal_2_calculate_kls_e(wxCommandEvent& event);
	//�źŶ����޺��Ч���δ�������¼�
	void signal_2_calculate_brect_e(wxCommandEvent& event);

	//ʱ���λ����¼�
	void imageType1_e(wxCommandEvent& event);
	//Ƶ���λ����¼�
	void imageType41_e(wxCommandEvent& event);
	//��һ������غ��������¼�
	void imageType2_e(wxCommandEvent& event);
	//NELP����ͼ�λ����¼�
	void imageType3_e(wxCommandEvent& event);
	//�ྶ���ͼ�λ����¼�
	void imageType4_e(wxCommandEvent& event);
	//ͼ�α����¼�
	void imageSave_e(wxCommandEvent& event);
	//�������ݱ���¼�
	void initDataset_e(wxCommandEvent& event);
	//��ͼ�����¼�
	void Paint(wxPaintEvent& event);

	//��ͼ����
	//����ʱ����ͼ
	void draw_time_domain(wxDC* dc);
	//����Ƶ����ͼ
	void draw_frequency_domain(wxDC* dc);
	//��������غ���ͼ��
	void draw_autocorrelation(wxDC* dc);
	//������������-���ʱ��ͼ��
	void draw_tracking_error_delta(wxDC* dc);
	//������������-�����ͼ��
	void draw_tracking_error_CN0(wxDC* dc);
	//���ƶྶ���ͼ��
	void draw_multipath_error(wxDC* dc);

	//����ͼƬ����
	void SaveImage();

	 //��������
	wxPanel* panelLeft;//������
	wxPanel* panelLeft_child_1;//�ź�һ���
	wxStaticText* signal_1_title;//�ź�һ����
	wxComboBox* signal_1_choice;//�ź�һѡ������
	wxPanel* signal_1_mainPanel;//�ź�һ�����
	wxPanel* signal_1_inPanel;//�ź�һ�������
	wxStaticText* signal_1_in_title;
	wxStaticText* nulltext1;
	wxStaticText* isUseSignal1_text;
	wxCheckBox* isUseSignal1;//�źŶ��Ƿ�����ѡ���
	wxStaticText* signal_1_in_fs;
	wxTextCtrl* signal_1_in_fs_input;//�ź�һfs�����
	wxStaticText* signal_1_in_fc;
	wxTextCtrl* signal_1_in_fc_input;//�ź�һfc�����
	wxStaticText* signal_1_in_tco;
	wxTextCtrl* signal_1_in_tco_input;//�ź�һtco�����
	wxStaticText* signal_1_in_beta;
	wxTextCtrl* signal_1_in_beta_input;//�ź�һbeta�����
	wxStaticText* signal_1_in_d;
	wxTextCtrl* signal_1_in_d_input;//�ź�һʱ�������
	wxStaticText* signal_1_in_signal;
	wxTextCtrl* signal_1_in_signal_input;//�ź�һ �ź������
	wxStaticText* signal_1_in_betat;
	wxTextCtrl* signal_1_in_betat_input;//�ź�һ beta t�����
	wxPanel* signal_1_outPanel;//�ź�һ������
	wxStaticText* signal_1_out_title;
	wxStaticText* nulltext4;
	wxStaticText* nulltext5;
	wxStaticText* signal_1_out_lamda;
	wxTextCtrl* signal_1_out_lamda_output;//�ź�һ�����
	wxButton* signal_1_calculate_lamda;//�ź�һ�˼��㰴ť
	wxStaticText* signal_1_out_brms;
	wxTextCtrl* signal_1_out_brms_output;//�ź�һ���brms
	wxButton* signal_1_calculate_brms;//�ź�һbrms�����ť
	wxStaticText* signal_1_out_kls;
	wxTextCtrl* signal_1_out_kls_output;//�ź�һ���kls
	wxButton* signal_1_calculate_kls;//�ź�һkls�����ť
	wxStaticText* signal_1_out_brect;
	wxTextCtrl* signal_1_out_brect_output;//�ź�һ���brect
	wxButton* signal_1_calculate_brect;//�ź�һbrect�����ť
	wxPanel* panelLeft_child_2;//�źŶ����
	wxStaticText* signal_2_title;
	wxComboBox* signal_2_choice;//�źŶ�ѡ���
	wxPanel* signal_2_mainPanel;
	wxPanel* signal_2_inPanel;
	wxStaticText* signal_2_in_title;
	wxStaticText* nulltext50;
	wxStaticText* isUseSignal2_text;
	wxCheckBox* isUseSignal2;//�źŶ��Ƿ�����ѡ���
	wxStaticText* signal_2_in_fs;
	wxTextCtrl* signal_2_in_fs_input;//�źŶ�����fs
	wxStaticText* signal_2_in_fc;
	wxTextCtrl* signal_2_in_fc_input;//�źŶ�����fc
	wxStaticText* signal_2_in_tco;
	wxTextCtrl* signal_2_in_tco_input;//�źŶ�����tco
	wxStaticText* signal_2_in_beta;
	wxTextCtrl* signal_2_in_beta_input;//�źŶ�����beta
	wxStaticText* signal_2_in_d;
	wxTextCtrl* signal_2_in_d_input;//�źŶ�����d
	wxStaticText* signal_2_in_signal;
	wxTextCtrl* signal_2_in_signal_input;//�źŶ������ź�
	wxStaticText* signal_2_in_betat;
	wxTextCtrl* signal_2_in_betat_input;//�źŶ� beta t�����
	wxPanel* signal_2_outPanel;
	wxStaticText* signal_2_out_title;
	wxStaticText* nulltext8;
	wxStaticText* nulltext9;
	wxStaticText* signal_2_out_lamda;
	wxTextCtrl* signal_2_out_lamda_output;//�źŶ������
	wxButton* signal_2_calculate_lamda;//�źŶ��������ť
	wxStaticText* signal_2_out_brms;
	wxTextCtrl* signal_2_out_brms_output;//�źŶ����brms
	wxButton* signal_2_calculate_brms;//�źŶ�brms�����ť
	wxStaticText* signal_2_out_kls;
	wxTextCtrl* signal_2_out_kls_output;//�źŶ����kls
	wxButton* signal_2_calculate_kls;//�źŶ�kls�����ť
	wxStaticText* signal_2_out_brect;
	wxTextCtrl* signal_2_out_brect_output;//�źŶ����brect
	wxButton* signal_2_calculate_brect;//�źŶ�brect�����ť
	wxPanel* panelRIGHT;
	wxStaticText* rightTitle;
	wxPanel* right_mianPanel;
	wxButton* imageType1;//ʱ���λ��ư�ť
	wxButton* imageType41;//Ƶ���λ��ư�ť
	wxButton* imageType2;//����غ������λ��ư�ť
	wxButton* imageType3;//��������ͼ�λ��ư�ť
	wxButton* imageType4;//�ྶ�����ư�ť
	wxButton* imageSave;//����ͼ�ΰ�ť
	wxButton* initDataset;//���ɱ��ť
	wxPanel* imagePanel;

	//�����������壬�����жϻ�ʲôͼ
	int ImageType = TIME_DOMAIN;
};