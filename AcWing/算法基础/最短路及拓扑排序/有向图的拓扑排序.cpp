#include <iostream>
#include <queue>
using namespace std;

// �������еĸ������һ�������޻�ͼ��һ������һ��������������1 -> 2 -> 3 , 2 -> 3, 1 -> 3�Ĺ�ϵ��
// ����Ϊ���ĵ���Զ������Ϊ�ص�ĵ��ǰ�档

// ��������Ĳ��裺����֪�����Ϊ0�ĵ�һ������㣬���Կ����ȴ����Ϊ0
// �ĵ㿪ʼBFS 

// ע�⣺����ͼû���������У����ڻ�������ͼҲû���������У���������һ����BFSʵ�֡�
// ���⣬�����޻�ͼ�ֳ�Ϊ����ͼ

// ����ж�һ������ͼ�Ƿ��л��� �޻�������ͼһ������һ�����Ϊ0�ĵ� 

const int N = 10010, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
// indg��¼ĳ�������ȣ�topu��¼�� 
int indg[N], topu[N];
int n, m;
void add(int k, int val) {
	e[idx] = val, ex[idx] = head[k], head[k] = idx++;
}
bool topusort() {
	// ͳ�����Ϊ0�ĵ��м���
	queue<int > que;
	int cnt = 0;
	// һ����n������ 
	for (int i = 1; i <= n; i++) {
		if (!indg[i]) {
			// �����Ϊ0������㣩�Ķ��㿪ʼBFS 
			que.push(i);
			// �������㣬��ô������������ǰ��� 
			topu[++cnt] = i; 
		}
	} 
	while (!que.empty()) {
		// ���ȴ����Ϊ0�ĵ㿪ʼ������ ���ҷ��������������ܵ��Ķ��� 
		int u = que.front();que.pop();
		for (int i = head[u]; i != -1; i = ex[i]) {
			int j = e[i];
			// ��ǰ��������Լ����������������ȼ���0�ˣ���˵����ǰ��ĵ��Ѿ��������ˣ���ô
			// �������Ϳ��Դ�����㿪ʼ������ 
			indg[j]--;
			if (!indg[j]) {
				// ����jҲ��ӵ����� 
				que.push(j);
				// ��¼�𰸣������Ϊ0�ĵ��ŵĸ�ǰ 
				topu[++cnt] = j; 
			}
		}
	}	
	// ������е㶼�����򣬾�˵�����ͼû�л��������Եõ��� 
	if (cnt == n) return true;
	// �����˵�����ͼ�л������ܵõ��� 
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + N + 10, -1);
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		// ��¼��v����� 
		indg[v]++;
		add(u, v);
	}
	if (topusort()) {
		for (int i = 1; i <= n; i++) cout << topu[i] << ' ';
	} else {
		cout << -1;
	}
	return 0;
} 

/*
����������
3 3
1 2
2 3
1 3

���������
1 2 3
*/
