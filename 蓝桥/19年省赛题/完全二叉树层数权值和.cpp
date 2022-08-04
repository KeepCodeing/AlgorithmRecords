#include <iostream>
#include <cstdio>
using namespace std;

// ��ǰ����������������ȫ������һ����2^n (n >= 0)��Ԫ�أ���ôģ���������Ȼ����;��У������ģ�������׹����w
// ��������ǽ�һ����������Ȼ����BFS..���������ŷ���������˼·����naiveww�������Ǻ��ߣ��潨������ʱ��ռ䶼���кܴ�
// ��˿w...������������ֱ����n�����������ʱ����ж��µ�ǰԪ������һ��ģ�Ȼ����һ��Ͱֱ�Ӱ����Ǽ����������ͨ������
// ��Χ����֪�������Ȳ�����18... 

const int N = 18;
typedef long long LL;
LL bucket[N];
int getdeep(int n) {
	int deep = 0;
	while (n > 0) deep += 1, n /= 2;
	return deep;
}
int main() {
	int n, num;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		bucket[getdeep(i)] += num;
	}
	int maxVal = -0x3fffffff, res = 0;
	for (int i = 1; i <= N; i++) {
		if (bucket[i] > maxVal) {
			maxVal = bucket[i];
			res = i;
		}
	}
	printf("%d", res);
	return 0;
}
