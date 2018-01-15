#ifndef _BA_FFT_H_
#define _BA_FFT_H_
#include "Complex.h"
#include <cmath>

// �������㣨��2Ϊ�ף�
int LOG(int n);

// ��ת���ӵ�����
void GenerateRotationFactor(int size);

// �������鸴��
void ArrayCopy(Complex dest[], Complex src[], int size);

// ��λ����
void BitReverse(int inIndex[], int indexSize);

// ���ٸ���Ҷ�任
void FFT(Complex IN[], Complex OUT[], int Size);

mat FFT(mat m);

#endif
#pragma once
