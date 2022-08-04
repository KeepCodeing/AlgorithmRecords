#include <iostream>
using namespace std;
// 这里把数组开两倍是因为x * 2这种走法如果只走一半的数轴的话是走不完的，所以这里要开两倍保证这种
// 走法能走完 
const int N = 1e5 * 2 + 10;
int que[N], dist[N];
int bfs(int x, int y) {
	fill(dist, dist + N, -1);
	int qtop = 0, qback = 0;
	que[qtop] = x;
	dist[x] = 0;
	// 总的来说还算记住了这个题（并不敢说理解w） 
	while (qtop <= qback) {
		int t = que[qtop++];
		if (t == y) return dist[t];
		// t + 1在数轴内并且某点未访问就说明可以走，下面的判断同理 
		if (t + 1 < N && dist[t + 1] == -1) {
			dist[t + 1] = dist[t] + 1;
			que[++qback] = t + 1;
		}
		if (t - 1 >= 0 && dist[t - 1] == -1)  {
			dist[t - 1] = dist[t] + 1;
			que[++qback] = t - 1;
		}
		if (t * 2 < N && dist[t * 2] == -1) {
			dist[t * 2] = dist[t] + 1;
			que[++qback] = t * 2;
		}
	}
	return -1;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		// 别样的爆零技巧：不打换号 
		cout << bfs(x, y) << endl;
	}
	return 0;
}
