#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �²��ֱ��� 

struct element {
	float g, p, v;
	element(float g1 = 0, float p1 = 0, float v1 = 0) {
		g = g1, p = p1, v = v1;
	}
	bool operator<(const element& e) {
		return v > e.v;
	}
};
element *el;
int main() {
	int n, w;
	cin >> n >> w;
	el = new element[n];
	
	for (int i = 0; i < n; i++) {
		cin >> el[i].g >> el[i].p;
		// �����������ûʲô�����ˣ��Լ۱ȵĹ涨�Ǽ�ֵ/������������v=1,w=10�������������
		// v������ 
		el[i].v = el[i].p / el[i].g;
	}
	sort(el, el + n);
	float sumValue = 0;
	for (int i = 0; i < n; i++) {
		if (w - el[i].g >= 0) {
			sumValue += el[i].p;
			w -= el[i].g;
		} else {
			sumValue += el[i].v * w;
			break;
		}
	}
	printf("%.1f", sumValue);
	delete[] el;
	return 0;
}
