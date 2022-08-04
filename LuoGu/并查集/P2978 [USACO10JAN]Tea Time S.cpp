#include <iostream>
using namespace std;

// �㲢�鼯����...��ʱ����С���ʱ��������...����ͣ�����أ���Ȼ����
// ��Ȼһ�ѿ�ʲô�ģ���֮��Ӧ���ǽ����һ��ˮ�⣬Ҳ�����һ���ˣ�д��ϴ��˯���� 

struct unionFind {
	int bin[1010]/*, sz[1010], dist[1010]*/;
//	unionFind() {
//		for (int i = 0; i < 1010; i++) bin[i] = i, sz[i] = 1, dist[i] = 0;
//	}
//	int anc(int x) {
//		if (x != bin[x]) dist[x] += dist[bin[x]], bin[x] = anc(bin[x]); // ����д����x=anc(bin[x])... 
//		return bin[x];
//	}
//	int uni(int x, int y) {
//		int ax = anc(x), by = anc(y);
//		dist[ax] = sz[by];
//		sz[by] += sz[ax];
//		// ����д��Ҳ�е�����w����ʵby�����ھ������Լ������Ի�����ֱ��дby���������˼�ǰ�ax�ϲ���by��... 
//		bin[ax] = bin[by];
//	}
//	int getDist(int x, int y) {
//		int ax = anc(x), ay = anc(y);
//		if (ax != ay) return -1;
//		return max(0, abs(dist[ax] - dist[ay] - 1)); // ����Ӧ�ð�-1д���棬����Ӧ��û������� 
//	} 
	// �����Ǵ���Ȩ���鼯�İ��ӣ�д�˱飨����˵Ĭдw�����е�С���⣬���������... 
	unionFind() {
		for (int i = 0; i < 1010; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = bin[anc(y)];
	}
	char ask(int x, int y) {
		return anc(x) == anc(y) ? 'Y' : 'N';
	}
};
unionFind u;
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	int x, y;
	while (m--) {
		cin >> x >> y;
		u.uni(x, y); 
	}
	while (q--) {
		cin >> x >> y;
		cout << u.ask(x, y) << endl;
	}
	return 0;
}
