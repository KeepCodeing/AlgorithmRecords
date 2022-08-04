#include <iostream>
#include <queue>
#include <map>
using namespace std;

// 改写了以前的办法，这次用的是类似最短路的写法，用queue代替了数组，原来那个写法可能
// 会有状态多于下标的情况，用步数代替了栈里元素个数，因为可能当前状态还没走到退出的步数，
// 后面的状态就都被剪掉了，同理这样写也可能会有一些状态本该退出但是没有的问题。 

typedef unsigned long long LL;
typedef pair<LL, int > PII; 
const int mod = 1000000007, out = 100000;
queue<PII > que;
map<LL, bool > vis;
int bfs(int start) {
	que.push(PII(start, 0)); 
	while (que.size()) {
		PII now = que.front(); que.pop();
		LL d = now.first;
		int step = now.second;
		// 剪掉状态步数过多的情况 
		if (step > out) continue;
		// 这个地方能够退出的条件应该就是d == 1e9 + 7或者d == 0... 
		if (!(d % mod)) return step;
		// 先取模才算是新状态，这是因为只有1e9 + 7的倍数才算终点，那么超过
		// 1e9 + 7就是没意义的了.. 
		int nx1 = (d * 4 + 3) % mod, nx2 = (d * 8 + 7) % mod;
		// 用map离散化标记 
		if (!vis[nx1]) que.push(PII(nx1, step + 1)), vis[nx1] = true;
		if (!vis[nx2]) que.push(PII(nx2, step + 1)), vis[nx2] = true;  
	}
	return -1;
}
int main() {
	LL start;
	cin >> start;
	cout << bfs(start);
	return 0;
} 
