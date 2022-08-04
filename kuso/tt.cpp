#include <iostream>
#include <cstdio>
#define endl '\n'
using namespace std;

int dtable[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dat[10];

bool isHuiwen() {
	int l = 1, r = 8;
	while (l < r) if (dat[l++] != dat[r--]) return false;
	return true;
}

bool isAB() {
	return dat[1] == dat[3] && dat[1] == dat[6] && dat[1] == dat[8]
	       && dat[2] == dat[4] && dat[2] == dat[5] && dat[2] == dat[7];
}

void splitDate(int y, int m, int d) {
	for (int i = 4; i >= 1; i--) dat[i] = y % 10, y /= 10;
	dat[5] = m / 10, dat[6] = m % 10;
	dat[7] = d / 10, dat[8] = d % 10;
}

int main() {
	int year, month, day;
	bool f1 = false, f2 = false;

	scanf("%4d%2d%2d", &year, &month, &day);
	day++;

	for (int y = year; ; y++) {
		if ((y % 4 && y % 100 != 0) || (y % 400 == 0)) dtable[2] = 29;
		for (int m = month; m <= 12 ; m++) {
			for (int d = day; d <= dtable[m] ; d++) {
//				cout << y << ' ' << m << ' ' << d << endl;
				splitDate(y, m, d);
				if (!f1 && isHuiwen()) {
					f1 = true;
					for (int i = 1; i <= 8; i++) cout << dat[i];
					cout << endl;
				}
				if (!f2 && isAB()) {
					f2 = true;
					for (int i = 1; i <= 8; i++) cout << dat[i];
					cout << endl;
				}
				if (f1 && f2) return 0;
			}
			// 重置当前天数
			day = 1;
		}
		// 新一年重置闰年，当前天数，当前月数
		dtable[2] = 28;
		day = month = 1;
	}
	return 0;
}
