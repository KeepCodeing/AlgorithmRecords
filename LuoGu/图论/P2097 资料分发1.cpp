#include <iostream>
#include <vector>
using namespace std;

// �������Ǹ�����ͨͼ�������� 
// ���̣�ԭ�����رߺͻػ���Ӱ����ͨ����������������⻹�����ò��鼯����

// ���鼯���� 

struct unionFind {
	int *bin;
	unionFind(int n) {
		bin = new int[n + 1];
		for (int i = 1; i <= n; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		// ������д����x 
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
		// ÿ�ڱ߼�����һ���߾ͽ����������һ�����ϣ�����������㱾������һ�����ϵĻ���������1
		// ����һ�����Ͼ�˵���������߻�����ͨ����ţ����������ͨ��һ�����ҵ�ĳ����������
		// ��ô˵��ͼ����ͨ���Ϳ����ò��鼯���� 
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
//		// ���� 
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
