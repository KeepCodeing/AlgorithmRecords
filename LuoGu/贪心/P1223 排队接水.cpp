#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 看起来就是把耗时久的人排到后面去，第i个人等的时间应该为i+sum(i-1) 
struct person {
	int id, t;
	bool operator<(const person& s) {
		return t < s.t;
	}
	person(int i = 0, int t = 0) {
		id = i, t = t;
	}
};
person *tt;
int main() {
	int n;
	double r = .0;
	cin >> n;
	tt = new person[n];
	for (int i = 0; i < n; i++) {
		cin >> tt[i].t;
		tt[i].id = i + 1;
	}
	sort(tt, tt + n);
	for (int i = 0; i < n; i++) {
		cout << tt[i].id;
		if (i != n - 1) cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		// 计算公式 
		r += tt[i].t * (n - i - 1);
	}
	printf("%.2lf",  r / n);
	delete[] tt;
	return 0;
}
