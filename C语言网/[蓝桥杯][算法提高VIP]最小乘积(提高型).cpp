#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �����һ�����д�С����һ�����дӴ�С... 

const int N = 1000 + 10;
int nums1[N], nums2[N]; 
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, res = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &nums1[i]);
		for (int i = 0; i < n; i++) scanf("%d", &nums2[i]);
		// Ĭ������ 
		sort(nums1, nums1 + n);
		sort(nums2, nums2 + n, cmp);
		for (int i = 0; i < n; i++) res += nums1[i] * nums2[i];
		printf("%d\n", res);
	} 
	return 0;
}
