#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 55, M = 20000 + 10;
struct cookies {
	int val, k;
	cookies(int val, int k) : val(val), k(k) {};
	cookies() {};
} ck[N];
vector<cookies > vec;
int f[M];
int main() {
	int n, m, val, k;
	cin >> m >> n;
	while (n--) {
		cin >> val >> k;
		// �������Ż��İ��ӣ�ע�����ֱ�����ߴ���... 
		for (int i = 1; i <= k; i <<= 1) {
			// ���ｫ��Ʒ��������Ϊ��ζ�̶ȣ�����ֵ����Ϊ��Ʒ������Ȼ����01��������... 
			vec.push_back(cookies(val * i, i));
			k -= i;
		}
		if (k > 0) vec.push_back(cookies(val * k, k)); 
	}
	// ע���ʼ������ΪҪ�������Сֵ������һ��ʼ��Ҫ����Ϊ���ֵ�����ǹ��������ֵû���ã���Ϊ
	// �ʼ���Ǹ�״̬Ҳ�Ǹ����ֵ������Ҫ���ʼ��״̬���⴦��Ϊ0.. 
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = m; j >= vec[i].val; j--) {
			// 01������ע���������Ʒ��ֵ�������Ʒ����.. 
			f[j] = min(f[j], f[j - vec[i].val] + vec[i].k);
		}
	}
	if (f[m] != 0x3f3f3f3f) cout << f[m];
	else cout << "><";
	return 0;
}
