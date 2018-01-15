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
	matlab的Segment数组，属性为begin、end、duration
	我的是Segment变量，属性为begin矩阵、end矩阵、duration矩阵
	matlab要取soundSegment(1).begin
	这里是soundSegment.begin(1)
	因为mat一定要声明好大小，所以这里有个循环我做了两次，没写好，不过程序是对的，下标从0开始
*/
Segment findSegment(mat express);

#endif
#pragma once