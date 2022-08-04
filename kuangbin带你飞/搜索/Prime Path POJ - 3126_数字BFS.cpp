#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

// 这个题其实是利用了BFS的最短路特性，而不是大爆搜直接枚举所有可能，后者甚至没办法记录最短路径是多少...
// 那么最短路的特性其实就是使得操作数最少，所以正解是个BFS，这种BFS其从来没有写过...这个题的思路是先打个
// 质数表，然后因为每个位置的数字都只能在0~9之间变换，而且要求变换后也是素数，因此可以直接枚举这些数字，
// 然后加入队列，根据BFS的最短路特性，第一次出现的目标数字就是步数最短的数字了... 

// 乍一看码农题，实际上很多重复代码... 

// 用来记录步数和当前元素的pair 
typedef pair<int, int > PII;
const int N = 10000 + 10, M = 1e6 * 5;
bool primes[N], visited[N];
// 打个质数表方便后面判断新产生的数字是否是素数.. 
void getPrimes() {
	primes[0] = primes[1] = true;
	for (int i = 2; i < sqrt(N); i++) {
		if (primes[i]) continue;
		for (int j = i * i; j < N; j += i) {
			primes[j] = true;
		}
	}
}
// 不知道有多少种情况，所以队列无脑开的非常大.. 
PII que[M];
int bfs(int x, int y) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(x, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		if (now.first == y) return now.second;
		// 枚举个位上的数字的可能，注意交换可能产生重复，这也是其DFS里碰到的问题，所以要用个visited标记下
		for (int i = 0; i <= 9; i++) {
			// 个位上的数字只可能是0~9，那么我们可以先把个位的数字去掉（即置零），然后加上0~9的数字就行了
			int temp = now.first;
			// 去掉原来的个位数字，加上新的个位数字 
			temp = temp - temp % 10 + i; 
			// 如果新产生的数字没有被使用过并且是素数，那么这个数字就是个合法数字，将其入队继续扩展... 
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			} 
		} 
		// 枚举十位数字，实现和个位相同，后面也差不多
		for (int i = 0; i <= 9; i++) {
			int temp = now.first;
			// 注意只能改变十位的数字，个位数字要还原 
			temp = temp - temp % 100 + temp % 10 + i * 10;
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			}
		} 
		// 枚举百位的数字 
		for (int i = 0; i <= 9; i++) {
			int temp = now.first;
			temp = temp - temp % 1000 + temp % 100 + i * 100;
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			}
		}
		// 枚举千位的数字，注意千位的数字不能从0开始 
		for (int i = 1; i <= 9; i++) {
			int temp = now.first;
			temp = i * 1000 + temp % 1000;
			if (!visited[temp] && !primes[temp]) {
				visited[temp] = true;
				que[++qback] = PII(temp, now.second + 1);
			}
		} 
	}
	return -1;
}
int main() {
	getPrimes();
	int T, x, y, res;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		// 注意重置访问数组... 
		memset(visited, 0, sizeof visited);
		res = bfs(x, y);
		if (res == -1) cout << "Impossible" << endl;
		else cout << res << endl;
	}
	return 0;
} 
