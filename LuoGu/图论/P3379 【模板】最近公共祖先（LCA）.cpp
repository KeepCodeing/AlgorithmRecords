#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

// 迫真fuxi板子，感觉LCA问题都比较难的样子w（指没有模板题w），总之可能也是打完就不管了... 

typedef pair<int, int > PII;
const int N = 500000 + 10, M = N * 2;
int bin[N];
int res[N];
struct unionFind {
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
};
vector<PII > ques[N];
// 边开成N了WA了三个点... 
int head[N], e[M], ex[M], idx = 0;
int st[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
unionFind uf;
void tarjan(int ut) {
	st[ut] = 1;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (st[vt]) continue;
		tarjan(vt);
		bin[vt] = ut;
	}
	for (int i = 0; i < ques[ut].size(); i++) {
		int y = ques[ut][i].first, id = ques[ut][i].second;
		res[id] = uf.anc(y); 
	}
	st[ut] = 2;
}
int main() {
	memset(head, -1, sizeof head);
	int n, m, s, ut, vt, a, b;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n - 1; i ++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		ques[a].push_back(PII(b, i));
		ques[b].push_back(PII(a, i));  
	}
	tarjan(s);
	for (int i = 0; i < m; i++) printf("%d\n", res[i]);
	return 0;
}
