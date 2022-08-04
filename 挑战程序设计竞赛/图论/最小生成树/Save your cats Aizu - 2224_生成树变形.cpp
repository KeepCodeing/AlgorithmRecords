#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// �о���һ��������˼���⣬��������׮��������Կ����ǵ㣬Ȼ���������׮�����Ӿ���˵��������֮���бߣ��ߵĳ��Ⱦ���
// ��������ľ���...�������·��ָ���ͼ�����Ǹ�ɭ�֣�Ȼ��ÿ����ͨ����ʵ�ʹ���������è��Ҫʹ�û��ѵ�ʥˮ��С��ʵ����˵
// Ҫȥ�������ͨ�����һ����С��..��ô������ͨ�����˵����ͼ�γ��˻�·��ǰ�����������Ĺ���������ͬ�����һ�����ܵ�
// ˼·�������ߵĹ������жϵ�ǰ�������Ƿ�ɻ��ˣ� Ȼ��ͳ����̱ߣ���������˻��ͼ���֮ǰͳ�Ƶ���̱߳��Ȳ�������̱�... 

// ׹��w������һ�������ͼ������һ��Բ���м��п�������ͼ�������������һ���ұ�һ������ʱ���ܿ���ͳ�Ƴ����ͼ����̱�
// ���ұ�ͼ����̱ߣ��������ǲ�һ����ֻ��ȥ����������̱ߣ����ǿ���ѡ����м�������ȥ����Ȼ����ȥ�����ҵ���̱�... 
// �������㷨����ɭ�֣�����ֻ��һ����ͨ���ͼ���ǿ��еģ����Ƕ���������˵������ͼ�޷�����...

// ��ÿ����ͨ����˵����һ������һ����̱ߣ������ͨ����Կ�����ȥ��������ӱ߻�����̱ߣ��м�����ͨ���Ҫȥ������̱�
// ���������ǲ�̫�У�������ɭ��������ֲ�������... 
// ��һ������ķ�ʽ����������Ȼ������׹����ww 

const int N = 10000 + 10, M = N * 2, INF = 1e9 + .0;
vector<double > vec;
struct Pos {
	int x, y;
} pos[N];
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getCnt(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (bin[i] == i) cnt++;
		}
		return cnt;
	}
};
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
unionFind uf;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	int u, v;
	double res = 0, mDist = INF;
	int cnt = 0;
	while (m--) {
		scanf("%d%d", &u, &v);
		if (!uf.ask(u, v)) {
			uf.uni(u, v); 
			// printf("%.3lf\n", cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
			mDist = min(mDist, cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
		} else {
			cnt++;
			// printf("%.3lf    %.3lf\n", mDist, cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
			vec.push_back(mDist);
			vec.push_back(cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
			res += mDist;
			mDist = INF;
		}
		// uf.uni(u, v);
		// printf("%.3lf\n", cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
		// mDist = min(mDist, cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
	}
	int vLen = vec.size();
	sort(vec.begin(), vec.end());
	if (uf.getCnt(n) == 1) {
		res = .0;
		for (int i = 0; i < cnt; i++) res += vec[i];
	}
	printf("%.3lf", res);
	return 0;
}
