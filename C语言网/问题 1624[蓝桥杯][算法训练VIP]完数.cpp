#include <iostream>
using namespace std;
int ans(int x) {
	int res = 0;
	// �����֪����Ϊʲô�����Գ���׹���� 
	for (int i = 1; i <= x / 2; i++) {
		if (!(x % i)) {
			res += i;
			//if (i != x / i && x != x / i) res += x / i;
		}
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	if (ans(n) == n) cout << "yes";
	else cout << "no";
	return 0;
}
