#include <iostream>
#define endl '\n'
using namespace std;
const int N = 60;
typedef long long LL;

// ��������Ķ��彫ԭ���ķ�ʽչ���ɡ��ȳ˺��������ʽ������n = 62, m = 31ʱ��� 

// ��������C(n, m)�����Ӷ�O(m) 
LL cal(int n, int m) {
	LL ans = 1;
	for (int i = 1; i <= m; i++) {
		ans = ans * (n - m + i) / i;
	}
	return ans;
}

// ���ַ�������ֱ�������������������Ӷ�O(n^2) ���ƺ���ˣ� 
LL res[N][N];
LL cal2(int n, int m) {
	if (m == 0 || m == n) return 1;
	if (res[n][m] != 0) return res[n][m];
	return res[n][m] = cal2(n - 1, m) + cal2(n - 1, m - 1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	return 0;
}
