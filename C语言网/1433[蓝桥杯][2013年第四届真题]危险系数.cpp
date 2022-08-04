#include <iostream>
#include <vector>
using namespace std;

// 感觉就是个DFS，然后统计下路过了几个点，如果走完了还没到
// 终点，则说明不连通，所谓的关键点也就是起点和终点之间的
// 顶点数，如果是连通的话去掉任意一个顶点都会导致其不连通 

// 这个题目的正解是：如果某个点经过的次数是总路径的次数，那么这个点就是关键点

int spos, epos;
bool *visited;
vector<int > graph[1010];
int *record; 
int successCnt = 0, ans = 0;
int m, n;
void dfs(int cur) {
	// 标记走过的点，下面再将其还原 
	visited[cur] = true;
	if (cur == epos) {
		// 统计走过的点的次数 
		for (int i = 1; i <= n; i++) {
			if (visited[i]) record[i]++;
		}
		// 还原终点的状态，不然没办法继续走 
		visited[epos] = false;
		successCnt++;
		return;
	}
	for (int i = 0; i < graph[cur].size(); i++) {
		if (!visited[graph[cur][i]]) {
			// 标记走过的所有点在上面 
			// visited[graph[cur][i]] = true;
			dfs(graph[cur][i]);
		}
	}
	// 这里相当于个回溯 
	visited[cur] = false;
}

int main() {
	cin >> n >> m;
	visited = new bool[m + 3]();
	record = new int[m + 3]();
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);  
	}
	cin >> spos >> epos;
	// 搞笑神作，输入没搞清楚，这里还弄的骚操作，结果全部坠毁w 
//	while (n--) {
//		if (n != 0) {
//			cin >> u >> v;
//			graph[u].push_back(v);
//			// 喜闻乐见的无向图，题目里没有说明，但是说是两点之间无法到达
//			// 而且其用的是DF(u,v)来表示图 
//			graph[v].push_back(u);  
//			continue;
//		}
//		cin >> spos >> epos;
//	}
	dfs(spos);
	if (!successCnt) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (record[i] == successCnt && i != spos && i != epos) ans++;
	}
	cout << ans;
	delete[] visited, record;
	return 0;
} 

// 写的有问题...，首先，没有权值，因此无需使用结构体，其次，思路不对， 
//struct Node {
//	int v, w;
//	Node (int v, int w) : v(v), w(w) {};
//};
//vector<Node > graph[1010];
//vector<int > path;
//bool *visited;
//int cnt = 0;
//bool flag = true, used = false;
//// 奇妙，end这个变量名似乎在C语言网的评测机里冲突了 
//int start_x, end_x;
//void dfs(int cur) {
//	// cout << cur << endl;
//	if (cur == end_x) {
//		flag = true;
//		return;
//	}
//	visited[cur] = true;
//	visited[end_x] = false;
//	Node temp(0, 0);
//	for (int i = 0; i < graph[cur].size(); i++) {
//		temp = graph[cur][i];
//		if (!visited[temp.v]) {
//			visited[temp.v] = true;
//			// cnt++;
//			if (!used) path.push_back(temp.v); 
//			dfs(temp.v);
//		}
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	visited = new bool[m + 3];
//	int u, v;
//	for (int i = 1; i <= n; i++) {
//		if (i == n) {
//			cin >> start_x >> end_x;
//			continue;
//		}
//		cin >> u >> v;
//		graph[u].push_back((Node){v, 1});
//		graph[v].push_back((Node){u, 1});
//	}
//	dfs(start_x);
//	// for (int i = 0; i < path.size(); i++) cout << path[i] << ' ';
//	// cout << endl;
//	used = true;
//	if (path.size() == 0) {
//		cout << -1;
//		return 0;
//	}
//	for (int i = 0; i < path.size(); i++) {
//		fill(visited, visited + m + 3, false);
//		if (path[i] == end_x) continue;
//		flag = false;
//		visited[path[i]] = true;
//		dfs(start_x);
//		// cout << "------------" << endl;
//		if (!flag) cnt++;
//	}
//	cout << cnt;
//	delete[] visited;
//	return 0;
//}

