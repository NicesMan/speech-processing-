#pragma once
#ifndef _BA_findSegment_H_
#define _BA_findSegment_H_

#include<armadillo>
using namespace arma;

class Segment {
public:
	mat begin;
	mat end;
	mat duration;
	Segment(int n);
	void setSize(int n);
};

/*
	matlab��Segment���飬����Ϊbegin��end��duration
	�ҵ���Segment����������Ϊbegin����end����duration����
	matlabҪȡsoundSegment(1).begin
	������soundSegment.begin(1)
	��Ϊmatһ��Ҫ�����ô�С�����������и�ѭ�����������Σ�ûд�ã����������ǶԵģ��±��0��ʼ
*/
Segment findSegment(mat express);

#endif
#pragma once