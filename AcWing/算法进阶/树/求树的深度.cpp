#include <iostream>
using namespace std;

// �������Ҳ���ǵ�ǰ�ڵ�������Ĳ�Σ���ǰ�ڵ�Ĳ��һ�����ɸ��ڵ�Ĳ�ε��ƶ��� 

// ����BFS��д����BFS����������д����һ����ÿ���ڵ���Ӳ��Ӹ��ڵ���ƣ���һ������
// ȥ��¼��ȣ�Ȼ����pair֮���Ԫ���¼������ȣ���һ�־��������Ľ���ǰ�ڵ�������ӽڵ���ӣ��������¼... 

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int dep[M];
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int x) {
	for (int i = head[x]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vis[vt]) continue;
		dfs(vt);
		// �Ӹ��ڵ�Ĳ�����Ƶ���ǰ�ڵ�Ĳ�� 
		dep[vt] = dep[x] + 1;	
	}
}
int main() {
	
	return 0;
} 
