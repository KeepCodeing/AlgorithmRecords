#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 事部分背包 

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
		// 除了这里基本没什么问题了，性价比的规定是价值/重量，试想下v=1,w=10的情况，所以是
		// v做分子 
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
