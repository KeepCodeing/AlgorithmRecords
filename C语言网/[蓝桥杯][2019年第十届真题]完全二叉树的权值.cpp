#include <iostream>
#include <cstdio>
using namespace std;
const int N = 20;
int getdeep(int x) {
	int deep = 0;
	// ��ǰ��ȣ�Ҳ�����㵱ǰ�����2�ļ��η���.. 
	while (x) deep++, x >>= 1;
	return deep;
}
typedef long long LL;
LL res[N];
int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		res[getdeep(i)] += t;
	}	
	// ��֪��ΪʲôINT_MIN���벻��.. 
	int ans = 0, mx = -0x3fffffff;
	for (int i = 1; i < N; i++) {
		if (res[i] > mx) mx = res[i], ans = i;
	}
	printf("%d", ans);
	return 0;
}
