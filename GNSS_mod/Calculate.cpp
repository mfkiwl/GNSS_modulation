#include "Calculate.h"


//���ִ���
#define Integral_Times 2048
//д������

//boc�Ĺ������ܶ�G(f)
double Calculate::boc_f(double f, double fs, double fc) {
	double G_f;
	if (f == 0)return 0;
	int n = (int)(2 * fs / fc);
	if (n % 2 == 0) {//nΪż��
		G_f = fc*pow(tan(PI*f / 2 / fs)*sin(PI*f / fc) / PI / f, 2);
	}
	else {//nΪ����
		G_f = fc*pow(tan(PI*f / 2 / fs)*cos(PI*f / fc) / PI / f, 2);
	}
	return G_f;
}

//bpsk�Ĺ������ܶ�G(f)
double Calculate::bpsk_f(double f, double fc) {
	double G_f;
	if (f == 0)return 0;
	G_f = 1 / fc*pow(sin(PI*f / fc) / PI / f*fc, 2);
	return G_f;
}

//����boc�Ħ�
double Calculate::boc_lamda(double fs, double fc, double beta) {
	double lamda = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		lamda += Calculate::boc_f(f, fs, fc);
	}
	return lamda*interval;
}

//����bpsk�Ħ�
double Calculate::bpsk_lamda(double fc, double beta) {
	double lamda = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		lamda += Calculate::bpsk_f(f, fc);
	}
	return lamda*interval;
}

//����boc�ľ���������
double Calculate::boc_brms(double fs, double fc, double beta) {
	double lamda = Calculate::boc_lamda(fs, fc, beta);
	double brms = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		brms += f*f*Calculate::boc_f(f, fs, fc)/lamda;
	}
	return sqrt(brms*interval)/1000000;
}

//����bpsk�ľ���������
double Calculate::bpsk_brms(double fc, double beta) {
	double lamda = Calculate::bpsk_lamda(fc, beta);
	double brms = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		brms += f*f*Calculate::bpsk_f(f, fc) / lamda;
	}
	return sqrt(brms*interval)/1000000;
}

//����boc��Ч���δ���
double Calculate::boc_brect(double fs, double fc, double beta) {
	double lamda = Calculate::boc_lamda(fs, fc, beta);
	double brect = 0;
	double f;
	int i;
	double G_f_max = 0;
	double interval = beta / Integral_Times;
	//���������ֵ
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f_max = Calculate::boc_f(f, fs, fc) > G_f_max ? Calculate::boc_f(f, fs, fc) : G_f_max;
	}
	return lamda / G_f_max/1000000;
}

//����bpsk��Ч���δ���
double Calculate::bpsk_brect(double fc, double beta) {
	double lamda = Calculate::bpsk_lamda(fc, beta);
	double brect = 0;
	double f;
	int i;
	double G_f_max = 0;
	double interval = beta / Integral_Times;
	//���������ֵ
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f_max = Calculate::bpsk_f(f, fc) > G_f_max ? Calculate::bpsk_f(f, fc) : G_f_max;
	}
	return lamda / G_f_max/1000000;
}

//����boc��boc�ĸ���
double Calculate::boc_boc_kls(double fs, double fc, double beta, double fs_a, double fc_a, double betat) {
	double lamda = Calculate::boc_lamda(fs_a, fc_a, beta);
	double kls = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		if (f <= betat / 2 && f >= -betat / 2) {
			kls += Calculate::boc_f(f, fs, fc)*Calculate::boc_f(f, fs_a, fc_a) / lamda;
		}
	}
	return 10*log10(kls*interval);
}

//����bpsk��boc�ĸ���
double Calculate::boc_bpsk_kls(double fs, double fc, double beta, double fc_a, double betat) {
	double lamda = Calculate::bpsk_lamda(fc_a, beta);
	double kls = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		if (f <= betat / 2 && f >= -betat / 2) {
			kls += Calculate::boc_f(f, fs, fc)*Calculate::bpsk_f(f, fc_a) / lamda;
		}
	}
	return 10 * log10(kls*interval);
}

//����boc��bpsk�ĸ���
double Calculate::bpsk_boc_kls(double fc, double beta, double fs_a, double fc_a, double betat) {
	double lamda = Calculate::boc_lamda(fs_a, fc_a, beta);
	double kls = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		if (f <= betat / 2 && f >= -betat / 2) {
			kls += Calculate::bpsk_f(f, fc)*Calculate::boc_f(f, fs_a, fc_a) / lamda;
		}
	}
	return 10 * log10(kls*interval);
}

//����bpsk��bpsk�ĸ���
double Calculate::bpsk_bpsk_kls(double fc, double beta, double fc_a, double betat) {
	double lamda = Calculate::bpsk_lamda(fc_a, beta);
	double kls = 0;
	double f;
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		if (f <= betat / 2 && f >= -betat / 2) {
			kls += Calculate::bpsk_f(f, fc)*Calculate::bpsk_f(f, fc_a) / lamda;
		}
	}
	return 10 * log10(kls*interval);
}

//����boc�Ĺ�һ������غ���
double Calculate::boc_autocorrelation(double t, double fs, double fc, double beta) {
	double real = 0;
	double image = 0;
	double f;
	double lamda = boc_lamda(fs, fc, beta);
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		real += cos(2 * PI*t*f)*Calculate::boc_f(f, fs, fc);
		image += sin(2 * PI*t*f)*Calculate::boc_f(f, fs, fc);
	}
	real *= interval;
	image *= interval;
	return sqrt(real*real + image*image) / lamda;
}

//����bpsk�Ĺ�һ������غ���
double Calculate::bpsk_autocorrelation(double t, double fc, double beta) {
	double real = 0;
	double image = 0;
	double f;
	double lamda = bpsk_lamda(fc, beta);
	int i;
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		real += cos(2 * PI*t*f)*Calculate::bpsk_f(f, fc);
		image += sin(2 * PI*t*f)*Calculate::bpsk_f(f, fc);
	}
	real *= interval;
	image *= interval;
	return sqrt(real*real + image*image) / lamda;
}

//��������Ƶƫ
double Calculate::boc_frequency_offset(double fs, double fc, double beta) {
	double max = 0;
	double f = 0;
	double offset = 0;
	double G_f;
	for (f = 0; f < beta / 2;f+=1000) {
		G_f = boc_f(f, fs, fc);
		max = max > G_f ? max : G_f;
		offset = max > G_f ? offset : f;
	}
	return offset / 1000000;
}

//����boc��������ܶ�
double Calculate::boc_maxf(double fs, double fc, double beta) {
	double max = 0;
	double f = 0;
	double G_f;
	for (f = 0; f < beta / 2; f += 1000) {
		G_f = boc_f(f, fs, fc);
		max = max > G_f ? max : G_f;
	}
	return 10 * log10(max);
}

//����bpsk��������ܶ�
double Calculate::bpsk_maxf(double fc, double beta) {
	double max = 0;
	double f = 0;
	double G_f;
	for (f = 0; f < beta / 2; f += 1000) {
		G_f = bpsk_f(f, fc);
		max = max > G_f ? max : G_f;
	}
	return 10 * log10(max);
}

//����boc90%���ʵĴ���
double Calculate::boc_beta_90(double fs, double fc, double beta) {
	double lamda = boc_lamda(fs,fc,beta);
	double lamda_f;
	double f;
	double beta_90 = 0;
	for (f = 0; f < beta / 2; f += 10000) {
		lamda_f = boc_lamda(fs, fc, f * 2);
		if (lamda_f >= 0.9*lamda) {
			return 2 * f / 1000000;
		}
	}
	return 2 * f / 1000000;
}

//����bpsk90%���ʵĴ���
double Calculate::bpsk_beta_90(double fc, double beta) {
	double lamda = bpsk_lamda(fc, beta);
	double lamda_f;
	double f;
	double beta_90 = 0;
	for (f = 0; f < beta / 2; f += 10000) {
		lamda_f = bpsk_lamda(fc, f * 2);
		if (lamda_f >= 0.9*lamda) {
			return 2 * f / 1000000;
		}
	}
	return 2 * f / 1000000;
}

//����boc������ʧ
double Calculate::boc_beta_loss(double fs, double fc, double beta) {
	double lamda = boc_lamda(fs, fc, beta);
	double lamda_2 = boc_lamda(fs, fc, 30*1000000);
	return 10 * log10(lamda_2 / lamda);
}

//����bpsk������ʧ
double Calculate::bpsk_beta_loss(double fc, double beta) {
	double lamda = bpsk_lamda(fc, beta);
	double lamda_2 = bpsk_lamda(fc, 30 * 1000000);
	return 10 * log10(lamda_2 / lamda);
}

//����boc����غ����������һ�����ʱ��
double Calculate::boc_autocorrelation_delay(double fs, double fc, double beta) {
	double interval = 0.000001 / Integral_Times;
	double t = interval;
	while (t < 0.000001) {
		if (boc_autocorrelation(t - interval, fs, fc, beta) <= boc_autocorrelation(t, fs, fc, beta) && boc_autocorrelation(t, fs, fc, beta) >= boc_autocorrelation(t + interval, fs, fc, beta)) {
			return t * 1000000000;
		}
		t += interval;
	}
	return 0;
}

//����boc����غ�����һ����������ķ���ƽ��֮��
double Calculate::boc_autocorrelation_amplitude_ratio(double delay, double fs, double fc, double beta) {
	delay *= 0.000000001;
	return pow(boc_autocorrelation(delay, fs, fc, beta), 2);
}

//����bocNELP����-���ͼ��
double Calculate::boc_NELP_delta(double delta, double fs, double fc, double beta, double tco) {
	double NELP = 0;
	double index_1 = 0;
	double index_2 = 0;
	double index_3 = 0;
	double index_4 = 0;
	double cn0 = 30;
	double G_f = 0;
	double f;
	int i;
	cn0 = pow(10, cn0 / 10);
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::boc_f(f, fs, fc);
		index_1 += G_f*pow(sin(PI*f*delta), 2);
		index_2 += G_f*f*sin(PI*f*delta);
		index_3 += G_f*pow(cos(PI*f*delta), 2);
		index_4 += G_f*cos(PI*f*delta);
	}
	index_1 *= interval;
	index_2 *= interval;
	index_3 *= interval;
	index_4 *= interval;
	NELP = (1 - 0.25*tco)*index_1 / cn0 / pow(2 * PI*index_2, 2)*(1 + index_3 / (tco*cn0*pow(index_4, 2)));
	return sqrt(NELP) * 3 * pow(10, 8);
}

//����bocNELP����-�����ͼ��
double Calculate::boc_NELP_CN0(double delta, double cn0, double fs, double fc, double beta, double tco) {
	double NELP = 0;
	double index_1 = 0;
	double index_2 = 0;
	double index_3 = 0;
	double index_4 = 0;
	double G_f = 0;
	double f;
	int i;
	cn0 = pow(10, cn0 / 10);
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::boc_f(f, fs, fc);
		index_1 += G_f*pow(sin(PI*f*delta), 2);
		index_2 += G_f*f*sin(PI*f*delta);
		index_3 += G_f*pow(cos(PI*f*delta), 2);
		index_4 += G_f*cos(PI*f*delta);
	}
	index_1 *= interval;
	index_2 *= interval;
	index_3 *= interval;
	index_4 *= interval;
	NELP = 0.1*(1 - 0.25*tco*0.1)*index_1 / cn0 / pow(2 * PI*index_2, 2)*(1 + index_3 / (tco*cn0*pow(index_4, 2)));
	return sqrt(NELP) * 3 * pow(10, 8);
}

//����bpskNELP����-���ͼ��
double Calculate::bpsk_NELP_delta(double delta, double fc, double beta, double tco) {
	double NELP = 0;
	double index_1 = 0;
	double index_2 = 0;
	double index_3 = 0;
	double index_4 = 0;
	double cn0 = 30;
	double G_f = 0;
	double f;
	int i;
	cn0 = pow(10, cn0 / 10);
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::bpsk_f(f, fc);
		index_1 += G_f*pow(sin(PI*f*delta), 2);
		index_2 += G_f*f*sin(PI*f*delta);
		index_3 += G_f*pow(cos(PI*f*delta), 2);
		index_4 += G_f*cos(PI*f*delta);
	}
	index_1 *= interval;
	index_2 *= interval;
	index_3 *= interval;
	index_4 *= interval;
	NELP = (1 - 0.25*tco)*index_1 / cn0 / pow(2 * PI*index_2, 2)*(1 + index_3 / (tco*cn0*pow(index_4, 2)));
	return sqrt(NELP) * 3 * pow(10, 8);
}

//����bpskNELP����-�����ͼ��
double Calculate::bpsk_NELP_CN0(double delta, double cn0, double fc, double beta, double tco) {
	double NELP = 0;
	double index_1 = 0;
	double index_2 = 0;
	double index_3 = 0;
	double index_4 = 0;
	double G_f = 0;
	double f;
	int i;
	cn0 = pow(10, cn0 / 10);
	double interval = beta / Integral_Times;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::bpsk_f(f, fc);
		index_1 += G_f*pow(sin(PI*f*delta), 2);
		index_2 += G_f*f*sin(PI*f*delta);
		index_3 += G_f*pow(cos(PI*f*delta), 2);
		index_4 += G_f*cos(PI*f*delta);
	}
	index_1 *= interval;
	index_2 *= interval;
	index_3 *= interval;
	index_4 *= interval;
	NELP = 0.1*(1 - 0.1*0.25*tco)*index_1 / cn0 / pow(2 * PI*index_2, 2)*(1 + index_3 / (tco*cn0*pow(index_4, 2)));
	return sqrt(NELP) * 3 * pow(10, 8);
}

//boc�ྶ����ϰ���
double Calculate::boc_multipath_error_Pos(double t, double fs, double fc, double beta, double delta) {
	double alpha = pow(10, -0.6);
	int i = 0;
	double f;
	double G_f;
	double interval = beta / Integral_Times;
	double index_1 = 0;
	double index_2 = 0;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::boc_f(f, fs, fc);
		index_1 += G_f * sin(PI*f*delta) * sin(2 * PI*f*t);
		index_2 += G_f * f * sin(PI*f*delta) * (1 + alpha * cos(2 * PI*f*t));
	}
	index_1 *= interval;
	index_2 *= interval;
	return alpha * index_1 / 2 / PI / index_2 * 3 *pow(10,8) / 0.03;
}

//boc�ྶ����°���
double Calculate::boc_multipath_error_Neg(double t, double fs, double fc, double beta, double delta) {
	double alpha = pow(10, -0.6);
	int i = 0;
	double f;
	double G_f;
	double interval = beta / Integral_Times;
	double index_1 = 0;
	double index_2 = 0;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::boc_f(f, fs, fc);
		index_1 += G_f * sin(PI*f*delta) * sin(2 * PI*f*t);
		index_2 += G_f * f * sin(PI*f*delta) * (1 - alpha * cos(2 * PI*f*t));
	}
	index_1 *= interval;
	index_2 *= interval;
	return (-alpha) * index_1 / 2 / PI / index_2 * 3 * pow(10, 8) / 0.03;
}

//bpsk�ྶ����ϰ���
double Calculate::bpsk_multipath_error_Pos(double t, double fc, double beta, double delta) {
	double alpha = pow(10, -0.6);
	int i = 0;
	double f;
	double G_f;
	double interval = beta / Integral_Times;
	double index_1 = 0;
	double index_2 = 0;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::bpsk_f(f, fc);
		index_1 += G_f * sin(PI*f*delta) * sin(2 * PI*f*t);
		index_2 += G_f * f * sin(PI*f*delta) * (1 + alpha * cos(2 * PI*f*t));
	}
	index_1 *= interval;
	index_2 *= interval;
	return alpha * index_1 / 2 / PI / index_2 * 3 * pow(10, 8) / 0.03;
}

//bpsk�ྶ����°���
double Calculate::bpsk_multipath_error_Neg(double t, double fc, double beta, double delta) {
	double alpha = pow(10, -0.6);
	int i = 0;
	double f;
	double G_f;
	double interval = beta / Integral_Times;
	double index_1 = 0;
	double index_2 = 0;
	for (i = 0; i < Integral_Times; i++) {
		f = -beta / 2 + interval / 2 + interval*i;
		G_f = Calculate::bpsk_f(f, fc);
		index_1 += G_f * sin(PI*f*delta) * sin(2 * PI*f*t);
		index_2 += G_f * f * sin(PI*f*delta) * (1 - alpha * cos(2 * PI*f*t));
	}
	index_1 *= interval;
	index_2 *= interval;
	return (-alpha) * index_1 / 2 / PI / index_2 * 3 * pow(10, 8) / 0.03;
}