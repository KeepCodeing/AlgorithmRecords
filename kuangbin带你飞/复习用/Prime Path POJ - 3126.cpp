#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

// 用来fuxiBFS枚举状态，颓废好久了... 

typedef pair<int, int > PII;
const int N = 10000;
// 防止重复入队 
bool visited[N];
bool prime[N];
// 优化埃氏筛，差点忘记... 
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
	// 第一位存当前数组，第二位存走了的步数 
	que.push(PII(x, 0));
	while (que.size()) {
		PII now = que.front();que.pop();
		if (now.first == y) return now.second;
		int px = now.first, py = now.second;
		// 枚举第一位的数字，开头不能为0 
		for (int i = 1; i <= 9; i++) {
			num = i * 1000 + px % 1000;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		} 
		// 第二位 
		for (int i = 0; i <= 9; i++) {
			int temp = px % 1000;
			num = px - temp;
			num += i * 100 + temp % 100;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		}
		// 第三位，第三位写成了num = px - 100... 
		for (int i = 0; i <= 9; i++) {
			int temp = px % 100;
			num = px - temp;
			num += i * 10 + temp % 10;
			if (prime[num] || visited[num]) continue;
			visited[num] = true;
			que.push(PII(num, py + 1)); 
		} 
		// 第四位 
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
