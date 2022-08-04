#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

// һЩ�涨�����ȹ涨����������ʲô���������Ⱦ��ǵ�ǰ������и��ڵ㣬���Ұ�����ǰ�ڵ㣬��ô�����������������Ⱦ���
// ���������ߵ�һ����ͬ�ĸ��ڵ㡣 

// Tarjan�㷨�Ƕԡ������Ҹ����㷨�ĸĽ�����������ǰ�ߣ�����㷨˼·�ܼ򵥣�ÿ��Ҫ��������Ĺ������ȣ��Ǿʹ������
// ��ʼ���ϲ��ң�������ĵ�һ����ͬ���ڵ�������ǵ�LCA������㷨���Ӷ�ΪO(n)��m��ѯ�ʾ���O(mn)����Ϊ��Ч��������˵
// �±����㷨��˼·�Ƚ���ѧ�����Ƕ�����ʲô�ģ����������ߣ�Ԥ����������O(nlogn)��m��ѯ��O(mlogn)���ص�Tarjan����
// �㷨������O(n+m)�ĸ��Ӷ��ڽ��LCA���⣬ȱ���Ǵ����鷳����ֻ�����ߡ�����һ������Ϊ�����ֵ㣬��һ�ֵ㣺�������һ���
// ���ĵ㣬�ڶ��ֵ㣺���ű�����û�л��ݵĵ㣬�����ֵ㣺û�п�ʼ�����ĵ㡣��Ϊ������ͼ������ֱ�Ӹ��������ˣ���ǰ����
// �����ĵ�Ĺ������Ⱦ��ǻ��ݹ�����Ǹ���...Ȼ��Ҫע��һ��ʼ�ľ���Ҳ��Ҫ��������������õ���ÿ���㵽���ڵ�ľ��룬
// Ȼ����������ľ�����ʵ�������ǵ��������ȵľ����ȥ2�����ظ����루�����ȵľ��룩... 

typedef pair<int, int > PII;
const int N = 500000 + 10, M = N * 2;
int sat[N];
int head[N], e[M], ex[M], idx = 0;
int res[N];
int bin[N];
struct unionFind {
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int xt = anc(x), yt = anc(y);
		if (xt != yt) bin[xt] = y;
	}
};
unionFind uf;
vector<PII > ques[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void tarjan(int ut) {
	sat[ut] = 1;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		// ע��ֻ�Ե�����㣬Ҳ����û�б������ĵ�������� 
		if (sat[vt]) continue;
		tarjan(vt);
		// �����ǰ��û�б���������ô���Ĺ������Ⱦ��ǻ���������·���ϵĵ� 
		bin[vt] = ut;
	}
	// ִ�����ж�ut��ѯ�ʣ���������ut��LCA 
	for (int i = 0; i < ques[ut].size(); i++) {
		int y = ques[ut][i].first, id = ques[ut][i].second;
		// ut��LCA���Ǿ���tarjan֮�󲢲鼯�к�ѯ�ʵ�y������ 
		res[id] = uf.anc(y); 
	}
	sat[ut] = 2;
}
int main() {
	// ���˳�ʼ��ͷ��� 
	memset(head, -1, sizeof head);
	int n, m, s, ut, vt, a, b;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n - 1; i ++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt), add(vt, ut);
	}
	// ������ѯ�ʴ��������ߴ��� 
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		ques[a].push_back(PII(b, i));
		ques[b].push_back(PII(a, i));   
	}
	// ��֪��Ϊʲô���в��Ե�������������˿�4sww... 
	tarjan(s);
	for (int i = 0; i < m; i++) printf("%d\n", res[i]);
	return 0;
}
