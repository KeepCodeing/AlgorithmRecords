#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// ����SPFA�㷨�Ƚ���ѧ����һ����ͨ�����в��ԣ����л������ȶ���Dijkstra�㷨���� 
const int INF = 99999;
int n, m, s;
int *dist;
bool *visited;
struct Node {
	// ��ǰ�����ܵ��ĵ㼰��Ȩ�� 
	int v, weight;
	Node(int v, int w) : v(v), weight(w) {}
};
vector<Node > graph[10010];
// �����ڽӱ�洢 
// �ڽӱ�ĺô������ô���޷����ʵĽڵ㣬�ռ������ʱ������ݷ�Χ����10^5�����ڽӾ���
// ���Ի�MLE�� 
void dfs(int cur) {
	visited[cur] = true;
	cout << cur << ' ';
	for (int i = 0; i < graph[cur].size(); i++) {
		// graph[cur]��ʾ����cur��������������ͨ���� 
		if (!visited[graph[cur][i].v]) {
			// graph[cur][i].v���ǰ�ÿ������Ķ���ֵȡ���� 
			visited[graph[cur][i].v] = true;
			dfs(graph[cur][i].v);
		}
	}
}
void dijkstra(int cur) {
	dist[cur] = 0;
	int index, minDist;
	// ����Ӧ���Ǵ���㿪ʼ���������ʼ��Ϊ������ͨ�����Ȩ�� 
	for (int i = 0; i < graph[cur].size(); i++) dist[graph[cur][i].v] = graph[cur][i].weight;
	// for (int i = 0; i < graph[cur].size(); i++) cout << graph[cur][i].weight << ' ';
	// ���˵ĵ�1��������� 
	visited[cur] = true;
	// ���ﲻ�Ǳ���������ͨ���㣬���Ƕ�ȫ��������б��� 
	for (int i = 1; i <= n - 1; i++) {
		minDist = INF;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				minDist = min(dist[j], minDist);
				index = j;
			}
		}
		visited[index] = true;
		for (int v = 0; v < graph[index].size(); v++) {
			// ����ĵ�1������·��ʱ�����ж��Ƿ�ʹ�ù�ĳ������ 
			// if (!visited[graph[index][v].v]) {

				// ���ǵĵ�2:�Ƕ�dist�����ÿ��Ԫ�ؽ��и��£������ǶԵ�ǰ������Ǹ�
				// Ԫ�ظ��� 
				
				// ���index��������㣩��v��ͨ· 
				if (graph[index][v].weight != INF) {
					if (dist[graph[index][v].v] > dist[index] + graph[index][v].weight) {
						dist[graph[index][v].v] = dist[index] + graph[index][v].weight;
					}
					
				}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	// �ӣ�memset����������ʼ���������飬�����ǳ�ʼ����Ҳֻ�ܳ�ʼ��Ϊ0 
	// memset(dist, INF, sizeof(dist));
	// cout << dist[1] << endl;
	visited = new bool[n + 1];
	dist = new int[n + 1];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		// ��ʾ����u������v�бߣ��ҳ���Ϊw
		// ע���ʼ��(Node){}��������ܻ��и�warning  
		graph[u].push_back((Node){v, w});
	} 
	dijkstra(s);
	// dfs(s);
	for (int i = 1; i <= n; i++) {
		cout << dist[i];
		if (i != n) cout << ' ';
	}
	delete[] visited, dist;
	return 0;
}
