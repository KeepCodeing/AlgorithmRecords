#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

// ����fuxiBFSö��״̬���ǷϺþ���... 

typedef pair<int, int > PII;
const int N = 10000;
// ��ֹ�ظ���� 
bool visited[N];
bool prime[N];
// �Ż�����ɸ���������... 
void getprime() {
	prime[0] = prime[1] = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (prime[i]) continue;
		for (int j = i * i; j <= N; j += i) {
			prime[j] = true;
		}
	}
}
int bfs(int x, int y) {
	memset(visited, 0, sizeof visited);
	queue<PII > que;
	int num;
	// ��һλ�浱ǰ���飬�ڶ�λ�����˵Ĳ��� 
	que.push(PII(x, 0));
	while (que.size()) {
		PII now = que.front();que.pop();
		if (now.first == y) return now.second;
		int px = now.first, py = now.second;
		// ö�ٵ�һλ�����֣���ͷ����Ϊ0 
		for (int i = 1; i <= 9; i++) {
			num = i * 1000 + px % 1000;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		} 
		// �ڶ�λ 
		for (int i = 0; i <= 9; i++) {
			int temp = px % 1000;
			num = px - temp;
			num += i * 100 + temp % 100;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		}
		// ����λ������λд����num = px - 100... 
		for (int i = 0; i <= 9; i++) {
			int temp = px % 100;
			num = px - temp;
			num += i * 10 + temp % 10;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		} 
		// ����λ 
		for (int i = 0; i <= 9; i++) {
			num = px - px % 10;
			num += i;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		}
	} 
	return -1;
}
int T, x, y;
int main() {
	getprime();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		int res = bfs(x, y);
		if (res == -1) printf("Impossible");
		else printf("%d", res);
		puts("");
	}
	return 0;
}
