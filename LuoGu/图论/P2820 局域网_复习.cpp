#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// ��ϰ���������������ĺ�������ѪŰ���������������������·����С��������ֻˢ����ģ����ڿ���Ҫ�Ӱ���...
// ������˼·��Ҫʹ��ȥ��������ֵ��󣬾�Ҫ��֤�����е����ܽ������ߵ�����������õ�������С���Զ��׼�
// ����Ǹ���С����������Ŀ�����Ĵ𰸾����ܱ�Ȩֵ����С�������ı�Ȩ�������ע��һ���㣬��ȨΪ0����û��
// ���ӣ���������ĿΪ���Ի��������ӵ�һ����������������С�������ı�Ȩ����ԽС�ı�ȨԽ��ǰ����ô���ǿ���
// ���ֱ�ȨΪ0�ı���Զ�ᱻ��ѡ�����������������ӵģ����Ծ�����ì���ˣ�����������Ǽ�Ȼ�ӽ�����������
// �����������㱾����û�ߣ��ɴ�Ͳ�������ߣ�Ҳ�����ж��±�ȨȻ������Ƿ�ӱ�... 

// ��Զ��Ҫ������Ŀ���ı����ķ�Χ���ܶ�����������鲻���ܴ�ͻ�RE.. 
const int N = 100 * 10 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	};
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m, cnt = 0, tot = 0, mnum = 0;
	scanf("%d%d", &n, &m);
	int ut, vt, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		if (!wt) continue;
		graph[cnt++] = G(ut, vt, wt), tot += wt;
	}
	// �ϸ�������д����graph + n��������ʵ���ڵ�˼άҲ���Ǻܻ�Ծ�ˣ��е��ģ������ɣ�������Ÿ�������... 
	sort(graph, graph + cnt);
	for (int i = 0; i < cnt; i++) {
		// ȥ��һЩ�߻����γɻ�·֮��Ķ��������ڰ�ʾ���������С����������Ϊȥ���߰�����˵һ���Ǹ��߻��ѵ��ߣ���
		// ��·����ζ��ȥ���߲����л�·����С�������ͱ�֤û�л�·... 
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			mnum += graph[i].w;
		}
	} 
	printf("%d", tot - mnum);
	return 0;
}
