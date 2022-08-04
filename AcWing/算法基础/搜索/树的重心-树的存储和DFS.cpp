#include <iostream>
using namespace std;

// ���ǿ��԰�������һ�������ͼ��������û�л�������ͼ�����
// ���ǿ����ô洢ͼ�ķ�ʽ�洢����Ҳ�������ڽӱ�������������
// vector��Ҳ�����ֶ�ģ��һ��������

// N�Ƕ�������M�Ǳ��� 
const int N = 100010, M = N * 2;

// �������ͨ������Ψһ��ͬ�ĵط����ǿ��Դ��ڶ��ͷ��ÿ��ͷ
// �������ӵ������ͷ�ܵ���ĵ� 
int h[N], e[M], ex[M], idx = 0;
bool visited[N];

// ��ͷ�ڵ�k�����val�������͵�����һģһ��������ָ���˴��ĸ�
// ͷ���� 
void add(int k, int val) {
	e[idx] = val;
	ex[idx] = h[k];
	h[k] = idx;
	idx++;
} 

// DFS�͵����������ֻ࣬��������Ҫ�����е�ͷ��������
void dfs(int cur) {
	// ��Ƿ��ʹ��Ľڵ� 
	visited[cur] = true;
//	while (h != -1) {
//		cout << e[h];
//		h = ex[h];
//	}
	for (int i = h[cur]; i != -1; i = ex[i]) {
		int j = e[i];
		if (!visited[j]) {
			dfs(j);
		}
	}
} 

int main() {
	// ��ʼ��ͷָ�� 
	fill(h, h + N, -1);
	return 0;
}
