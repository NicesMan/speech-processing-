#pragma once
#ifndef _BA_COMPLEX_H_
#define _BA_COMPLEX_H_

#include <cmath>
#include <armadillo>
using namespace arma;

class Complex
{

private:

	// ʵ�����鲿
	double RealPart;
	double ImaginaryPart;

public:

	// Ĭ�Ϲ��캯��
	Complex();

	// ���캯��
	Complex(double rep, double imp);

	// ֱ������
	void Update(double ReP, double ImP);

	// ȡʵ��
	double Re(void);

	//ȡ�鲿
	double Im(void);

	//ȡģ��ƽ��
	double AbsSqr(void);

	//ȡģ
	double Abs(void);

	// �����ӷ�
	Complex operator+(Complex c);

	// ��������
	Complex operator-(Complex c);

	// �����˷�
	Complex operator*(Complex c);

	// ���ظ�ֵ�����
	void operator=(Complex rv);
};

Complex* mat2com(mat a);

mat com2mat(Complex* c, int num);


#endif
#pragma once
