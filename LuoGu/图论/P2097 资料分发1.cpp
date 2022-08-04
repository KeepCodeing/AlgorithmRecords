#include <iostream>
#include <vector>
using namespace std;

// 看起来是个求连通图数量的题 
// 谔谔，原来有重边和回环不影响连通量数量，另外这个题还可以用并查集来做

// 并查集板子 

struct unionFind {
	int *bin;
	unionFind(int n) {
		bin = new int[n + 1];
		for (int i = 1; i <= n; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		// 这里又写成了x 
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	~ unionFind() {
		delete[] bin;
	}
}; 

int n, m;
vector<int > graph[100010];
bool *visited;
void dfs(int cur) {
	visited[cur] = true;
	int v;
	for (int i = 0; i < graph[cur].size(); i++) {
		v = graph[cur][i];
		if (!visited[v]) {
			visited[v] = true;
			dfs(v); 
		}
	}
} 
int main() {
	cin >> n >> m;
	unionFind uf(n);
	int u, v;
	int cnt = n;
	while (m--) {
		cin >> u >> v;
		// 每在边集加入一条边就将两个点加入一个集合（如果这两个点本来不在一个集合的话）答案数减1
		// 不在一个集合就说明这两个边还不连通（大概），而如果连通边一定能找到某个公共顶点
		// 这么说求图的连通量就可以用并查集来做 
		if (!uf.ask(u, v)) {
			uf.uni(u, v);
			cnt--; 
		}
	}
	cout << cnt;
	return 0;
}
//int main() {
//	cin >> n >> m;
//	visited = new bool[n + 1]();
//	int u, v;
//	while (m--) {
//		cin >> u >> v;
//		graph[u].push_back(v); 
//		// 无向 
//		graph[v].push_back(u); 
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			dfs(i);
//			cnt++;
//		}
//	}
//	cout << cnt;
//	delete[] visited;
//	return 0;
//}
