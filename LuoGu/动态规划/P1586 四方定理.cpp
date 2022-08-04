#include <iostream>
using namespace std;

// ԭ������Ʒ��������Ҳ�Ƕ�ά���ñ��������ܣ�
// ������Ǹ���ȫ�������������Ƕ����һ�����ƣ����ֻ����4�Σ����Կ��԰�ʹ�ô��������Ƕ��һά���ã�
// ��ô����ö����Ʒ����������ʹ�ö��ٴΣ���Ʒ��ֵ������... 

typedef long long LL;
const int N = 32768 + 10, M = 10;
LL f[N][M];
int main() {
	f[0][0] = 1;
	// ����ö����Ʒ��������Ʒ�������ƣ���Ʒ��ֵ 
	for (int i = 1; i * i <= N; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = i * i; k <= N; k++) {
				// ��ǰѡ����������һ��״̬ת�ƶ��� 
				f[k][j] += f[k - i * i][j - 1];
			}
		}
	}
	int T;
	cin >> T;
	int num, ans = 0;
	while (T--) {
		ans = 0;
		cin >> num;
		// �𰸾���ѡ[1,4]�����ķ���֮�� 
		for (int i = 1; i <= 4; i++) ans += f[num][i];
		cout << ans << endl;
	}
	return 0;
}
// �����ݣ�if (p & 1) s *= q^(1~p) 
//#include <iostream>
//using namespace std;
//int main() {
//	int b, p, k, s = 1;
//	int b1, p1;
//	cin >> b >> p >> k;
//	b1 = b, p1 = p;
//	while(p1) {
//		if (p1 & 1) s = s * 1ll * b1 % k;
//		b1 = b1 * 1ll * b1 % k;
//		p1 >>= 1;
//	}
//	cout << b << "^" << p << " mod " << k << '=' << s % k; 
//	return 0;
//}
