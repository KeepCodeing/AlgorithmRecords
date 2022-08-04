#include <iostream>
#include <cmath>
using namespace std;

// Ñ­»·¾ÍÐÐ

struct stu {
	int c, s, y, tot;
	stu(int c1 = 0, int s1 = 0, int y1 = 0, int t = 0) {
		c = c1, s = s1, y = y1, tot = t;
	}
}; 
stu *st;
int main() {
	int n, cnt = 0;
	cin >> n;
	st = new stu[n];
	for (int i = 0; i < n; i++) {
		cin >> st[i].c >> st[i].s  >> st[i].y;
		st[i].tot = st[i].c + st[i].s + st[i].y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(st[i].c - st[j].c) <= 5 && abs(st[i].s - st[j].s) <= 5 && abs(st[i].y - st[j].y) <= 5 && abs(st[i].tot - st[j].tot) <= 10) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
