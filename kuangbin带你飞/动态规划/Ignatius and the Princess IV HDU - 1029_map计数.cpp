#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// ��Ȼ����������dp���棬��ʵ���Ͼ��Ǹ�Ͱ��ˮ��w����֮����һ���㷨
// ��û��������ʼѧDP�������ű��ƺ��ؿ�������w����ˢw 

const int N = 1e6 + 10;
int bucket[N];
int main() {
	int n, num, res, temp;
	while (scanf("%d", &n) != EOF) {
		memset(bucket, 0, sizeof bucket);
		res = 0, temp = n;
		// ����ֱ��д��n--�ˣ����滹��n�ж�...ʵ������w 
		while (temp--) {
			scanf("%d", &num);
			bucket[num]++;
			if (bucket[num] >= (n + 1) / 2) res = num;
		}	
		printf("%d\n", res);
	}
	return 0;
}
