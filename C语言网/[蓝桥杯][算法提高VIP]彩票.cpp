#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 40, M = 10, K = 7;
int trick[M], bucket[N];
int res[M];
int main() {
	int n, t, cnt;
	scanf("%d", &n);
	for (int i = 1; i <= K; i++) scanf("%d", &trick[i]);
	// �����Ʊ���ҷŵ�Ͱ�Ȼ����ͳ�Ƴ����˶��ٸ���Ч���֣�����������ȥ����ά���飬���ҿ���ֱ�Ӵ��� 
	for (int i = 1; i <= n; i++) {
		memset(bucket, 0, sizeof bucket);
		// ��֤�±���ȷ 
		cnt = K + 1;
		for (int j = 1; j <= K; j++) {
			scanf("%d", &t);
			bucket[t]++;
		}
		// ����Ͱ��Ȼ��ͳ�Ƴ����˼������֣��������Լ��������±꣬���������������ǵ��ŵ�.. 
		for (int j = 1; j <= K; j++) {
			if (bucket[trick[j]]) cnt--;
		}
		// ͳ���ж��ٸ�Ʊ.. 
		res[cnt]++;
	}
	for (int i = 1; i <= K; i++) cout << res[i] << ' ';
	return 0;
}
