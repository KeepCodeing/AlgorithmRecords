#include <iostream>
using namespace std;
const int N = 1010;
int val[N], wei[N], f[N];

// 01��������̸�������þ�֮ǰд���ܶ�01�������⣬����ȴ���ò���� 

int main() {
	int n, v;
	cin >> n >> v;
	int vi, wi;
	// ������val��ʾ���ۣ���Ǯ����wei��ʾ�ջ�Ȩ�أ� 
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= val[i]; j--) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[v];
	return 0;
} 
