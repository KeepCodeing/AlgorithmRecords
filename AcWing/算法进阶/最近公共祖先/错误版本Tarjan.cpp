#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int > PII;
const int N = 500000 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
int st[N], res[N], bin[N];
int fd(int x) {
	if (x != bin[x]) bin[x] = fd(bin[x]);
	return bin[x];
}
vector<PII > ques[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void tarjan(int ut) {
	st[ut] = 1;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		// 错误的地方：这样写的意思可能和正解差不多，但是它只保证了向下搜的过程是正确的，没有保证连边的过程也是正确的... 
		// if (!st[vt]) tarjan(vt);
		if (st[vt]) continue;
		tarjan(vt);
		bin[vt] = ut;
	}
	for (int i = 0; i < ques[ut].size(); i++) {
		int y = ques[ut][i].second, id = ques[ut][i].first;
		res[id] = fd(y);
	}
	st[ut] = 2;
}
int main() {
	memset(head, -1, sizeof head);
	for (int i = 0; i < N; i++) bin[i] = i;
	int n, m, s, ut, vt;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &ut, &vt);
		ques[ut].push_back(PII(i, vt));
		ques[vt].push_back(PII(i, ut));  
	}
	tarjan(s);
	for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
	return 0;
}
