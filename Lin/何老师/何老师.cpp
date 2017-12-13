// ����ʦ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//http://blog.csdn.net/sandeepin/article/details/60866222

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<time.h>
#include<armadillo>
#include "pitch_Ceps.h"
#include "hamming.h"
#include "audioRead.h"
#include "linsomoothm.h"
#include "FrameTimeC.h"
using namespace std;
using namespace arma;

int main()
{
	int i, k, j;
	double inc = 128, T1 = 0.05;
	mat wlen(1, 1);
	wlen(0) = 256;
	audioread("F:\\matlab����\\����ʦ_����\\��Ƶ\\tone.wav");
	x = x - mean(x);
	mat x1 = x;
	for (i = 0; i < x1.n_elem; i++)
		x1(i) = fabs(x(i));
	mat a = max(x1);
	x = x / a(0);
	pitch_Ceps(x, wlen, inc, T1, fs, -1);

	mat F0 = fs / period;
	
	for (i = 0; i < SF.n_elem; i++)
		if (SF(i) == 0)
			F0(i) = 0;
	for (i = 0; i < F0.n_elem; i++)
		if (F0(i) > 500)
			F0(i) = 500;
	
	F0 = linsomoothm(F0, 3);
	int fn = F0.n_elem;
	mat tim(1, x.n_elem);
	for (i = 0; i < x.n_elem; i++)
		tim(i) = i / fs;
	mat frameTime = FrameTimeC(fn, wlen(0), inc, fs);
	cout << F0 << endl;

	/*double a;
	mat x(27200, 1);
	int k = 0;
	freopen("C:\\Users\\��ؼ\\Desktop\\616����ʦ\\x����.txt", "r", stdin);
	while ((scanf("%lf", &a)) != EOF)
	{
		x(k++) = a;
	}
	mat b(1, 1);
	b(0) = 256;
	pitch_Ceps(x, b, 128, 0.05, 8000, -1);*/

	/*mat express(1, 68);
	for (int i = 0; i < 50; i++) {
		express(i) = i + 1;
	}
	for (int i = 50; i < 59; i++) {
		express(i) = i + 2;
	}
	for (int i = 59; i < 68; i++) {
		express(i) = i + 3;
	}
	Segment a = findSegment(express);

	cout << a.begin << endl;
	cout << a.end << endl;
	cout << a.duration << endl;*/

	//1���������A��B
	/*mat A(2, 2), B(2, 2);
	for (int i = 0; i < 4; i++)
	{
		A(i) = i + 1;//i������Ϊ����˳�򣬾���ĵ�i��Ԫ��
		B(i) = i + 5;
	}
	A.print("����AΪ��");
	B.print("����BΪ��");
	//2������A�����B���
	mat AAddB = A + B;
	AAddB.print("A + B =");
	//3������A�����B���
	mat AMinusB = A - B;
	AMinusB.print("A - B =");
	//4������A�����B���
	//mat AMulB = A * B;
	//AMulB.print("A * B =");
	//5������A�����B���
	mat ADiviB = A / B;
	ADiviB.print("A / B =");
	//6������A�����B���
	mat ADotMulB = A % B;
	ADotMulB.print("A % B =");

	B.col(1) = A.col(1) * 2;
	cout << endl << B << endl;

	B.reshape(1, 2);
	cout << B << endl;


	//cout << repmat(B, 5, 1) << endl;

	mat c;
	c << 0.165300 << 0.454037 << 0.995795 << 0.124098 << 0.047084 << endr
		<< 0.688782 << 0.036549 << 0.552848 << 0.937664 << 0.866401 << endr
		<< 0.348740 << 0.479388 << 0.506228 << 0.145673 << 0.491547 << endr
		<< 0.148678 << 0.682258 << 0.571154 << 0.874724 << 0.444632 << endr
		<< 0.245726 << 0.595218 << 0.409327 << 0.367827 << 0.385736 << endr;
	cout << c << endl;

	mat x;
	x << 5 << endr
		<< 6 << endr
		<< 14 << endr
		<< 11 << endr
		<< 15 << endr
		<< 9 << endr
		<< 7 << endr
		<< 13 << endr
		<< 18 << endr
		<< 17 << endr
		<< 4 << endr
		<< 20 << endr
		<< 16 << endr
		<< 1 << endr
		<< 10 << endr
		<< 19 << endr
		<< 8 << endr
		<< 2 << endr
		<< 12 << endr
		<< 3 << endr;


	mat win;
	win << 10 << endr;
	int inc = 6;
	cout << enframe(x, win, inc);*/

	//cout << FrameTimeC(211, 256, 128, 8000) << endl;

	

	return 0;
}

