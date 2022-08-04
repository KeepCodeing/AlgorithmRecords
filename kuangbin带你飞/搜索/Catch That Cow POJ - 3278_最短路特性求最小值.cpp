#include <iostream>
#include <cstring>
using namespace std;

// 做过的题，不过大概忘记了呢，就当复习好了... 
// 忘得差不多了，主要是初始值的设置，还有访问否的设置.. 

int n, k;
const int N =  100000 * 2 + 10;
int que[N];
int dist[N];
int bfs() {
	// 全部设置为一个一开始不存在的值，其之前设置的就是0，但是0可以一开始就有... 
	memset(dist, -1, sizeof dist);
	int qtop = 0, qback = 0;
	que[qtop] = n;
	dist[n] = 0;
	while (qtop <= qback) {
		int now = que[qtop++];
		if (now == k) return dist[now];
		// 这里判断能不能走判断的是下一个点，而不是当前点... 
		if (now + 1 < N && dist[now + 1] == -1) {
			dist[now + 1] = dist[now] + 1;
			que[++qback] = now + 1; 
		}
		if (now - 1 >= 0 && dist[now - 1] == -1) {
			dist[now - 1] = dist[now] + 1;
			que[++qback] = now - 1;
		}
		if ( now * 2 < N && dist[now * 2] == -1) {
			dist[now * 2] = dist[now] + 1;
			que[++qback] = now * 2;
		}
	}
}
int main() {
	cin >> n >> k;
	cout << bfs();
	return 0;
}
