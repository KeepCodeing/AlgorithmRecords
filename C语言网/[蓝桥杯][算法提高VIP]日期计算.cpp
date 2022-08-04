#include <iostream>
#include <cmath>
using namespace std;

// 思路：先把日期换算成天数，然后慢慢加/减... 

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int yd = 0;
int main() {
	while (true) {
		int year, month, day;
		cin >> year >> month >> day;
		for (int i = 0; i < abs(2011 - year); i++) {
			yd += 365;
			if (((2011 + i) % 4 == 0 && (2011 + i) % 100 != 0) || (2011 + i) % 400 == 0) yd += 1;	
		}
		cout << yd <<endl;
//		int nd = (year - 2011) * yd + (month - 12) * 12 + (day - 11);
//		nd = nd < 0 ? -nd : nd;
//		cout << nd << endl;
//		int res = 5;
//		for (int i = 1; i <= nd; i++) {
//			res++;
//			if (res % 8 == 0) res = 1;
//		}
//		cout << res;
	}
	
	return 0;
}
