#include <iostream>
#include <cstring>
using namespace std;

// ��Ϊ�򵥵�����������û���ǣ�����ֵ��ע���������ж�һ��ͼ�Ƿ����������ͼ��
// ��n-1�������ȶ�Ϊ0ʱ�����ͼ����������ͼ������Ϊ��ô��n-1���㣬��Ϊ���һ����
// ���һ��Ϊ1�����������е����һ��Ϊ1 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int rd[N];
int que[N];
// ע��������ӵĿӣ�qback�ĳ�ֵһ��Ҫ��-1��ʼ��Ȼ����ѭ�������Ĺ���
// ��һ��ʼд���ǳ�ֵΪ0������������֪��Ϊʲô������...��ǰ�����ƶ�Դ
// ���·BFS������������д... 
int qtop = 0, qback = -1;
bool topsort(int n) {
	for (int i = 1; i <= n; i++)
		if (!rd[i]) que[++qback] = i;
	while (qtop <= qback) {
		int ut = que[qtop++];
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			rd[vt]--;
			if (!rd[vt]) que[++qback] = vt;
		}
	}
	return qback == n - 1;
}
int main() {
	int n, m, ut, vt;
	memset(head, -1, sizeof head);
	cin >> n >> m;
	while (m--) {
		cin >> ut >> vt;
		add(ut, vt);
		rd[vt]++;
	}
	if (topsort(n)) 
		for (int i = 0; i < n; i++) cout << que[i] << ' ';
	return 0;
}
/*
3 3
1 2
2 3
1 3
*/
