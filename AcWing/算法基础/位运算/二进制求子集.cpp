#include <iostream>
#include <bitset>
#define endl '\n'
const int N = 5e4 + 10;
using namespace std;

// 思路：设一个集合{A, B, C}, 用0~(2^n)-1的二进制数表示选或不选（n为集合大小），即可生成它的全部子集 

char c_set[N];
int quick_power(int n, int k) {
	int res = 1;
	while (k) {
		if (k & 1) res *= n;
		k >>= 1, n *= n;
	}
	return res;
}
int main () {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int n;
	cin >> n;
	bitset<8 > bt;
	for (int i = 0; i < n; i++) cin >> c_set[i];
	for (int i = 0; i < quick_power(2, n); i++) {
		bt = i;
		for (int j = 0; j < n; j++) {
			if (bt[j]) cout << c_set[j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
