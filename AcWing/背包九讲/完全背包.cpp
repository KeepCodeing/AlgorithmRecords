#include <iostream>
using namespace std;

// ��01�����Ļ�����������չ��ĳ����Ʒ��������ѡȡ���ڴ����ϵ�����ֻ�еڶ���ѭ���Ǵ�С����ö�� 

const int N = 1010;
int val[N], wei[N], f[N];
int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		for (int j = val[i]; j <= v; j++) {
			f[j] = max(f[j], f[j - val[i]] + wei[i]);
		}
	}
	cout << f[v];
	return 0;
}
