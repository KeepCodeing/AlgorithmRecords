#include <iostream>
using namespace std;

// һ��ǰ׺�ͣ���������Ҫ�ж������Ͳ��ܽ����ۼ� 

const int N = 1e5 + 10;
int a[N], b[N], c[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	int x;
	a[0] = b[0] = c[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = a[i - 1], b[i] = b[i - 1], c[i] = c[i - 1];
		if (x == 1) a[i] += 1;
		else if (x == 2) b[i] += 1;
		else c[i] += 1;
	} 
	int l, r;
	while (q--) {
		cin >> l >> r;
		// ע��lҪ-1����Ϊ��һ��ǰ׺�͵��±��Ǵ�0��ʼ�� 
		l -= 1;
		// ǰ׺�� 
		cout << a[r] - a[l] << ' ' << b[r] - b[l] << ' ' << c[r] - c[l] << endl;
	}
	return 0;
}
