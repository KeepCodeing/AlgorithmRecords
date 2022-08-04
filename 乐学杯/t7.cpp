#include <iostream>
#define endl '\n'
using namespace std;

int mn[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isRun(int y) {
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int y, m, x, res;
	int t = 0;
	while (cin >> y >> m >> x) {
		
		mn[2] = 28;
		res = 0;
		
		if (isRun(y)) mn[2]++;
		
		if (y / 1000 == x) res++;
		if (y / 100 % 10 == x) res++;
		if (y / 10 % 10 == x) res++;
		if (y % 10 == x) res++;
		if (m / 10 == x) res++;
		if (m % 10 == x) res++;
		
		res *= mn[m];
		
		for (int i = 1; i <= mn[m]; i++) {
			
			
			if (i / 10 == x) res++;
			if (i % 10 == x) res++;
		}
		cout << res << endl;
	}
	return 0;
}
