//������ͷ�ļ�
#include <sstream> 
#include <math.h>
//�����
#define PI 3.14159265358979323846
class Calculate {
public:
	//�ַ���ת���ָ�������
	template <class Type>
	Type static stringToNum(const std::string& str)
	{
		istringstream iss(str);
		Type num;
		iss >> num;
		return num;
	}

	/*
	boc���ƵĹ������ܶ�
	f:Ƶ�ʵ㣬��λΪHz
	fs�����ز�Ƶ�ʣ���λΪHz
	fc����Ƶ�����ʣ���λΪHz
	return��fƵ�ʵĹ������ܶ�
	*/
	double static boc_f(double f, double fs, double fc);

	/*
	bpsk���ƵĹ������ܶ�
	f:Ƶ�ʵ㣬��λΪHz
	fc����Ƶ�����ʣ���λΪHz
	return��fƵ�ʵĹ������ܶ�
	*/
	double static bpsk_f(double f, double fc);

	/*
	boc���ƴ��޺��ʣ�๦��
	fs�����ز�Ƶ�ʣ���λΪHz
	fc����Ƶ�����ʣ���λΪHz
	beta�����ջ�����
	return��beta���޺��ʣ�๦��
	*/
	double static boc_lamda(double fs, double fc, double beta);

	/*
	bpsk���ƴ��޺��ʣ�๦��
	fc����Ƶ�����ʣ���λΪHz
	beta�����ջ�����
	return��beta���޺��ʣ�๦��
	*/
	double static bpsk_lamda(double fc, double beta);

	/*
	boc���ƴ��޺�ľ���������
	fs�����ز�Ƶ�ʣ���λΪHz
	fc����Ƶ�����ʣ���λΪHz
	beta�����ջ�����
	return��beta���޺�ľ���������
	*/
	double static boc_brms(double fs, double fc, double beta);

	/*
	bpsk���ƴ��޺�ľ���������
	fc����Ƶ�����ʣ���λΪHz
	beta�����ջ�����
	return��beta���޺����Ч���δ���
	*/
	double static bpsk_brms(double fc, double beta);

	/*
	boc���ƴ��޺����Ч���δ���
	fs�����ز�Ƶ�ʣ���λΪHz
	fc����Ƶ�����ʣ���λΪHz
	beta�����ջ�����
	return��beta���޺����Ч���δ���
	*/
	double static boc_brect(double fs, double fc, double beta);
	
	/*
	bpsk���ƴ��޺����Ч���δ���
	fs�����ز�Ƶ�ʣ���λΪHz
	fc����Ƶ�����ʣ���λΪHz
	beta�����ջ�����
	return��beta���޺����Ч���δ���
	*/
	double static bpsk_brect(double fc, double beta);

	/*
	bocΪ�����ź�ʱ����boc���Ƶ�Ƶ�׸���ϵ��
	fs�������ź����ز�Ƶ��
	fc�������ź���Ƶ������
	beta�����մ���
	fs_a�������ź����ز�Ƶ��
	fc_a�������ź���Ƶ������
	betat�����������
	return��bocΪ�����ź�ʱ����boc���Ƶ�Ƶ�׸���ϵ��
	*/
	double static boc_boc_kls(double fs, double fc, double beta, double fs_a, double fc_a,double betat);

	/*
	bpskΪ�����ź�ʱ����boc���Ƶ�Ƶ�׸���ϵ��
	fs�������ź����ز�Ƶ��
	fc�������ź���Ƶ������
	beta�����մ���
	fc_a�������ź���Ƶ������
	betat�����������
	return��bpskΪ�����ź�ʱ����boc���Ƶ�Ƶ�׸���ϵ��
	*/
	double static boc_bpsk_kls(double fs, double fc, double beta, double fc_a, double betat);

	/*
	bocΪ�����ź�ʱ����bpsk���Ƶ�Ƶ�׸���ϵ��
	fc�������ź���Ƶ������
	beta�����մ���
	fs_a�������ź����ز�Ƶ��
	fc_a�������ź���Ƶ������
	betat�����������
	bocΪ�����ź�ʱ����bpsk���Ƶ�Ƶ�׸���ϵ��
	*/
	double static bpsk_boc_kls(double fc, double beta, double fs_a, double fc_a, double betat);
	
	/*
	pskcΪ�����ź�ʱ����bpsk���Ƶ�Ƶ�׸���ϵ��
	fc�������ź���Ƶ������
	beta�����մ���
	fc_a�������ź���Ƶ������
	betat�����������
	bpskΪ�����ź�ʱ����bpsk���Ƶ�Ƶ�׸���ϵ��
	*/
	double static bpsk_bpsk_kls(double fc, double beta, double fc_a, double betat);
	
	/*
	����boc��������غ���
	t�������ʱ�䣬��λΪs
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	return��tʱ��ʱ������غ���
	*/
	double static boc_autocorrelation(double t, double fs, double fc, double beta);
	
	/*
	����bpsk��������غ���
	t�������ʱ�䣬��λΪs
	fc����Ƶ������
	beta�����ջ�����
	return��tʱ��ʱ������غ���
	*/
	double static bpsk_autocorrelation(double t, double fc, double beta);
	
	/*
	����boc���ƹ�������������Ƶƫ
	fs��boc���ز�Ƶ��
	fc��boc��Ƶ������
	return��boc���ƹ�������������Ƶƫ
	*/
	double static boc_frequency_offset(double fs, double fc, double beta);
	
	/*
	����boc���Ƶ���������ܶ�
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	return��boc���Ƶ���������ܶ�
	*/
	double static boc_maxf(double fs, double fc, double beta);
	
	/*
	����bpsk���Ƶ���������ܶ�
	fc����Ƶ������
	beta�����ջ�����
	return��bpsk���Ƶ���������ܶ�
	*/
	double static bpsk_maxf(double fc, double beta);
	
	/*
	����boc90%���ʵĴ���
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	return��boc90%���ʵĴ���
	*/
	double static boc_beta_90(double fs, double fc, double beta);
	
	/*
	����bpsk90%���ʵĴ���
	fc����Ƶ������
	beta�����ջ�����
	return��bpsk90%���ʵĴ���
	*/
	double static bpsk_beta_90(double fc, double beta);
	
	/*
	����boc�Ĵ�����ʧ
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	return��boc�Ĵ�����ʧ
	*/
	double static boc_beta_loss(double fs, double fc, double beta);
	
	/*
	����bpsk�Ĵ�����ʧ
	fc����Ƶ������
	beta�����ջ�����
	return��bpsk�Ĵ�����ʧ
	*/
	double static bpsk_beta_loss(double fc, double beta);
	
	/*
	����boc����غ����������һ�����ʱ��
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	return��boc����غ����������һ�����ʱ��
	*/
	double static boc_autocorrelation_delay(double fs, double fc, double beta);

	/*
	����boc����غ����������һ����ķ���ƽ��֮��
	delay��boc����غ����������һ�����ʱ��
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	return��boc����غ����������һ����ķ���ƽ��֮��
	*/
	double static boc_autocorrelation_amplitude_ratio(double delay, double fs, double fc, double beta);
	
	/*
	��boc����-NELP����-���ͼ�Σ�Ĭ������ȹ̶�
	delta����ǰ�ͺ󱾵�����
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	tco����������ػ���ʱ��
	return������boc���ƶ�Ӧ����ĳ�ǰ�ͺ󱾵���������������
	*/
	double static boc_NELP_delta(double delta, double fs, double fc, double beta, double tco);
	
	/*
	��boc����-NELP����-�����ͼ�Σ���ǰ�ͺ󱾵�����������ȷ��
	delta����ǰ�ͺ󱾵�����
	cn�������
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	tco����������ػ���ʱ��
	return������boc���ƶ�Ӧ���������ȵ���������
	*/
	double static boc_NELP_CN0(double delta, double cn0, double fs, double fc, double beta,double tco);
	
	/*
	��bpsk����-NELP����-���ͼ�Σ�Ĭ������ȹ̶�
	delta����ǰ�ͺ󱾵�����
	fc����Ƶ������
	beta�����ջ�����
	tco����������ػ���ʱ��
	return������boc���ƶ�Ӧ����ĳ�ǰ�ͺ󱾵���������������
	*/
	double static bpsk_NELP_delta(double delta, double fc, double beta, double tco);
	
	/*
	��bpsk����-NELP����-�����ͼ�Σ���ǰ�ͺ󱾵�����������ȷ��
	delta����ǰ�ͺ󱾵�����
	cn�������
	fc����Ƶ������
	beta�����ջ�����
	tco����������ػ���ʱ��
	return������boc���ƶ�Ӧ���������ȵ���������
	*/
	double static bpsk_NELP_CN0(double delta, double cn0, double fc, double beta, double tco);
	
	/*
	��boc���ƶྶ������ͼ�Σ��ྶ�����ź������ֱ���źŵ���λΪ2�е�ż������
	t���ྶʱ��
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	delta����ǰ�ͺ󱾵�����
	*/
	double static boc_multipath_error_Pos(double t, double fs, double fc, double beta, double delta);
	
	/*
	��boc���ƶྶ������ͼ�Σ��ྶ�����ź������ֱ���źŵ���λΪ2�е���������
	t���ྶʱ��
	fs�����ز�Ƶ��
	fc����Ƶ������
	beta�����ջ�����
	delta����ǰ�ͺ󱾵�����
	*/
	double static boc_multipath_error_Neg(double t, double fs, double fc, double beta, double delta);

	/*
	��bpsk���ƶྶ������ͼ�Σ��ྶ�����ź������ֱ���źŵ���λΪ2�е�ż������
	t���ྶʱ��
	fc����Ƶ������
	beta�����ջ�����
	delta����ǰ�ͺ󱾵�����
	*/
	double static bpsk_multipath_error_Pos(double t, double fc, double beta, double delta);

	/*
	��bpsk���ƶྶ������ͼ�Σ��ྶ�����ź������ֱ���źŵ���λΪ2�е���������
	t���ྶʱ��
	fc����Ƶ������
	beta�����ջ�����
	delta����ǰ�ͺ󱾵�����
	*/
	double static bpsk_multipath_error_Neg(double t, double fc, double beta, double delta);
};