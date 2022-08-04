#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	double ans = 0;
	while (n--) {
		string str;
		double dj;
		int sl;
		cin >> str >> dj >> sl;
		ans += dj * sl;
	}
	printf("%.6lf", ans);
	return 0;
}
