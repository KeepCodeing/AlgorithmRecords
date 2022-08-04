#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 题目要求若干个顶点能到的共同顶点的集合，我们可以
// 枚举这些点能到哪里，然后判断是否有重复点 

// 没有标记起始点的池沼，这样搞导致答案少了k个（也就是起始点个） 

// 另外这里可以用桶排做，虽然用map比较方便（大嘘） 

vector<int > graph[1005];
map<int, int > record;
int k, n, m;
int *cows;
bool *visited;

void dfs(int cur) {
	int v;
	// 没有标记起始点，坠毁w 
	visited[cur] = true;
	record[cur]++;
	for (int i = 0; i < graph[cur].size(); i++) {
		v = graph[cur][i];
		if (!visited[v]) {
			visited[v] = true;
			dfs(v);
		}
	}
}

int main() {
	cin >> k >> n >> m;
	cows = new int[k + 1];
	visited = new bool[n + 1];
	for (int i = 1; i <= k; i++) cin >> cows[i];
	int u, v;
	while(m--) {
		cin >> u >> v;
		graph[u].push_back(v); 
	}
	for (int i = 1; i <= k; i++) {
		fill(visited, visited + n + 1, false);
		dfs(cows[i]);
	}
	int ans = 0;
	for (map<int, int >::iterator it = record.begin(); it != record.end(); it++) {
		if (it->second != k) continue;
		ans++;
	}
	cout << ans;
	delete[] cows, visited;
	return 0;
}
