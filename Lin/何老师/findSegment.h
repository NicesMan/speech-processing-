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
	Segment(int n) {
		begin.set_size(1, n);
		end.set_size(1, n);
		duration.set_size(1, n);
	}
};

/*
matlab��Segment���飬����Ϊbegin��end��duration
�ҵ���Segment����������Ϊbegin����end����duration����
matlabҪȡsoundSegment(1).begin
������soundSegment.begin(1)
��Ϊmatһ��Ҫ�����ô�С�����������и�ѭ�����������Σ�ûд�ã����������ǶԵģ��±��0��ʼ
*/
Segment findSegment(mat express)
{
	int i, k;
	mat voicedIndex(1, express.n_cols);
	if (express(0) == 0) {
		k = 0;
		for (i = 0; i < express.n_cols; i++) {
			if (express(i) != 0)
				voicedIndex(k++) = i + 1;
		}
	}
	else
		voicedIndex = express;

	k = 1;
	for (i = 0; i <= voicedIndex.n_elem - 2; i++) {
		if (voicedIndex(i + 1) - voicedIndex(i) > 1) k++;
	}

	Segment soundSegment(k);
	k = 0;
	soundSegment.begin(0) = voicedIndex(0);
	for (i = 0; i <= voicedIndex.n_elem - 2; i++) {
		if (voicedIndex(i + 1) - voicedIndex(i) > 1) {
			soundSegment.end(k) = voicedIndex(i);
			soundSegment.begin(k + 1) = voicedIndex(i + 1);
			k++;
		}
	}

	soundSegment.end(k) = voicedIndex(voicedIndex.n_elem - 1);
	for (i = 0; i <= k; i++) {
		soundSegment.duration(i) = soundSegment.end(i) - soundSegment.begin(i);
	}
	return soundSegment;
}
#endif
#pragma once