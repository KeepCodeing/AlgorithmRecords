#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;

// 之前一直都没怎么学，也没什么理解，不够现在大概能总结成一句话了：从入度为0的点开始，每次将它能直接到达的点的
// 入度减少（大概意思是把这个入度为0的点从图里“去掉”），如果入度为0则入队继续扩展...

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int rd[M], res[N];
int head[N], e[M], ex[M], idx = 0;
int n, m, ut, vt, cnt = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void bfs() {
	queue<int > que;
	for (int i = 1; i <= n; i++) {
		if (rd[i] == 0) que.push(i); 
	}
	while (que.size()) {
		// 用priority_queue代替queue可以达到节点小的先输出的效果... 
		int ut = que.front(); que.pop();
		
		// 注意这里的vis要去掉，主要是因为如果这个图是有环图，那么它的某个点就会一直入不了队，而如果加了
		// vis，就会导致所有点都只经过一次... 
		// if (vis[ut]) continue;
		// vis[ut] = true;
		
		// 将拓扑序存起来，如果cnt < n就说明不是所有点都入队了，也就是存在环路... 
		res[++cnt] = ut;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (--rd[vt] == 0) que.push(vt); 
		}
	}
}
int main() {
	memset(head, -1, sizeof head);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> ut >> vt;
		add(ut, vt);
		rd[vt]++;
	}
	bfs();
	// 这句话可有可无，因为结果一定存在 
	if (cnt < n) return 0;
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	return 0;
} 

/*
这里没有针对“编号小的先输出”进行处理... 
如果要节点小的先输出，那么就用一个结构体（只有一个点的）存放要入队的点，然后用priority_queue代替queue 
Sample Input
4 3
1 2
2 3
4 3
 
Sample Output
1 2 4 3
*/
