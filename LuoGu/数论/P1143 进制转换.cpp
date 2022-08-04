#include <iostream>
using namespace std;

// 模拟短除，要处理下字母 

void jz(int n, int k) {
	int res[100], index = 0;
	while(n) {
		res[index++] = n % k;
		n /= k;
	}
	for (int i = index - 1; i >= 0; i--) {
		cout << res[i];
	}
}
int str2int(string str) {
	int x = 0;
	
}
int main() {
	int n, m;
	int x;
	string str;
	cin >> n >> str >> m;
	
	jz(n, m);
	return 0;
}
