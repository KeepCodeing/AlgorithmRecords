#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int nums[N], f[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	f[1] = nums[1];
	// ����ʽ���＼w��������������к͵Ķ������ǰ��ĺͼ�������������ܲ��ܱ��������... 
	for (int i = 2; i <= n; i++) f[i] = max(f[i - 1] + nums[i], nums[i]);
	int res = -0x3fffffff;
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	printf("%d", res);
	return 0;
}
