#include "stdafx.h"
#include "complex.h"


Complex::Complex()
{
	this->RealPart = 0.0;
	this->ImaginaryPart = 0.0;
}

Complex::Complex(double rep, double imp)
{
	this->RealPart = rep;
	this->ImaginaryPart = imp;
}

// ֱ������
void Complex::Update(double ReP, double ImP)
{
	this->RealPart = ReP;
	this->ImaginaryPart = ImP;
}

// ȡʵ��
double Complex::Re(void)
{
	return this->RealPart;
}

//ȡ�鲿
double Complex::Im(void)
{
	return this->ImaginaryPart;
}

//ȡģ��ƽ��
double Complex::AbsSqr(void)
{
	return (this->RealPart * this->RealPart + this->ImaginaryPart * this->ImaginaryPart);
}

//ȡģ
double Complex::Abs(void)
{
	return sqrt(this->RealPart * this->RealPart + this->ImaginaryPart * this->ImaginaryPart);
}

// �����ӷ�
Complex Complex::operator+(Complex c)
{
	return Complex(this->RealPart + c.Re(), this->ImaginaryPart + c.Im());
}

// ��������
Complex Complex::operator-(Complex c)
{
	return Complex(this->RealPart - c.Re(), this->ImaginaryPart - c.Im());
}

// �����˷�
Complex Complex::operator*(Complex c)
{
	double rep = this->RealPart * c.Re() - this->ImaginaryPart * c.Im();
	double imp = this->RealPart * c.Im() + c.Re() * this->ImaginaryPart;
	return Complex(rep, imp);
}

// ���ظ�ֵ�����
void Complex::operator=(Complex rv)
{
	this->RealPart = rv.Re();
	this->ImaginaryPart = rv.Im();
}

Complex* mat2com(mat a) {
	int alen = a.n_cols;
	Complex* c = new Complex[alen];
	for (int i = 0; i < alen; i++)
		c[i].Update(a(0, i), a(1, i));
	return c;
}

mat com2mat(Complex* c, int num) {
	mat a(2, num);
	for (int i = 0; i < num; i++) {
		a(0, i) = c[i].Re();
		a(1, i) = c[i].Im();
	}
	return a;
}