#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
map<string, int > mp;
const int N = 3000 + 10;
int head[N], e[N], ex[N], idx = 0;
double w[N];
bool visited[N];
double dist[N];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
bool spfa(int st) {
	memset(visited, 0, sizeof visited);	
	memset(dist, 0, sizeof dist);
	queue<int > que;
	que.push(st);
	dist[st] = 1.0;
	while (que.size()) {
		int ut = que.front();que.pop();
		if (ut == st && dist[ut] > 1.0) return true;
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			double cost = dist[ut] * w[i];
			if (dist[vt] < cost) {
				dist[vt] = cost;
				if (!visited[vt]) {
					que.push(vt);
					visited[vt] = true;
				}
			}
		}
	}
	return false;
}
int main() {
	int n, m;
	bool flag;
	string temp, ut, vt;
	double money;
	for (int T = 1;; T++) {
		cin >> n;
		if (!n) break;
		flag = false;
		// ��������idx���RE����.. 
		idx = 0;
		memset(head, -1, sizeof head);
		for (int i = 1; i <= n; i++) cin >> temp, mp[temp] = i;
		cin >> m;
		while (m--) {
			cin >> ut >> money >> vt;
			add(mp[ut], mp[vt], money);
		}
		// ע���±��Ӧ��ֻҪ������һ�����ҿ�����������˵���𰸴��� 
		for (int i = 1; i <= n; i++) {
			flag = spfa(i);
			if (flag) break;
		}
		// ���������д����cout << cout ...��Ȼ�󱾵���ûë����OJ��ըw... 
		cout << "Case " << T << ": " << (flag ? "Yes" : "No") << endl;
	}
	return 0;
}
