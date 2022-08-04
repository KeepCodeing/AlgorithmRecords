#include <iostream>
#include <vector>
using namespace std;

// �о����Ǹ�DFS��Ȼ��ͳ����·���˼����㣬��������˻�û��
// �յ㣬��˵������ͨ����ν�Ĺؼ���Ҳ���������յ�֮���
// ���������������ͨ�Ļ�ȥ������һ�����㶼�ᵼ���䲻��ͨ 

// �����Ŀ�������ǣ����ĳ���㾭���Ĵ�������·���Ĵ�������ô�������ǹؼ���

int spos, epos;
bool *visited;
vector<int > graph[1010];
int *record; 
int successCnt = 0, ans = 0;
int m, n;
void dfs(int cur) {
	// ����߹��ĵ㣬�����ٽ��仹ԭ 
	visited[cur] = true;
	if (cur == epos) {
		// ͳ���߹��ĵ�Ĵ��� 
		for (int i = 1; i <= n; i++) {
			if (visited[i]) record[i]++;
		}
		// ��ԭ�յ��״̬����Ȼû�취������ 
		visited[epos] = false;
		successCnt++;
		return;
	}
	for (int i = 0; i < graph[cur].size(); i++) {
		if (!visited[graph[cur][i]]) {
			// ����߹������е������� 
			// visited[graph[cur][i]] = true;
			dfs(graph[cur][i]);
		}
	}
	// �����൱�ڸ����� 
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
	// ��Ц����������û����������ﻹŪ��ɧ���������ȫ��׹��w 
//	while (n--) {
//		if (n != 0) {
//			cin >> u >> v;
//			graph[u].push_back(v);
//			// ϲ���ּ�������ͼ����Ŀ��û��˵��������˵������֮���޷�����
//			// �������õ���DF(u,v)����ʾͼ 
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

// д��������...�����ȣ�û��Ȩֵ���������ʹ�ýṹ�壬��Σ�˼·���ԣ� 
//struct Node {
//	int v, w;
//	Node (int v, int w) : v(v), w(w) {};
//};
//vector<Node > graph[1010];
//vector<int > path;
//bool *visited;
//int cnt = 0;
//bool flag = true, used = false;
//// ���end����������ƺ���C����������������ͻ�� 
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

