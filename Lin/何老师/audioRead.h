#ifndef _BA_audioRead_H_
#define _BA_audioRead_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include<stdlib.h>
#include <bitset>
#include <iomanip>
#include<armadillo>
#include<vector>
using namespace std;
using namespace arma;

//Ҫ��int main()��ǰ����Ϻ�������������Ϊ��ĺ���д��main�����ĺ���
int hex_char_value(char ss);
int hex_to_decimal(const char* s);
//string hex_to_binary(char* szHex);

extern double fs;
extern mat x;

struct wav_struct
{
	unsigned long file_size;        //�ļ���С
	unsigned short channel;            //ͨ����
	unsigned long frequency;        //����Ƶ��
	unsigned long Bps;                //Byte��
	unsigned short sample_num_bit;    //һ��������λ��
	unsigned long data_size;        //���ݴ�С
	unsigned char *data;            //��Ƶ���� ,����Ҫ����ʲô�Ϳ�����λ���ˣ�������ֻ�ǵ����ĸ�������
};

void audioread(string path);

#endif
#pragma once
