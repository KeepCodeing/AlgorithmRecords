#include <iostream>
#include <cstdio>
using namespace std;

// ö��ÿ���㣬�����������Ϊ�ָ��ܲ���ʹ������������ĺ����
// ����ǰ׺�ͽ���Ԥ���� 

// ֮ǰ���и�ACM ICPC���⣬�����Ҳ��Ҫ�����������ֻ�����Ǹ���������С
// ���Կ����ñ��ѣ�������������ܴ����Ե���ǰ׺�� 

typedef long long LL;
const int N = 1e5 + 10;
LL s[N];
int main() {
	s[0] = 0;
	int n;
	scanf("%d", &n);
	int t;
	for (int i = 1; i <= n; i++) scanf("%d", &t), s[i] = s[i - 1] + t;
	// ö��ÿ���и�㣬ע�����һ���㲻��ȡ����Ϊ��ĿҪ���������䶼����Ϊ�� 
	int cnt = 0;
	for (int i = 1; i <= n - 1; i++) {
		// ����ö���Ե�ǰ��Ϊ�ָ�㣬������������ĺ��Ƿ���� 
		if (s[i] == s[n] - s[i]) cnt++;
	} 
	cout << cnt;
	return 0;
}
