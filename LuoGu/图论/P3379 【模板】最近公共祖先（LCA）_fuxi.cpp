#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int > PII;
const int N = 500000 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
int st[N], res[N];
int bin[N];
int anc(int x) {
	if (x != bin[x]) bin[x] = anc(bin[x]);
	return bin[x];
}
vector<PII > ques[N];
void add(int ut, int vt) {
	// 建图建错了w，这里写成了ex[idx] = ut.... 
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
		int y = ques[ut][i].first, id = ques[ut][i].second;
		res[id] = anc(y);
	}
	st[ut] = 2;
}
int main() {
	memset(head, -1, sizeof head);
	for (int i = 0; i < N; i++) bin[i] = i;
	int n, m, ut, vt, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n - 1; i ++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ut, &vt);
		ques[ut].push_back(PII(vt, i));
		ques[vt].push_back(PII(ut, i)); 
	} 
	tarjan(s);
	for (int i = 0; i < m; i++) printf("%d\n", res[i]);
	return 0;
}
