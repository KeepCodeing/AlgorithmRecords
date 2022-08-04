#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ��ĿҪ�����ɸ������ܵ��Ĺ�ͬ����ļ��ϣ����ǿ���
// ö����Щ���ܵ����Ȼ���ж��Ƿ����ظ��� 

// û�б����ʼ��ĳ��ӣ������㵼�´�����k����Ҳ������ʼ����� 

// �������������Ͱ��������Ȼ��map�ȽϷ��㣨���꣩ 

vector<int > graph[1005];
map<int, int > record;
int k, n, m;
int *cows;
bool *visited;

void dfs(int cur) {
	int v;
	// û�б����ʼ�㣬׹��w 
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
