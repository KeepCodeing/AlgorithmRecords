#include <iostream>
using namespace std;

// ���ȷ�������Ŀ����Ŀ����˼����˵ȥ������ڵ㣬Ȼ��Ա�
// ������ͨ�������ڵ�Ľڵ������𰸼������ٵĽڵ�����

// ��������Ҫ��¼�ľ���ÿ��ȥ��һ���㣬ʣ�µ���ͨ����
// �ڵ������ĵ㣬Ȼ��Աȳ���С���Ǹ�ֵ���� 

const int N = 100010, M = N * 2;

int head[N], e[M], ex[M], idx = 0;
bool visited[N];
void add(int k, int val) {
	e[idx] = val;
	ex[idx] = head[k];
	head[k] = idx;
	idx++;
}
int ans = N;
int n;
// ��¼cur�ж��ٸ����� 
int dfs(int cur) {
	visited[cur] = true;
	// tot��ʾ��ǰ����������res��ʾ������������ 
	int tot = 1, res = 0;
	for (int i = head[cur]; i != -1; i = ex[i]) {
		int j = e[i];
		if (!visited[j]) {
			int s = dfs(j);
			// �Ա������������������������� 
			res = max(s, res);
			// ͳ�Ƶ�ǰ�����ж��ٸ��ڵ� 
			tot += s;
		}
	}
	// �ö�������ȥ��ǰ�����Ľڵ������ɵõ����˵�ǰ�ڵ������
	// ��ͨͼ�Ľڵ���֮�� 
	res = max(res, n - tot);
	// ���´� 
	ans = min(ans, res);
	return tot;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	// һ����n - 1���� 
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		// ��Ŀ������������� 
		add(a, b), add(b, a);
	} 
	return 0;
}
/*
��������
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

�������
4
*/
