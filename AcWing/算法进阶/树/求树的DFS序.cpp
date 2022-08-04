#include <iostream>
using namespace std;

// DFS�򣺼��ڻ���ǰ��Ե�ǰ�ڵ�ķ���˳����м�¼��
// DFS����ص���:ÿ���ڵ�x�ı����������ǡ�ó������Ρ��������γ��ֵ�λ��ΪL[x]�� R[x]��
// ��ô������[L[x],R[x]]������xΪ����������DFS����ʹ�����ںܶ�������ص������У�����
// ͨ��DFS�������ͳ��ת��Ϊ�����ϵ�����ͳ�ơ�

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int s[M], now = 0;
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int x) {
	vis[x] = true;
	// �������ͨDFS������DFS������ڻ���ǰ�����һ�����������ǵ�ǰԪ���ǵڼ������ֵ�... 
	s[now++] = x;
	for (int i = head[x]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vis[vt]) continue;
		dfs(vt);
	}
	s[now++] = x;
}
int main() {
	
	return 0;
} 
