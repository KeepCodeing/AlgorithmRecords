#include <iostream>
using namespace std;

// ����ʱ�������ʵ����ÿ���ڵ���ֵ�˳��... 

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int dfn[M], now = 0;
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int x) {
	vis[x] = true;
	// ����ͨDFS�Ļ����ϼ�¼�ĵ�ǰ�ڵ��ǵڼ�����DFS�Ĺ����г��ֵ�... 
	dfn[x] = now++;
	for (int i = head[x]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vis[vt]) continue;
		dfs(vt);
	}
}
int main() {
	
	return 0;
} 
