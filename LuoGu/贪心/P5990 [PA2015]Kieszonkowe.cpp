#include <iostream>
#include <cstdio>
using namespace std;

// ˼·���ǰ����������������ж����ǲ���ż������ż����ǰ�;������ģ�
// �����ȥһ����С������ǰ�;ͱ����ż����Ҳ���Ǵ𰸡� 

/*
����+����=ż��

����+ż��=����

ż��+ż��=ż��
*/
typedef long long LL;
int main() {
	int n, mNum = 0x3fffffff, t;
	LL res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		res += t;
		if (t % 2) mNum = min(mNum, t);
	}
	if(n == 1 && res % 2) {
		printf("NIESTETY");
		return 0;
	}
	if (res % 2) res -= mNum;
	printf("%d", res);
	return 0;
}
