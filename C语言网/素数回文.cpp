#include <iostream>
using namespace std;
bool isprimes(int n) {
	for (int i = 2; i <= n / i; i++) {
		if (!(n % i)) return false; 
	}
	return true;
}
bool ishuiwen(int n) {
	string str;
	while (n) {
		str += (n % 10) + '0';
		n /= 10;
	}	
	int l = 0, r = str.size() - 1;
	while (l < r) {
		if (str[l++] != str[r--]) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (isprimes(i) && ishuiwen(i)) cout << i << endl;
	}
	return 0;
} 
