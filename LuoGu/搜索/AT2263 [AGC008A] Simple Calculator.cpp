#include <iostream>
#include <map>
#include <queue>
using namespace std;

// 又是搜索（BFS）... 
// 只过了4个点...，其它全超时了..不是正解的末路w 

typedef long l;
map<l, int > dist;
queue<l > que;
int bfs(l x, l y) {
	dist[x] = 0;
	que.push(x);
	while (!que.empty()) {
		l now = que.front();que.pop();
		if (now == y) return dist[now];
		if (!dist[now + 1]) dist[now + 1] = dist[now] + 1, que.push(now + 1);
		if (!dist[-now]) dist[-now] = dist[now] + 1, que.push(-now);  
	} 
	return -1;
}
int main() {
	l x, y;
	cin >> x >> y;
	cout << bfs(x, y);
	return 0;
}
