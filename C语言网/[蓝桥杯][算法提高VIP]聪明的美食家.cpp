#include <iostream>
#include <cstdio>
using namespace std;

// �����������...�ź�������ʽ�Ӳ������w.. 

const int N = 1000 + 10;
int nums[N];
int f[N];
int main() { 
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	for (int i = 0; i < n; i++) {
		f[i] = 1;
		for (int j = 0; j < i; j++) {
			// �ӣ����Ժ�ǰ��ԵĶ���һ����.. 
			if (nums[i] >= nums[j]) f[i] = max(f[i], f[j] + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res, f[i]);
	printf("%d", res);
	return 0;
}
