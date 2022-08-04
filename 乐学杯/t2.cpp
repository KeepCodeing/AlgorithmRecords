#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string str = "LANQIAO";
	int sLen = str.size();
	int res = 0;
	for (int i = 0; i < sLen; i++) {
		for (int j = i + 1; j < sLen; j++) {
			res += abs(str[i] - str[j]);
		}
	}
	cout << res;
	return 0;
}
