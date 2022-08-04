#include <iostream>
#define endl '\n'
using namespace std;
const int N = 200000 + 10;
int bin[N], dist[N];
int ans = 0x3fffffff;

// ��Dijkstra����floyd������ͼ����С�����Ӷȶ���̫���룬��������ͼ��floyd�㷨��˵����������С����ʵ������һ��
// ȫԴ���·...
// ����ʹ�ò��鼯���н��⣬������Ҫ˼·�������ߵĹ������ж��������Ƿ���һ������������һ���������˵��x��
// ��y��һ����·���ôx��y�ľ���;���x�����ڵ�ľ���+y�����ڵ�ľ���+1���������ֺʹ�Ȩ���鼯���� 

struct unionFind {
	unionFind() {
		// ����dist�ĳ�ʼֵ��һ��ʼ�����е㶼�ǵ�����һ���㣬����û�е����ڵ�ľ��� 
		for (int i = 0; i < N; i++) bin[i] = i, dist[i] = 0; 
	}
	int anc(int x) {
		if (x != bin[x]) {
			// ע�������д�������Ͳ��鼯��·�����Ȳ�ͬ����Ҫ�ľ�����·��ѹ��ǰ��...����һ��������˳��涨�ģ�
			// ���Կ���ֱ�Ӱѵ�ǰ��ľ���Ӹ��ڵ��Ƶ���... 
			int fa = bin[x];
			// ��ͨ���鼯�����߹��� 
			bin[x] = anc(bin[x]);
			dist[x] += dist[fa];
		}
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x), b = anc(y);
		if (a == b) {
			// ���x��y��������һ���������˵��������һ����·���ôͳ��������ĳ��� 
			ans = min(ans, dist[x] + dist[y] + 1);
		} else {
			bin[a] = b;
			// �������һ����������кϲ���ʱ�����x��y�ĸ��ڵ�ľ��� 
			dist[x] = dist[y] + 1;
		}
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, vt;
	cin >> n;
	unionFind uf;
	for (int i = 1; i <= n; i++) {
		cin >> vt;
		uf.uni(i, vt);
	} 
	cout << ans << endl;
	return 0;
}
