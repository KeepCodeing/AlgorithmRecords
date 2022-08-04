#include <iostream>
#include <algorithm>
#include <bitset> 
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	bitset<32> bt;
	int n;
	long long temp;
	long long res = 0;
	cin >> n;
	bt = n;
	for (int i = 0; i < 16; i++) temp = bt[i], bt[i] = bt[i + 16], bt[i + 16] = temp;
	cout << bt << endl;
	temp = 1;
	for (int i = 31; i >= 0; i--) {
		res += bt[i] * temp;
		cout << res << endl;
		temp *= 2;
	}
	cout << temp << endl;
	cout << res;
	return 0;
}
