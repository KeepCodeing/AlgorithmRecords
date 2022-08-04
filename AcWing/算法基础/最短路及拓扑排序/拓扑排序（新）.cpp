#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;

// ֮ǰһֱ��û��ôѧ��Ҳûʲô��⣬�������ڴ�����ܽ��һ�仰�ˣ������Ϊ0�ĵ㿪ʼ��ÿ�ν�����ֱ�ӵ���ĵ��
// ��ȼ��٣������˼�ǰ�������Ϊ0�ĵ��ͼ�ȥ��������������Ϊ0����Ӽ�����չ...

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
		// ��priority_queue����queue���Դﵽ�ڵ�С���������Ч��... 
		int ut = que.front(); que.pop();
		
		// ע�������visҪȥ������Ҫ����Ϊ������ͼ���л�ͼ����ô����ĳ����ͻ�һֱ�벻�˶ӣ����������
		// vis���ͻᵼ�����е㶼ֻ����һ��... 
		// if (vis[ut]) continue;
		// vis[ut] = true;
		
		// ������������������cnt < n��˵���������е㶼����ˣ�Ҳ���Ǵ��ڻ�·... 
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
	// ��仰���п��ޣ���Ϊ���һ������ 
	if (cnt < n) return 0;
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	return 0;
} 

/*
����û����ԡ����С������������д���... 
���Ҫ�ڵ�С�����������ô����һ���ṹ�壨ֻ��һ����ģ����Ҫ��ӵĵ㣬Ȼ����priority_queue����queue 
Sample Input
4 3
1 2
2 3
4 3
 
Sample Output
1 2 4 3
*/
