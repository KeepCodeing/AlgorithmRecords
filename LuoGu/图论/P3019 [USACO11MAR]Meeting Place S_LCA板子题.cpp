#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

// 久违的LCA...这是个板子题w.. 

typedef pair<int, int > PII;
const int N = 1000 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
int st[N], bin[N], res[N];
vector<PII > ques[N];
int fd(int x) {
	if (x != bin[x]) bin[x] = fd(bin[x]);
	return bin[x];
}
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void tarjan(int ut) {
	st[ut] = 1;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (st[vt]) continue;
		tarjan(vt);
		bin[vt] = ut;
	}
	for (int i = 0; i < ques[ut].size(); i++) {
		int id = ques[ut][i].first, y = ques[ut][i].second;
		res[id] = fd(y);
	}
	st[ut] = 2;
}
int main() {
	memset(head, -1, sizeof head);
	for (int i = 0; i < N; i++) bin[i] = i;
	int n, m, ut, vt;
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &ut);
		add(ut, i), add(i, ut);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &ut, &vt);
		ques[ut].push_back(PII(i, vt));
		ques[vt].push_back(PII(i, ut));  
	}
	tarjan(1);
	for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
	return 0;
}
