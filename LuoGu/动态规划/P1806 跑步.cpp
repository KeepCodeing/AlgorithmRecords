#include <iostream>
using namespace std;

// ͻȻ�������Ǹ�01�����󷽰���... 
// ��Ҫ�ܵľ���n�����Ǳ����ݻ���ÿ�ο����ܵľ���i������Ʒ���ۣ���Ϊÿ���ܵľ���ֻ�ܱ���һ�εľ���󣨵�����
// ����i��ʵ��ֻ��ѡһ�εģ��ɴ˿����Ƴ����Ǹ�01����... 

// ����long long������ 
typedef long long LL;
const int N = 510;
LL f[N];
int main() {
	int n;
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			// 01�����󷽰�����״̬ת�Ʒ��� 
			f[j] += f[j - i];
		}
	}
	cout << f[n] - 1;
	return 0;
} 
