#include <iostream>
using namespace std;

// ����û������������ʵ���Ǹ����01�����󷽰��� 
// �Ѽ���Ԫ�ؿ�����Ԫ�ظ�������ôҪ�յ�����������Ԫ��֮�ͣ�
// ��ģ����У�����Ҫע�⿪long long���ƺ��ܶ��󷽰�������Ŀ
// ���ս������ܴ����Կ�long longû�л��� 

const int N = 2000;
long long f[N];
int main() {
	int n;
	cin >> n;
	int t = (n * (n + 1) / 2);
	// ֻ�м��Ͽ��Ա���Ϊ�������������кͣ�����������ԼӸ���֦ 
	if (t % 2) {
		cout << 0;
		return 0;
	}
	t >>= 1;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= i; j--) {
			f[j] += f[j - i];
		}
	}
	cout << (f[t] >> 1);
	return 0;
}
