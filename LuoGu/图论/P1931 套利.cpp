#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

// ����һ����������w...���֮ǰ�����þ�֮ǰ������Ӧ�û����ӡ���... 
// ��Щ����...��ʵ֤��������˲���Ҳ���������ο�������������... 

const int N = 1000;
int head[N], e[N], ex[N], idx = 0;
double w[N], dist[N];
bool vis[N];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
map<string, int > mp;
bool spfa(int st) {
	for (int i = 0; i < N; i++) dist[i] = 0;
	memset(vis, 0, sizeof vis);
	queue<int > que;
	que.push(st);
	dist[st] = 1.0;
	while (que.size()) {
		int ut = que.front(); que.pop();
		vis[ut] = false;
		if (ut == st && dist[st] > 1.0) return true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			double wt = w[i] * dist[ut];
			// ƾ�ż�����İ���һͨ�Ҵ�Ȼ���ֲ���...����˲ŷ������ɳ��������ˣ�Ӧ����Խ��Խ����У�������
			// �����·һ����С����Ϊ��������Ϊ��׬Ǯ... 
			// ��������Ŀ˵�����·�����������ɳ������ǣ����Ǳ��ʻ����жϡ���������... 
			if (dist[vt] < wt) {
				dist[vt] = wt;
				if (!vis[vt]) {
					vis[vt] = true;
					que.push(vt); 
				}
			}
		}
	} 
	return false;
}
int main() {
	int n, m;
	double wt;
	string ut, vt;
	for (int T = 1; cin >> n, n; T++) {
		bool flag = false;
		// ע���ڽӱ�ĳ�ʼ��idxҲҪ�ָ� 
		memset(head, -1, sizeof head), idx = 0;
		for (int i = 1; i <= n; i++) cin >> ut, mp[ut] = i;
		cin >> m;
		while (m--) {
			cin >> ut >> wt >> vt;
			add(mp[ut], mp[vt], wt);
		}
		for (int i = 1; i <= n; i++) {
			if (spfa(i)) {
				flag = true;
				break;
			}
		}
		cout << "Case " << T << ": " << (flag ? "Yes" : "No") << '\n';
	}
	return 0;
}
